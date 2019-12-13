// go

inherit F_CLEAN_UP;
inherit F_MAP_XY;

mapping default_dirs = ([
	"north":	"����",
	"south":	"�Ϸ�",
	"east":		"����",
	"west":		"����",
	"northup":	"����",
	"southup":	"�ϱ�",
	"eastup":	"����",
	"westup":	"����",
	"northdown":"����",
	"southdown":"�ϱ�",
	"eastdown":	"����",
	"westdown":	"����",
	"northeast":"����",
	"northwest":"����",
	"southeast":"����",
	"southwest":"����",
	"up":		"����",
	"down":		"����",
	"enter":	"����",
	"out":		"����",
	"leitai":	"��̨����",
]);

void create()
{
	seteuid(getuid());
}

int jing, m_jing, eq, mq;

int main(object me, string arg)
{
	string dest, mout, min, dir, face, thing_msg, room;
	object env, obj, obj1, thing;
	mapping exit;
	object follow_ob,*enemys;
	int flag,i;
	
	eq = me->query("eff_qi");
	mq = me->query("max_qi");
	jing = me->query("jing");
	m_jing = me->query("max_jing");
	reset_eval_cost();
	
	if( !arg )
		return notify_fail("��Ҫ���ĸ������ߣ�\n");

	if( me->over_encumbranced() )
		return notify_fail("��ĸ��ɹ��أ��������á�\n");

	if( me->is_busy() )
		return notify_fail("��Ķ�����û����ɣ������ƶ���\n");

	env = environment(me);
	
	if(!env)
		return notify_fail("������Ҳȥ���ˡ�\n");

	if( !mapp(exit = env->query("exits")) || undefinedp(exit[arg]) ) {
        if( query_verb()=="go") {
		    if( !environment(me)->query("outdoors") ) 
			{
				    if((int)me->query("qi") > (int)me->query("max_qi")/2)
					{
						me->add("jing",-1);
						me->add("qi",-3);
						write( "�������û�г�·��\n" );
						return 1;
					} else { 
						me->add("qi",-3);
						write("�������û�г�·��\n" );
						return 1;
					}
			} else  return notify_fail("�������û�г�·��\n");
		}
		else
				return notify_fail("�������û�г�·��\n" );
	}

	dest = exit[ arg ];
	
	if( !(obj = load_object(dest)) )
	{
		if(file_size(file_name(environment(me))+".c")>0)
		{
			message("channel:wiz",HIG"\n����ͼ���顽 ����"+environment(me)->query("short")+"("+file_name(environment(me))+")"+"�����д����ٸ�����\n\n"NOR,users());
			log_file("map_error","����"+environment(me)->query("short")+"("+file_name(environment(me))+")"+"�����д����ٸ�����\n");
		}
		
		write( "��Ҫȥ������û����ͨ,��֪ͨ������Ա��\n");
		return 1;
	}
	
	if ( !(obj = find_object(dest)) )
		return notify_fail( sprintf( "�޷��� %s �ƶ���\n", dest ) );
	
	obj1 = find_object(dest);
	
	if(obj1->query("wiz_only")&&!wizardp(me))
	   return notify_fail("����ֻ�й�����Ա���ܽ�ȥ��\n");
	if(obj1->query("building"))
	   return notify_fail("���ﻹ��ʩ�������Ժ�������\n");
	
	if( !env->valid_leave(me, arg) )
		return 0;
	
	if( !undefinedp(default_dirs[arg]) )
		dir = default_dirs[arg];
	else
		dir = arg;
    
	if (!dir || !me)  return 0;
	if( me->is_fighting() ) 
	{
		mout = me->name() + "��" + dir + "��Ķ����ˡ�\n";
		min = me->name() + "����ײײ�����˹�����ģ����Щ�Ǳ���\n";
	}
	else if( wizardp(me) && me->query("env/invisibility") && me->query("env/msg_off"))
    {
		mout = "";
		min = "";
	}
	
	else 
	{
		face="��";         	
             if( me->query("gender") == "Ů��") {
			mout = "һ��ٻӰ��" + dir + "�뿪��\n";
			min = "һ��ٻӰ���˹�����\n";
            if (me->query("per") >= 35) face =HIM+"���޾���"+NOR + face;
            if ((me->query("per") >= 28) && (me->query("per") < 35)) face= "��������" + face;
			if ((me->query("per") >= 26) && (me->query("per") < 28)) face= "��������" + face;
			if ((me->query("per") >= 24) && (me->query("per") < 26)) face= "��ɫ����" + face;
			if ((me->query("per") >= 21) && (me->query("per") < 24)) face= "��Ŀ毺�" + face;
			if ( me->query("per") < 21)
			{
			if (me->query("str") <= 16) face = "ͤͤ����" + face;
			if ((me->query("str") <= 20) && (me->query("str") > 16)) face= "��̬��ӯ"+ face;
			if ((me->query("per")<21) && (me->query("str")>20) || !userp(me)) face = "";
			}
		}
                else {
			mout = "һ����Ӱ��" + dir + "�뿪��\n";
			min = "һ����Ӱ���˹�����\n";
			if (me->query("per") >= 30) face= "�����ٷ��" + face;
			if ((me->query("per") >= 26) && (me->query("per") < 30)) face="Ӣ������" + face;
			if ((me->query("per") >= 22) && (me->query("per") < 26)) face="�Ǳ�����" + face;
			if (me->query("per") < 22)
			{
			if (me->query("str") >=23) face = "�����Բ" + face;
			if ((me->query("str") >= 15) && (me->query("str") < 23)) face= "���׳˶"+ face;
			if ((me->query("per") < 22) && (me->query("str") < 15) || !userp(me)) face = "";
			}
		}
	        if (objectp(thing = me->query_temp("armor/cloth")))
			thing_msg = "����" + thing->query("name");
		else
			thing_msg = "ȫ���������";
	        if (objectp(thing = me->query_temp("weapon")))
			thing_msg += "��ִ" + thing->query("name");
		if ( me->query("race") == "Ұ��")
		{
			mout = me->name() + "������" + dir + "һ�ܾ���ʧ�ˡ�\n";
			min = me->name() + "���ش��˳�������������������š�\n";
		}
		else
		{
			if ( me->query_temp("is_riding"))
			{
				mout = me->name()+"����"+me->query_temp("is_riding")+"��" + dir + "���۶�ȥ��\n";
				min = face + me->name() + thing_msg + "����"+me->query_temp("is_riding")+"һ·���۶�����\n";
			}
	
			else if(100*jing/m_jing<=20)
			{   
				mout = me->name()+"ҡҡ�λε���"+dir+"��ȥ���ۿ���Ҫ���¡�\n";
				min = me->name()+"ҡҡ�λε����˹������Ϳ��۵�ſ���ˡ�\n";
			}
			else if(100*jing/m_jing<=40)
			{
				mout = me->name()+"����ƣ���ĽŲ���"+dir+"�뿪��\n";
				min = face+me->name()+"ƣ�����������˹�����\n";
			}
			else if(100*jing/m_jing<=70)
			{
				mout = face +me->name()+"���ų��صĽŲ���"+dir+"�뿪��\n";
				min = me->name()+thing_msg+"ƣ�������˹�����\n";
			}
			else if(100*eq/mq<=30 )
			{
                                mout = me->name()+"��ס�����������ű������˵Ĳ�����" + dir + "��ȥ�����Ϻ�Ȼ����һ�����߰ߵ�"+HIR"Ѫ��"NOR+"��\n";
                                min =me->name()+ "��ס�����������ű������˵Ĳ������˹�����\n";
                        }
                        else if(100*eq/mq<=50 )
                        {
                                mout = me->name()+"��������"+HIR"��Ѫ"NOR+"�����壬һȳһ�յس�" + dir + "Ųȥ��\n";
                                 min =me->name()+"��������"+HIR"��Ѫ"NOR+"�����壬һȳһ�յ�Ų�˹�����\n";
                         }
                         else if(100*eq/mq<=70)
                         {
                                mout = me->name()+"һ�߲�����ǵ�"+HIR"��Ѫ"NOR+"��һ�߳�" +dir+"��ȥ��\n";
                                min = me->name()+"һ�߲�����ǵ�"+HIR"��Ѫ"NOR+"��һ�����˹�������������ġ�\n";
                         }
                         else if(100*eq/mq<=90 )
                         {
                                mout = face+me->name()+"��ͷ�������Ǳ���������"+dir+"��ȥ��\n";
                                 min = me->name()+thing_msg+"��ͷ�������Ǳ����������˹�����\n";  
                          }
                          else if(100*eq/mq<=95)
                          {
                                mout = me->name()+"һ�����Ե�ת��"+dir+"��ȥ����ɫ������Щ�ѿ���\n";
                                min = me->name()+"�񶷰��˵Ĺ�������ͷɥ�������˹�����\n";
                           }
                           else if ( arg == "leitai")
			{
				mout = me->name()+"˫�����ţ��������Σ�����Ծ����̨��\n";
				min = me->name()+"����̨��һԾ�������ȵ�����̨�ϡ�\n";
			}
			else
			{
				mout = me->name() + "��" + dir + "�뿪��\n";
				min = face + me->name() + thing_msg + "���˹�����\n";
			}
		}		
	}
	if(!(wizardp(me) && me->query("env/invisibility") == 10) && !env->query("no_msg_vision"))
	message( "go", mout, environment(me), ({me}) );
	
	// ��־�Ǵ���̨����
	flag = 0;
	if ( (room=base_name(env))=="/d/wizard/fightroom3" || room=="/d/wizard/fightroom2" )
		flag = 1;

	if ( me->move(obj) ) 
	{
//		me->remove_all_enemy(flag);
		/*
		 * ս���п������ƶ������в����������ڹֵ�init���������kill_ob��fight_ob
		 * ��������ڷ���ͻᴥ���ֵ�init��ֱ���Ƴ����е��˻ᵼ��ս���޷�����
		 */
		enemys = me->query_enemy();
		for(i=0;i<sizeof(enemys);i++)
		{
		    if(!objectp(enemys[i]))
			continue;
		    if(environment(enemys[i])!=obj)
		    {
			me->remove_enemy(enemys[i]);
			enemys[i]->remove_enemy(me);
		    }
		}
		
		if ( !playerp(me) && objectp(follow_ob=me->query_leader()) )
		{
			if ( me->is_killing(follow_ob) ) 
				me->kill_ob(follow_ob);
			if ( playerp(follow_ob) && 
				(me->query("is_boss") || me->query("end_boss")) )
				me->fight_ob(follow_ob);
		}
		if ( !(wizardp(me) && me->query("env/invisibility") == 10) && !obj->query("no_msg_vision"))
		{
			if ( me->query_condition("killer") ) min = HIR"��ɱ��ͨ������"NOR + min;
			message( "go", min, environment(me), ({me}) );
		}
		
		me->set_temp("pending", 0);
		me->delete_temp("pended");
		
		if ( me->query("jing") > me->query("max_jing") )
			me->set("jing",me->query("max_jing"));
		
		all_inventory(env)->follow_me(me, arg);
		return 1;
	}

	return 0;
}

void do_flee(object me)
{
	mapping exits;
	string *directions;

	if( !environment(me) || !living(me) ) return;
	exits = environment(me)->query("exits");
	if( !mapp(exits) || !sizeof(exits) ) return;
	directions = keys(exits);
	tell_object(me, "�������һ���������...(����Ҫȡ���Զ��������������"HIY"wimpy 0"NOR")\n");
	main(me, directions[random(sizeof(directions))]);
}

int help(object me)
{
	write(@HELP
ָ���ʽ : go <����>
 
������ָ���ķ����ƶ���
 
HELP
    );
    return 1;
}


