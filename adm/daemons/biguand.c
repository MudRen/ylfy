// �չ�ϵͳ By Wenwu On 2006.7.22

#include <ansi.h>

inherit F_DBASE;
inherit F_SAVE;

// ����
#define MAX_HEART_DOING 1
// ÿ�ε���������
#define MAX_CMD_DOING_OB 5
// ��������ָ��ִ�м��ʱ�� (ȡ���ֵ)
#define SPACE_TIME_SEC 2
#define BIGUN_DATA "/data/biguan/��������.o"
#define XIULIAN_POT_COST 0

// �չ����
mapping bg_users = ([]);
// biguan���
nosave object *biguan_obs = ({});
// �ȴ��ж���
nosave object *lixian_wait = ({});
// ������ɵĶ���
nosave object *lixian_finish = ({});
nosave int doing_flag = 0;

// �ڲ�ʹ�ú���
int load_all_users();
void xiulian_doing();
int del_breaking_user(object ob);
int breaking(object me);
// �ⲿʹ�ú���
int add_bg_user(object ob);
varargs int del_bg_user(object ob, int localcall);
int add_breaking_user(object ob);

string query_save_file()
{
	return BIGUN_DATA;
}

int clean_up()
{
	set_heart_beat(MAX_HEART_DOING);
	return 1;
}

void create()
{
	seteuid( ROOT_UID );
	set("channel_id", "��������");
	CHANNEL_D->do_channel( this_object(), "sys", "���������Ѿ�������\n"NOR);
	
	if ( file_size(BIGUN_DATA) > 0 )
		restore();

	load_all_users();
	/*remove_call_out("xiulian_doing");
	call_out("xiulian_doing", 3 + random(3));
	remove_call_out("breaking_doing");
	call_out("breaking_doing", 3);*/
	set_heart_beat(MAX_HEART_DOING);
}

int load_all_users()
{
	object user;
	string *bg_ob, room, xy_hy;
	int i;

	if ( !mapp(bg_users) )
	{
		bg_users = ([]);
		return 0;
	}

	if ( !sizeof(bg_users) ) return 0;

	if ( !arrayp(lixian_wait) ) lixian_wait = ({});

	CHANNEL_D->do_channel( this_object(), "sys", "��ʼ��ȡ������������С�\n"NOR);
	bg_ob = keys(bg_users);
	for ( i=0; i<sizeof(bg_ob); i++ )
	{
		if ( user = find_player(bg_ob[i]) )
		{
			if ( !user->query("lixian/biguan") )
			{
				del_bg_user(user);
			}
			else if ( objectp(user) ) 
				lixian_wait += ({ user });
			continue;
		}

		user = new(USER_OB);
		seteuid(bg_ob[i]);
		export_uid(user);
		
		user->set_name("���", ({ bg_ob[i] }));
		
		if ( !user->restore() )
		{
			del_bg_user(user);
			destruct(user);
			continue;
		}

		user->setup();

		if ( !user->query("lixian/biguan") )
		{
			del_bg_user(user);
			destruct(user);
			continue;
		}

		room = user->query("startroom");
		
		if ( user->move(room) )
			UPDATE_D->check_user(user, 3);
		else
		{
			del_bg_user(user);
			destruct(user);
			continue;
		}

		if ( !playerp(user) )
		{
			del_bg_user(user);
			destruct(user);
			continue;
		}

		if ( user->query("block") )
		{
			del_bg_user(user);
			destruct(user);
			continue;
		}
		// Ч���Ա��Ч��
		if ( stringp(xy_hy = user->query("xy_huiyuan")) )
		{
			if ( sscanf(xy_hy, "%*s��%*s��%*s��") )
				"/feature/vip"->del_vip(user, xy_hy);
			else
			{
				user->delete("xy_huiyuan");
				user->delete("xyhy_type");
			}
		}
		else
		{
			user->delete("xy_huiyuan");
			user->delete("xyhy_type");
		}
		// �ǻ�Ա�������������ʸ�
		if ( !user->query("xy_huiyuan") )
		{
			del_bg_user(user);
			destruct(user);
			continue;
		}
		// ��ѻ�Ա�������������ʸ�
		/*if ( !user->query("xyhy_type") )
		{
			del_bg_user(user);
			destruct(user);
			continue;
		}*/
		// ɱ�˷���������
		if ( user->query_condition("killer") )
		{
			del_bg_user(user);
			destruct(user);
			continue;
		}
		if ( objectp(user) ) lixian_wait += ({ user });
		user->delete("exp_jiacheng"); // �����ȡ��˫����������
	}
	
	save();
	CHANNEL_D->do_channel( this_object(), "sys", "��ȡ��ϡ�\n"NOR);
	return 1;
}

