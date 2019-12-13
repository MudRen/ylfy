// ----/cmds/usr/quit.c ----
//����tomudЭ��quit�б�(���ߵ����ҡ����who�б�ĸ���)
#include <dbase.h>
#include <command.h>
#include <ansi.h>
#include <liebiao.h>
// #define HTTP_D "/adm/daemons/httpd"

inherit F_DBASE;
inherit F_CLEAN_UP;

int do_rmdata(object ob, object me);

void create() 
{
	seteuid(getuid());
	set("channel_id", "����ָ��");
}

string online_time(int t)
{
	int h, m, s;
	
	s = t % 60;
	t /= 60;
	m = t % 60;
	t /= 60;
	h = t ;
        
        return sprintf("��������ʱ��%d:%d",m,s);
}

int main(object me, object target, string arg)	
{
	int exp,online;
	object link_ob;
	string ip_num,msg;
	
	if ( !objectp(me) ) return 0;
	// ������������²����뿪��Ϸ
	if( LOGIN_D->get_madlock() == 1 )  return notify_fail(HIY"ʱ���ѷ�գ��κ��˶��޷��뿪������硣\n"NOR);
	if ( !wizardp(me) )
	{
		if ( me->query_condition("killer") ) 
		{
			set_heart_beat(1);
			return notify_fail(HIR"��Ŀǰ�����ٸ�����ͨ������Ǳ��ô��\n"NOR);
		}
		/*if ( (me->query_temp("pker_starttime")+3600*me->query_temp("pker_time")) > me->query("mud_age") )
		{
			set_heart_beat(1);
			return notify_fail("���ɱ���ˣ���ʱ���޷��뿪��Ϸ��\n");
		}*/
	}
	
	if( interactive(me) )
	{
		if ( me->is_busy() )
		{
			if( !me->query_temp("suicide") )
				return notify_fail("��һ������δ��ɣ�\n");
			else
			{
				CHANNEL_D->do_channel(this_object(),"rumor",HIG""+me->query("name") + "������ͨ�ˣ�������ɱ�ˡ� :)");
				tell_object( me,MAG "\n\n�����Ҫ������ɱ��̫���ˣ����´������ɣ�\n\n\n" NOR);
			}
		}
		
		if ( me->is_fighting() ) return notify_fail("ս����ֻ�����ܣ������˳���Ϸ��\n");
	}
	
	// We might be called on a link_dead player, so check this.
	link_ob = me->query_temp("link_ob");
	
	if( link_ob )
	{
		// Are we possessing in others body ?
		if( link_ob->is_character() )
		{
			write("��Ļ��ǻص�" + link_ob->name(1) + "�����ϡ�\n");
			exec(link_ob, me);
			link_ob->setup();
			return 1;
		}
		
		if( !living(me) )
		{
			write("ʲ�᣿\n");
			return 0;
		}
		
		if( !wizardp(me) )
		{
			foreach (object ob in all_inventory(me))
			{
				if ( ob && !ob->query_autoload() && !ob->query("xyzx_save_item") )
					DROP_CMD->do_drop(me, ob, 1);
			}
			// ע�᲻����Сʱ�˳���Ϸɾ���ʺ��Լ���ϵͳ����
			if ( time() - me->query("birthday",1) < 1800 )
			{
				// �����˳���Ϸ
				if ( interactive(me) )
				{
					write(HIY"����ע���ʺŲ�����Сʱ������������뿪��ϷΪ�˼���ϵͳ������ɾ�������ʺ�"HIW"["HIR"Y"HIY"/"HIG"N"HIW"]"HIY"��\n"NOR);
					input_to("rmdata_exit", 1, link_ob, me);
					return 1;
				}
			}
			if ( !interactive(me) && time() - me->query("birthday",1) < 3600 )
			{ // ע�᲻��һСʱ������ߵ������˳���Ϸɾ���ʺ�
				do_rmdata(link_ob, me);
				return 1;
			}
		}
		
		online=time()-link_ob->query("online_time");
		link_ob->set("last_on", time());
		if ( query_ip_name(me) )
			link_ob->set("last_from", query_ip_name(me));
		else
			link_ob->set("last_from", me->query_temp("last_ip_name"));
		exp=me->query("combat_exp")-link_ob->query("combat_exp");
		link_ob->set("combat_exp", me->query("combat_exp"));
		
		if ( !(wizardp(me) && me->query("env/invisibility") == 10) )
			link_ob->save();
		
		destruct(link_ob);
	}
	else
	{
		link_ob = new(LOGIN_OB);
		link_ob->set("id", me->query("id"));

		if( !link_ob->restore() )
		{
			destruct(link_ob);
        	return 0;
		}

		// ע�᲻����Сʱ�˳���Ϸɾ���ʺ��Լ���ϵͳ����
		if ( !wizardp(me) )
		{
			if ( time() - me->query("birthday",1) < 1800 )
			{
				// �����˳���Ϸ
				if ( interactive(me) )
				{
					write(HIY"����ע���ʺŲ�����Сʱ������������뿪��ϷΪ�˼���ϵͳ������ɾ�������ʺ�"HIW"["HIR"Y"HIY"/"HIG"N"HIW"]"HIY"��\n"NOR);
					input_to("rmdata_exit", 1, link_ob, me);
					return 1;
				}
			}
			if ( !interactive(me) && time() - me->query("birthday",1) < 3600 )
			{ // ע�᲻��һСʱ������ߵ������˳���Ϸɾ���ʺ�
				do_rmdata(link_ob, me);
				return 1;
			}

			if ( query_ip_name(me) ) // ��¼IP
				link_ob->set("last_from", query_ip_name(me));
			else // ����Ŀǰ�� IP ����¼��ε�¼ʱ�� IP
				link_ob->set("last_from", me->query_temp("last_ip_name"));

			link_ob->save();
		}

		destruct(link_ob);
	}

	//if ( in_input(me) ) /*remove_input_to(me)*/;
	
	write("��ӭ�´�������\n");
	//message("system", me->query("name") + "�뿪��Ϸ��\n", environment(me), me);
	
	ip_num = query_ip_number(me);
	
	if (!ip_num)
		msg=me->query("name")+"("+me->query("id")+")"+HIR+"����ʱ�����"+HIW+",�Զ��뿪��Ϸ�ˡ�";
	else
		msg=me->query("name")+"("+me->query("id")+")("+query_ip_number(me)+")�뿪��Ϸ�ˡ�";
	
	msg+=online_time(online);
	
	if (exp!=0)
		msg+=sprintf("����������"+HIR+"%d"+NOR+WHT+"�㡣",exp);
	else
		msg+="��";
	
	CHANNEL_D->do_channel(this_object(), "sys",msg);

    reclaim_objects();
	
	if ( !wizardp(me) )
	{
		if ( sscanf(base_name(environment(me)), "/u/%*s") 
			|| sscanf(base_name(environment(me)), "/d/automap/%*s") 
			|| sscanf(base_name(environment(me)), "/d/migong/%*s") 
			|| environment(me)->query("no_login")
			|| clonep(environment(me))
			|| virtualp(environment(me)) )
		{
			me->delete("startroom");
		}
		else
			me->set("startroom", base_name(environment(me)));

		me->set("quit_time",time());
	}
	else me->set("startroom", base_name(environment(me)));
	// �������������
	//me->delete_learned();
	//me->delete("exp_jiacheng");
	me->save();
	
	if(!me->query("xieyi/zmud"))
	{
		tell_object(me,CLEAN2);
		tell_object(me,CLEAN0);
		tell_object(me,CLEAN1);
                /*
		if ( !me->query("env/myhp_show") )
			tell_object(me, ALERT("��ʹ�õĵ�½��(�ͻ���)�汾���ͣ��뵽��̳�������°汾�Ŀͻ��ˡ�$$$$"
		"�°汾�ͻ��������Ĺ��ܾ������£�$$"
		"�塢������˫�������Ʒ�����ͼ��ɴ���Ʒ���Կ�(��������Ϸ����Ա����ֱ��ͨ�������޸���Ʒ����)$$"
		"�桢�������������ť������ֱ�Ӵ򿪻����������ÿ������и�����������;����ϸ˵����$$"
		"�硢���Ӿ�����Ѫ��������������ʳ���ˮ����״̬��������������Ҳ���þ���������hp���鿴״̬�ˡ�$$"
		"�衢�����ͼ��ť���Դ򿪵�ͼ�Ի���������ͨ����ť����ֱ��ȥһЩ��ȥ�ĵط�����Ҳ���Բ鿴��ǰ��ͼ��$$"
		"�顢��������걨��ť�����ӷ��Ϳ������ͨ��������㷢�ֵ�������ߺõĽ���ֱ�ӷ��͸���Ϸ����Ա��$$"
		"�ꡢ�޸��˿ͻ�����ע��Ϳ���ʹ��ȫ���Ĺ��ܡ�$$"
		"�롢������ԭ���󴰿����ֹ��໻�е����⣬���ڿ�����ȫ������������������Ϣ��ʽ������ʾ��(���۶��ˣ��Ǻ�)$$"
		"�졢�޸���ԭ����who�б��Լ���ͼ��鿴QQ����û��Ӧ�����⣬���ڵ��Լ���ͼ��鿴QQ���ϻ��QQ�������ÿ�$$"
		"�����������촰�ڲ����Զ����������⡣�޸�who�б��ڿͻ��˴���ˢ�¡�$$"
		"������˵��������ͼ����ʱ�ᵼ�´��ں�ͼ��ͬʱ��ʧ�����⡣(��ʱ����������ֻ����������������������̡���)"));
               */
	}
	
	// �������ݵ����ݿ������
	// DATAD->send_database(me);
	destruct(me);
    //HTTP_D->make_who();
    return 1;
}

