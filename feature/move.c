// move.c by Wenwu On 2003.06.21

#include <dbase.h>
#include <room.h>
#include <liebiao.h>

int room_outs_tomud(object me, object ob);

nosave int weight = 0;
nosave int encumb = 0, max_encumb = 0;
// ��ѯЯ����Ʒ������
nomask int query_encumbrance()
{
	return encumb;
}
// ����
nomask int over_encumbranced()
{
	return encumb > max_encumb;
}
//���ذٷֱ�
nomask int than_encumbranced()
{
	int than_encumb;
	
	than_encumb = encumb * 100 / max_encumb;
	if ( than_encumb < 0 ) than_encumb = 0;
	if ( than_encumb > 100 ) than_encumb = 100;

	return than_encumb;
}
// ��ѯ��Я����Ʒ���������
nomask int query_max_encumbrance()
{
	return max_encumb;
}
// ��¼��Я����Ʒ���������
nomask void set_max_encumbrance(int e)
{
	max_encumb = e;
}
// ��������
nomask void add_encumbrance(int w)
{
	encumb += w;
	
	if( encumb < 0 ){
		log_file("move.bug", sprintf("%O encumbrance underflow.\n", this_object()));
	}
	if( encumb > max_encumb )
		this_object()->over_encumbrance();
	
	if( environment() )
		environment()->add_encumbrance(w);
}

void over_encumbrance()
{
	if( !interactive(this_object()) )
		return;
	
	tell_object(this_object(), "��ĸ��ɹ����ˣ�\n");
}

nomask int query_weight()
{
	return weight;
}
nomask void set_weight(int w)
{
	if( !environment() )
	{
		weight = w;
		return;
	}
	
	if( w!=weight )
		environment()->add_encumbrance( w - weight );
	
	weight = w;
}

// This is the "current" weight of an object, which is used on weight
// checking in move().
nomask int weight()
{
	return weight + encumb;
}