int add_bg_user(object ob)
{
	string id;

	if ( !objectp(ob) ) return 0;
	if ( !playerp(ob) ) return 0;
	if ( !ob->query("lixian/biguan") ) return 0;
	if ( ob->query("block") ) return 0;

	if ( !mapp(bg_users) )
		bg_users = ([]);

	id = ob->query("id");
	bg_users[id] = 1;
	save();
	if ( !arrayp(lixian_wait) ) lixian_wait = ({});
	if ( member_array(ob, lixian_wait) == -1 ) lixian_wait += ({ ob });
	set_heart_beat(MAX_HEART_DOING);
	return 1;
}

varargs int del_bg_user(object ob, int localcall)
{
	string id;

	if ( !mapp(bg_users) )
	{
		bg_users = ([]);
		return 0;
	}
	if ( !sizeof(bg_users) ) return 0;
	if ( !objectp(ob) ) return 0;
	if ( ob->query("lixian/biguan") )
	{
		ob->delete("lixian/biguan");
		ob->save();
	}

	id = ob->query("id");
	map_delete(bg_users, id);
	save();
	if ( !localcall && arrayp(lixian_wait) ) lixian_wait -= ({ ob });
	return 1;
}

void xiulian_doing()
{
	string cmd, xy_hy;
	int i, max, grant;

	if ( !arrayp(lixian_wait) ) lixian_wait = ({});
	if ( !arrayp(lixian_finish) ) lixian_finish = ({});
	lixian_wait += lixian_finish;
	lixian_finish = ({});
	lixian_wait -= ({ 0 });
	if ( !(max=sizeof(lixian_wait)) ) return;
	if ( max < MAX_CMD_DOING_OB ) grant = max;
	else grant = MAX_CMD_DOING_OB;

	for ( i=0; i<grant; i++ )
	{
		if ( i >= sizeof(lixian_wait) ) break;
		if ( !objectp(lixian_wait[i]) ) continue;
		else lixian_finish += ({ lixian_wait[i] });
		if ( !environment(lixian_wait[i]) )
		{
			del_bg_user(lixian_wait[i], 1);
			destruct(lixian_wait[i]);
			continue;
		}
		if ( interactive(lixian_wait[i]) )
		{
			del_bg_user(lixian_wait[i]);
			continue;
		}
		// ����������
		if ( !lixian_wait[i]->query("lixian/biguan") ) 
		{
			del_bg_user(lixian_wait[i], 1);
			lixian_wait[i]->save();
			destruct(lixian_wait[i]);
			continue;
		}
		// ��������
		if ( !query_heart_beat(lixian_wait[i]) )
		{
			del_bg_user(lixian_wait[i], 1);
			lixian_wait[i]->save();
			destruct(lixian_wait[i]);
			continue;
		}
		// �ؼ��
		if ( lixian_wait[i]->query("block") )
		{
			del_bg_user(lixian_wait[i], 1);
			lixian_wait[i]->save();
			destruct(lixian_wait[i]);
			continue;
		}
		// ɱ�˷�
		if ( lixian_wait[i]->query_condition("killer") )
		{
			del_bg_user(lixian_wait[i], 1);
			lixian_wait[i]->save();
			destruct(lixian_wait[i]);
			continue;
		}
		// Ч���Ա��Ч��
		if ( stringp(xy_hy = lixian_wait[i]->query("xy_huiyuan")) )
		{
			if ( sscanf(xy_hy, "%*s��%*s��%*s��") )
				"/feature/vip"->del_vip(lixian_wait[i], xy_hy);
			else
			{
				lixian_wait[i]->delete("xy_huiyuan");
				lixian_wait[i]->delete("xyhy_type");
			}
		}
		else
		{
			lixian_wait[i]->delete("xy_huiyuan");
			lixian_wait[i]->delete("xyhy_type");
		}
		// �ǻ�Ա�������������ʸ�
		if ( !lixian_wait[i]->query("xy_huiyuan") )
		{
			del_bg_user(lixian_wait[i], 1);
			lixian_wait[i]->save();
			destruct(lixian_wait[i]);
			continue;
		}
		// ��ѻ�Ա��Ҫ����Ǳ��
		if ( !lixian_wait[i]->query("xyhy_type") 
			&& lixian_wait[i]->query("potential") < XIULIAN_POT_COST )
		{
			del_bg_user(lixian_wait[i], 1);
			lixian_wait[i]->save();
			destruct(lixian_wait[i]);
			continue;
		}
		// ���߶೤ʱ���ֻ�����߹Ҷ���ʱ�䣬������
		if ( lixian_wait[i]->query("biguan_is_online") < 1 
			/*&& lixian_wait[i]->query("xyhy_type") != 2*/ )//����޷����ߵ�����
		{
			del_bg_user(lixian_wait[i], 1);
			lixian_wait[i]->save();
			destruct(lixian_wait[i]);
			continue;
		}
		// ��busy��
		if ( lixian_wait[i]->is_busy() ) continue;
		// �޷����
		if ( lixian_wait[i]->query_temp("block_msg") ) continue;
		if ( !living(lixian_wait[i]) ) continue;
		// ��������δִ�����ָ��
		if ( stringp(cmd=lixian_wait[i]->query_temp("chufa_buffer")) )
		{
			lixian_wait[i]->do_xyzx_chufa(cmd);
			continue;
		}
		// ����д���ִ�д���
		if ( lixian_wait[i]->query_temp("xyzx_sys_chufa") )
		{
			if ( !stringp(cmd = lixian_wait[i]->query_temp("xyzx_sys_chufa")) )
			{
				lixian_wait[i]->delete_temp("xyzx_sys_chufa");
				continue;
			}

			lixian_wait[i]->delete_temp("xyzx_sys_chufa");
			lixian_wait[i]->do_xyzx_chufa(cmd);
			continue;
		}
		// ִ�мƻ�
		lixian_wait[i]->do_xyzx_xiulian();
		// ��ѻ�Ա����Ǳ��
		if ( lixian_wait[i]->query("xyhy_type")!=2 )
			lixian_wait[i]->add("potential", -XIULIAN_POT_COST);
	}

	lixian_wait -= lixian_finish;
	lixian_wait -= ({ 0 });
	/*remove_call_out("xiulian_doing");
	call_out("xiulian_doing", random(SPACE_TIME_SEC));*/
	return;
}

