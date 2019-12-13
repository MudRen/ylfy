inherit ROOM;

nosave object *working_obs = ({});

void init()
{
    if ( this_player() ) add_action("do_work", "work");
    //      if ( !wizardp(this_user()) )
    add_action("discmds",({"duanlian","ansuan","touxi","persuade","teach","exert","exercise","study","learn","sleep","kill","steal","cast","conjure","expell","fight","hit","perform","prcatice","scribe","surrender"}));
}

int discmds()
{
    tell_object(this_player(),"��������ʵʵ�����ɣ���\n");
    return 1;
}

void got_gold(object me,int amount)
{
    int money;
    money = me->query("money");
    money += amount*10000;
    if(money>100000000)
    {
	money -= 100000000;
	me->add("more_money",1);
    }
    me->set("money",money);
}

int do_work(string arg)
{
    object me;
    int max;

    me = this_player();

    if ( !objectp(me) ) return 0;
    if ( !arrayp(working_obs) ) working_obs = ({});

    working_obs -= ({ 0 });
    max = sizeof(working_obs);

    if ( (int)me->query("jing")<random(30) || (int)me->query("qi")<random(30) )
    {
	tell_object(me,"�㿪ʼ����ع���......\n");
	write("��ͻȻ�е�ͷ���ۻ�������������\n");
	tell_room(environment(me), RED+me->name() +"��ɫ�����������ͷ������ĺ�������ϻ���������\n��,����һ��ҪǮ��Ҫ����..!\n"NOR, ({me}));
	me->unconcious();
	return 1;
    }
    if ( (int)me->query("jing")<60 || (int)me->query("qi")<60 ) 
	return notify_fail("��������ˣ�ҪǮ��Ҫ������\n");
    if ( me->query_temp("working") ) return notify_fail("����ѽ��˭������ѽ��\n");
    if ( max > get_system_config(DATA_CONFIG_DIR "work.h", "max_doing_user") ) 
    {               
	write("�ϰ�ٺ�һЦ�������������Ѿ����ˣ����幤��û��Ǯ��Ӵ��\n");
	me->start_busy(5);
	return 1;
    }
    tell_object(me,"�㿪ʼ����ع���......\n");
    working_obs += ({ me });
    me->set_temp("working", 1);
    me->add_temp("work_times", 1);
    return 1;
}

private void heart_beat()
{
    object me;
    int max, i,pay;

    if ( !arrayp(working_obs) ) 
    {
	working_obs = ({});
	return;
    }

    working_obs -= ({ 0 });

    if ( !(max=sizeof(working_obs)) ) return;

    for ( i=0; i<max; i++ )
    {
	me = working_obs[i];

	if ( !objectp(me) ) continue;

	me->receive_damage("jing", 50); 
	me->receive_damage("qi", 50);   

	if ( (string)environment(me)->query("short")!="����ӹ���" || me->query_temp("work_out") )
	{
	    tell_object(me, "�㹤����ʱ��С�������˰���ʲô��û�õ�!\n");
	    me->delete_temp("working");
	    me->delete_temp("work_out");
	    working_obs[i] = 0;
	    continue;
	}
	if ( random((int)me->query_temp("work_times")) > 60+random(100) )
	{
	    tell_object(me,"�ϰ����˵���ţ����Ĳ������Ǹ���Ľ�����\n");
	    tell_object(me,HIW"���Ǯׯ���������ʮ���ƽ�"NOR"\n"NOR);
	    got_gold(me,10);
	    me->add("potential", 30, 1);
	    me->delete_temp("work_times");
	    me->delete_temp("working");
	    working_obs[i] = 0;
	    continue;
	}

	tell_object(me,"������Ĺ������ڽ����ˣ�����Ҳ�۵İ�����\n");
	pay = 5+random(get_system_config(DATA_CONFIG_DIR "work.h", "max_give_gold"));
	got_gold(me,pay);       
	me->add("combat_exp",random(10), 1);
	me->add("potential",random(10), 1);
	tell_object(me,"�ϰ�����ض���˵��������Ĺ�Ǯ��\n");
	tell_object(me,sprintf(HIW"���Ǯׯ�������%s���ƽ�"NOR"\n"NOR,chinese_number(pay)));
	me->set_temp("die_for","�ڹ���ӹ�����");
	me->delete_temp("working");
	working_obs[i] = 0;
    }

    working_obs -= ({ 0 });
}

int valid_leave(object me, string dir)
{
    mapping exits;
    string *dirs;
    int i,leave;
    leave=0;
    mapp(exits = this_object()->query("exits"));
    dirs=keys(exits);
    dirs -= ({ 0 });
    for(i=0;i<sizeof(dirs);i++)
    {
	if(dir == dirs[i])
	{
	    leave = 1;
	    break;
	}
    }
    if ( me->query_temp("working") && leave ) 
	me->set_temp("work_out",1);
    me->delete_temp("working");
    return ::valid_leave(me, dir);
}

void reset()
{
    set_heart_beat(10+random(get_system_config(DATA_CONFIG_DIR "work.h", "do_heart_times")));
    ::reset();
}