varargs int move(mixed dest, int silently)
{
	object me, ob, env, obj;
	mapping exits, my, is_bind;
	string str, *dirs;
	int i;

	me = this_object();
	
	//If we are equipped, unequip first.
	if( query("equipped") && !this_object()->unequip() )
        return notify_fail("��û�а취ȡ������������\n");
	
	//Find the destination ob for moving.
	if( objectp(dest) )
		ob = dest;
	else if( stringp(dest) )
	{
		//call_other(dest, "???");
        ob = load_object(dest);
		if(!ob)
			return notify_fail("move: destination unavailable.\n");
    }
	else
		return notify_fail(sprintf("move: invalid destination %O.\n", dest));

	// �󶨵���Ʒ�޷�����
	if ( environment(this_object()) 
		&& mapp(is_bind = this_object()->query("bind_master_level")) 
		&& !is_bind[ob->query("id")])
		return notify_fail("�󶨵���Ʒ�޷����ס�\n");
    
	//Check if the destination ob can hold this object.
	//Beforce checking it, we check if the destination is environment of
	//this_object() (or environment of its environment). If it is, then
	//this could be like get something from a bag carried by the player.
	//Since the player can carry the bag, we assume he can carry the this
	//object in the bag and encumbrance checking is unessessary.
	
	env = this_object();
	
	while ( env = environment(env) )
	{
		if( env==ob )
			break;
	}

	if( !env )
	{
		// ���ȼ�鸺�أ�Ŀ��OBJ�޷������ɵ���ʱ�Ĵ���
		if( (int)ob->query_encumbrance() + weight() > (int)ob->query_max_encumbrance() )
		{
			// Ŀ��OBJ�л��������ƶ�������
			if ( environment(ob) && !wizardp(ob) )
			{
				tell_room(environment(ob), "����"+this_object()->name()+"����"+ob->name()+"����ʵ����̫���ˣ�ֻ��������һ�ԡ�\n");
				ob = environment(ob);
			} else if( ob == this_player() ) // ��Ŀ�������ʾ��Ϣ
				return notify_fail( this_object()->name() + "�������̫���ˡ�\n");
			else
				return notify_fail( this_object()->name() + "��" + ob->name() + "����̫���ˡ�\n");
		} else if ( playerp(ob) && sizeof(all_inventory(ob)) > 50 ) // ���Ŀ�����OBJ����Я�������Ŀ�Ƿ񳬹�50
		{
			// ����������������ڣ����ƶ�������
			if ( environment(ob) && !wizardp(ob) )
			{
				tell_room(environment(ob), "����"+this_object()->name()+"����"+ob->name()+"����ʵ����̫���ˣ�ֻ��������һ�ԡ�\n");
				ob = environment(ob);
			}
			else if( ob == this_player() )
			{
				tell_object(ob, "�����ϵĶ���̫���ˣ�\n");
				return notify_fail( this_object()->name() + "�������̫���ˡ�\n");
			}
			else
				return notify_fail( this_object()->name() + "��" + ob->name() + "����̫���ˡ�\n");
		}
	}
	
	// Move the object and update encumbrance
	if ( env = environment() )
	{
		//_________________________���Ƶͼ���ʦ���趫��______________________
		if ( playerp(env) )
		{ 
			if ( ob->is_character() )
			{ // ����� ---> ��������
				if ( wizardp(env) && wiz_level(env) < 9 && !wizardp(ob) )
				{ // ����ʦ������ʦ�ȼ� < 9��Ҳ���� admin Ȩ�����µ�
					if ( me->query("is_wiz_level") )
					{
						tell_object(env, "������ʦ�������غ���ʦ����Ҫ���⽻�׶�����\n");
						return 0;
					}
				}
			}
		}
		//________________________________END________________________________
		// ��Ҵ���̨�������ս���˺�����
		if ( playerp(me) )
		{
			if ( base_name(env) == "/d/wizard/fightroom3" 
				|| base_name(env) == "/d/wizard/fightroom2" )
			{
				me->delete_temp("last_unconcious_from");
				me->delete_temp("last_damage_from");
			}
		}
		env->add_encumbrance( - weight());
	}
	
	//Tomud�б�ɾ��
	if ( me && ob )
	{
		//��env���¸�ֵ������������ڸó�ʽ����ָ��Ϊthis_object()ԭ�����ڵĻ���
		//env = environment(this_object());
		
		if ( env )
		{
			//���ˣ�ֻ����Ŀǰ�Ŀɻ������
			if(interactive(env)) 
			{
				if(!env->query("xieyi/zmud"))
				{
					//ɾ����Ʒ������б�ͼ��
					tell_object(env,REM1(this_object()));
				}
			}
			else if(!env->is_character())
			{
				object *temp;
				//ֻ����ͬ�����µ������������ԭ����users()Ч�ʸ߶���
				temp=all_inventory(env);
				for(i=0;i<sizeof(temp);i++)
				{
					if (temp[i] == this_object())
						continue;

					if(environment(temp[i]) == env)
					{
						if(!temp[i]->query("xieyi/zmud"))
						{
							if (interactive(temp[i]))
							tell_object(temp[i],REM0(this_object()));
						}
					}
				}
			}
		}
	}
	
	// RPGϵͳ���⴦��
	//if ( !clonep(ob) || virtualp(ob) ) ob->xyzx_system_clean_up();
	// Add by Wenwu
	if ( !this_object() ) return 0;
	// ��Ʒ��ȡ��
	if ( this_object()->query("xyzx_sys/bind_type") == 2 && playerp(ob) )
	{
		this_object()->set("bind_master_level/"+ob->query("id"), 2);
		this_object()->set("owner_id", 1);
		this_object()->set("xyzx_save_item", 1);
	}

	move_object(ob);
	
	// ��̬��Ʒ��ʱ����
	// ----------------------------------------------
	if ( objectp(env) )
	{
		if ( this_object()->query("xyzx_save_item") && this_object()->query("owner_id") )
		{
			if ( playerp(env) ) env->save_item_call(); // ��̬��Ʒ����������ƿ�ʱ�������ݿ�
			if ( playerp(ob) ) ob->save_item_call(); // ��̬��Ʒ�ƶ����������ʱ�������ݿ�
		}

		if ( playerp(this_object()) )
		{
			if ( base_name(ob) == VOID_USER )
			{
				this_object()->set_temp("move_temp_room", base_name(env));
			}
		}
		else if ( this_object()->is_character() )
			this_object()->delete("env/no_combat_msg");
	}
	else
	{
		if ( playerp(ob) )
		{
			if ( this_object()->query("xyzx_save_item") && this_object()->query("owner_id") )
				ob->save_item_call(); // ��̬��Ʒ�ƶ����������ʱ�������ݿ�
		}
	}
	// ----------------------------------------------

	//Tomud�б�ͼ������
	if (this_object() && ob)
	{
		//ob->add_encumbrance(weight());
		//���ƶ����������ʱ���������Ʒ���������б�ͼ��
		if(interactive(ob))
		{
			if(!ob->query("xieyi/zmud"))
			{
				//��ʦ����������˿����Լ����԰�����ȼ�����Ϊ10���������б���������ʦ������Ч����
				if(!(wizardp(this_object()) && this_object()->query("env/invisibility") == 10))
					//�������Ʒ������һ���б�ͼ��
					tell_object(ob,ADD1(this_object()) );
			}
		}
		//���ƶ���һ������ʱ����������������������ҵ�������������б�ͼ��
		else if(!ob->is_character())
		{
			object *temp;
			//���ӹ��ˣ�ָ�������б��Ŀ�����ִ��Ч��
			temp=all_inventory(ob);
			for(i=0;i<sizeof(temp);i++)
			{
				if (temp[i] == this_object())
					continue;

				if ( sizeof(temp) > 50 )
				{
					if ( !temp[i]->is_character() && temp[i]->query("startroom") != base_name(this_object()) )
						continue;
				}

				if(environment(temp[i]) == ob)
				{
					if(!temp[i]->query("xieyi/zmud"))
					{
						if(!(wizardp(this_object()) && this_object()->query("env/invisibility") == 10))
						{
							//���ˣ�ֻ����Ŀǰ�Ŀɻ������
							if (interactive(temp[i]))
								tell_object(temp[i],ADD0(this_object()));
						}
					}
				}
			}
		}
	}
    
	ob->add_encumbrance(weight());
    
	//If we are players, try look where we are.
    if( interactive(this_object()) && living(this_object()) && objectp(env=environment()) && !silently )
	{
		ob=this_object();
		
		if(!intp(query("env/brief")))
			set("env/brief",0);
		
		if((int)query("env/brief") == 1 )
		{
			room_outs_tomud(ob, environment());
			tell_object(ob, HIW+environment()->query("short") +NOR+ "\n");
		}
		else if ( (int)query("env/brief") == 2 )
		{
			str=NOR+"\n";
			exits = environment()->query("exits");
			
			if( !sizeof(exits) )
				str += "    ����û���κ����Եĳ�·��\n";
			else
			{
				dirs = keys(exits);
				for(i=0; i<sizeof(dirs); i++)
				if( (int)environment()->query_door(dirs[i], "status") & DOOR_CLOSED )
					dirs[i] = 0;
				dirs -= ({ 0 });
				
				if( !sizeof(dirs))
					str += "    ����û���κ����Եĳ�·��\n";
				else if( sizeof(dirs)==1 )
					str += "    ����Ψһ�ĳ����� " + BOLD + dirs[0] + NOR + "��\n";
				else
					str += sprintf("    �������Եĳ����� " + BOLD + "%s" + NOR + " �� " + BOLD + "%s" + NOR + "��\n",implode(dirs[0..sizeof(dirs)-2], "��"), dirs[sizeof(dirs)-1]);
			}
			
			if ( (int)query("env/brief")==2 )
			{
				tell_object(ob, HIW+environment()->query("short") +str+NOR+ "\n");
			}
			else
			{
				obj=first_inventory(env);
				while(obj)
				{
					reset_eval_cost();
					
					if (obj==this_object() || !this_object()->visible(obj))
					{
						obj = next_inventory(obj);
						continue;
					}
					
					if (obj->query("money_id") || !obj->query("unit") || obj->is_character())
					{
						str+=sprintf("    %s\n",obj->short());
						obj = next_inventory(obj);
						continue;
					}
					
					if (!mapp(my))
						my=([obj->query("unit")+obj->short():1]);
					else
					{
						i=my[obj->query("unit")+obj->short()];
						my[obj->query("unit")+obj->short()]=i+1;
					}
					obj = next_inventory(obj);
				}
				if (mapp(my))
				{
					dirs=keys(my);
					for (i=0;i<sizeof(my);i++)
						str+=sprintf("    %s%s\n",my[dirs[i]]==1?"":CHINESE_D->chinese_number(my[dirs[i]]),my[dirs[i]]==1?dirs[i][2..]:dirs[i]);
				}
				
				tell_object(ob, HIW+environment()->query("short") +str+NOR+ "\n");
			}
			
			room_outs_tomud(ob, environment());
		}
		else if ( (int)query("env/brief") == 3 )
		{
			command("maphere -min");
			room_outs_tomud(ob, environment());
		}
		else
		{
			//command("look");
			"/cmds/std/look"->main(ob);
			room_outs_tomud(ob, environment());   
		}
	}
        
	return 1;
}