int add_breaking_user(object ob)
{
	if ( !interactive(ob) ) return 0;
	if ( ob->query("breakup") ) return 0;
	if ( ob->query_temp("breakuping") ) return 0;

	if ( !pointerp(biguan_obs) )
		biguan_obs = ({});
	
	biguan_obs += ({ ob });
	ob->set_temp("breakuping", 1);
	set_heart_beat(MAX_HEART_DOING);
	return 1;
}

int del_breaking_user(object ob)
{
	if ( !pointerp(biguan_obs) )
	{
		biguan_obs = ({});
		return 0;
	}

	if ( !sizeof(biguan_obs) ) return 0;
	if ( !objectp(ob) ) return 0;
	
	biguan_obs -= ({ ob });
	return 1;
}

void breaking_doing()
{
	int i;

	if ( !arrayp(biguan_obs) )
	{
		biguan_obs = ({});
		/*remove_call_out("breaking_doing");
		call_out("breaking_doing", 3);*/
		return;
	}

	if ( !sizeof(biguan_obs) )
	{
		/*remove_call_out("breaking_doing");
		call_out("breaking_doing", 3);*/
		return;
	}

	for ( i = 0; i < sizeof(biguan_obs); i++ )
	{
		if ( !objectp(biguan_obs[i]) ) continue;
		if ( !biguan_obs[i]->query_temp("breakuping") ) continue;
		if ( biguan_obs[i]->query("breakup") ) continue;
		breaking(biguan_obs[i]);
		
	}

	/*remove_call_out("breaking_doing");
	call_out("breaking_doing", 3);*/
	return;
}