int rmdata_exit(string arg, object ob, object me)
{
	if ( strsrch(arg,"Y") != -1 || strsrch(arg,"y") != -1 )
		do_rmdata(ob, me);
	else
		write(HIG"\n���������»ص���Ϸ�ˡ�\n"NOR);

	return 1;
}

int do_rmdata(object ob, object me)
{
	if ( !objectp(ob)) return 0;
	if ( !objectp(me)) return 0;

	CHANNEL_D->do_channel(this_object(), "sys", HBRED+HIY+me->query("name")+"("+me->query("id")+")"+HIW"ɾ���뿪��Ϸ From "+query_ip_number(me)+"\n"NOR);
	log_file("static/quit_rm",sprintf("%s ɾ���뿪��Ϸ On %s\n",me->name(1)+"("+me->query("id")+")", CHINESE_D->chinese_time(7,ctime(time()))) );
	rm( ob->query_save_file() + __SAVE_EXTENSION__ );
	rm( me->query_save_file() + __SAVE_EXTENSION__ );	
	write(HIR"\n�������뿪��Ϸ�������ʺ��ѱ�ɾ����\n"NOR);
	message("system", me->query("name") + "�뿪��Ϸ��\n", environment(me), me);
	delete_item_data(me);
	me->set_temp("no_auto_items", 1);
	me->set_temp("no_end_save", 1);
	destruct(ob);
	destruct(me);
	return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : quit
��������ʱ�뿪ʱ, �����ô�һָ�
HELP
    );
    return 1;
}