void remove(string euid)
{
	object default_ob;
	
	// ���д˺�ʽ�Ĳ��� SIMUL_EFUN_OB 
	if( !previous_object() || base_name(previous_object()) != SIMUL_EFUN_OB )
		error("move: remove() can only be called by destruct() simul efun.\n");
	// û�� this_object() 
	if ( !objectp(this_object()) )
		return;
	// û�� default_ob ����
	if( objectp(default_ob = this_object()->query_default_object()) )
		default_ob->add("no_clean_up", -1);	
	// this_object() �Ǳ�װ���ŵ�װ������������װ��
	if( this_object()->query("equipped"))
	{
		if( !this_object()->unequip() )
			log_file("destruct", sprintf("Failed to unequip %s when destructed.\n",file_name(this_object())));
	}
    
	// We only care about our own weight here, since remove() is called once
	// on each destruct(), so our inventory (encumbrance) will be counted as
	// well.
	
	// �л���
	if( environment() )
	{
		// ��ȥ this_object() ������
		environment()->add_encumbrance( - weight );
		// ����ұ��浵��
		/*if ( playerp(this_object()) )
			this_object()->save();*/
	}
	return;
}

int move_or_destruct( object dest )
{
	if ( playerp(this_object()) )
	{	
		tell_object(this_object(), "һ��ʱ�յ�Ť�����㴫�͵���һ���ط�....\n");
		move(VOID_USER);

		if ( stringp(this_object()->query_temp("move_temp_room")) )
		{
			this_object()->apply_condition("move", 1);
		}
	}
}

int room_outs_tomud(object me, object ob)
{
	mapping exits;
	string *outs, msg;
	object *inv;
	int i;

	if ( me->query("xieyi/zmud") )
		return 0;

	msg = "" + CLEAN0;
	inv = all_inventory(ob);
	for ( i = 0; i < sizeof(inv); i++ )
	{		
		if ( !inv[i]->query_temp("check_only") && inv[i] != me && me->visible(inv[i]) )
		{
			if ( i > 50 )
			{
				if ( inv[i]->is_character() || inv[i]->query("startroom") == base_name(ob) )
					msg += ADD0(inv[i]);
			}
			else
				msg += ADD0(inv[i]);
		}
	}

	if ( mapp(exits = ob->query("exits")) )
	{
		if ( sizeof(exits) < 1 )
			msg += ADDWAY("");
		else
		{
			outs = keys(exits);
			i = sizeof(outs);
			msg += ADDWAY(""); // �������ԭ���ķ����
			msg += ADDWAY(implode(outs[0..i - 1], ";"));
		}
	}
	else
		msg += ADDWAY("");
	
	if ( me->query("env/myhp_show") )
		msg += ROOMNAME(filter_color(ob->query("short")));

	tell_object(me ,msg);
	return 1;
}