int breaking(object me)
{
	string msg;
	
	if ( !interactive(me) )
	{
		me->delete_temp("breakuping");	
		del_breaking_user(me);
		return 0;
	}
	if ( me->query("block") )
	{
		me->delete_temp("breakuping");	
		del_breaking_user(me);
		return 0;
	}
	if ( me->is_ghost() )
	{
		me->delete_temp("breakuping");	
		del_breaking_user(me);
		return 0;
	}
	if ( me->query("potential") < 15 )               	
	{
		tell_object(me, "���Ǳ�ܲ����ˡ�\n");	
		me->delete_temp("breakuping");	
		me->set("potential",0);
		del_breaking_user(me);
		message_vision("$N����˫Ŀ����������һ������վ��������\n", me);
		message("channel:chat", HIY"������ˮ�¡�"+HIM"��˵"+me->query("name")+HIM"�չؽ���,�ƺ�û��̫��Ľ�չ��\n"NOR,users() );
		return 0;
	}
	if ( me->query_temp("netdead") || me->query("lixian/biguan") )               	
	{
		me->delete_temp("breakuping");	
		//me->set("potential",0);
		del_breaking_user(me);
		message_vision("$N����˫Ŀ����������һ������վ��������\n", me);
		message("channel:chat", HIY"������ˮ�¡�"+HIM"��˵"+me->query("name")+HIM"�չ���;ͻȻ����,�ƺ�û��̫��Ľ�չ��\n"NOR,users() );
		return 0;
	}

	me->add("potential",-5);	

	if (random(500000) < me->query("con") && !me->query("breakup"))
	{
		message_vision(HIW "ֻ��$N" HIW "ͷ�ϰ������ڡ�������ͬ���������У������Ѿ����������۶���������Ԫ��������á����˽���Ľ�Ҫ��ͷ��\n" NOR, me);
		tell_object(me, HIR "����������ڵ���ԴԴ���������ϳ�����Ѩ�����������ѵ�����������������\n" NOR);
		message_vision(HIC "ͻȻ$N" HIC "���һ����һ���������˶�Ȼɢ�����������ܿ�����ʱ������ȡ�\n" NOR, me);
		tell_object(me, HIG "���ʱ���û���һ�����ɣ�һ������֮����Ȼ��������һƬ����������û��˿�����ͣ���̩֮����\n" NOR);
		me->delete_temp("breakuping");
		me->set("breakup", 1);
		message("channel:chat", HIY"������ˮ�¡�"+HIM"��˵"+me->query("name")+HIM"�����չؿ���,���ڴ�ͨ���ζ�����,���ӵ������ϵ���ѧ���磡\n"NOR,users() );	
		me->add("max_jingli",me->query("max_jingli")/10);             	
		me->add("max_neili",me->query("max_neili")/10);
		me->set_skill("force",me->query_skill("force",1)+100);
		del_breaking_user(me);
		return 1;
	}

	switch ( random(5) ) 	
	{
		case 0:
				msg = "��ĬĬ��ת������������Щ�о���\n";    	
				break;
		case 1:
				msg = "�㽫�����˳�������Ϲ��������衢͸ʮ����¥���鲼��������Ȼ���ջص��\n";  	
				break;
		case 2:
				msg = "�㽫�����˾���Ѩ������֫���࣬Ȼ���ֻ��յ��\n"; 	
				break;
		case 3:
				msg = "���ڵ����в��ϻ���������ֻ���û������ȡ�\n";
				break;
		default:
				msg = "�㻺���������ɣ���������ˮ¶����Ϊ���á�\n";
	}
	
	me->start_busy(15);
	tell_object(me, msg);
	return 1;
}

object *query_all_lixian_wait()
{
	return lixian_wait;
}

object *query_all_lixian_finish()
{
	return lixian_finish;
}

void remove()
{
	/*remove_call_out("xiulian_doing");
	remove_call_out("breaking_doing");*/
}

private void heart_beat()
{
	doing_flag++;

	if ( !(doing_flag%1) ) xiulian_doing();
	if ( !(doing_flag%3) ) breaking_doing();
}
