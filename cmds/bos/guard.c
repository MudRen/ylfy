// guard.c

inherit F_CLEAN_UP;

mapping default_dirs = ([
"north":        "��",
"south":        "��",
"east":	        "��",
"west":	        "��",
"northup":      "����",
"southup":      "����",
"eastup":       "����",
"westup":       "����",
"northdown":    "����",
"southdown":    "����",
"eastdown":	    "����",
"westdown":	    "����",
"northeast":    "����",
"northwest":    "����",
"southeast":    "����",
"southwest":    "����",
"up":           "��",
"down":	        "��",
"out":	        "����",
"in" :          "��",
"enter" :       "����",
]);

int main(object me, string arg)
{
	object ob,obj,*enemy;
	int i;
	
	if( me->is_busy() )
		return notify_fail("������û�а취����ȥ�������£�\n");
	
	if( !arg || arg=="" )
		return notify_fail("ָ���ʽ��guard <����> | <��Ʒ> | <����>\n");

	if( arg == "None" && me->query_temp("guard_ob"))
	{
		me->delete_temp("guard_ob");
		write("ʲôҲ�������ˣ����Ǻ����ɡ�\n");
		return 1;
	}

	if( arg )
	{
		if( environment(me)->query("exits/" + arg) )
			ob = environment(me);
		else
			ob = present(arg,environment(me));
	}

	if( !ob )
		return notify_fail("��Ҫ����˭��ʲ�ᣬ�����ĸ�����\n");
	
	if( arg == me->query_temp("guard_ob") )
	{
		if( ob->query("exits/" + arg) )
		{
			write("������ס�� " + default_dirs[arg] + " �ķ���,��׼�κ����뿪.\n");
			return 1;
		}
		
		if( living(ob) )
		{
			write("�������ػ��� " + ob->query("name") + " ��\n");
			return 1;
		}
		else
		{
			write("�������� " + ob->query("name") + " һ�ԣ���ֹ�������ߡ�\n");
			return 1;
		}
	}
	
	if( ob==me )
		return notify_fail("�����Լ�������˵��Ҳ�������԰ɡ�\n");

	if(ob->query_temp("guard_for"))
		obj = find_living(ob->query_temp("guard_for"));

	if( objectp(obj) )
	{
		if( environment(me) == environment(obj) && ob->query_temp("guard_for") != me->query("id") )
			return notify_fail(ob->query("name") +" �Ѿ������ػ����ˡ�\n");
	}

	if( ob->query("exits/" + arg) )
	{
		if( ob->query("no_fight") )
			return notify_fail("���ﲻ׼ս��,Ҳ��׼��ס����ȥ·��\n");

		message_vision("$N��ʼ��ס�� " + default_dirs[arg] + " �ķ������κ���ͨ�С�\n", me);
	}
	else
	{
		if( living(ob) )
		{
			if( !userp(ob) )
				ob->set_temp("guard_for",me->query("id"));
			message_vision("$N��ʼ����$n��\n", me, ob);
		}
		else
			message_vision("$Nվ�����ϵ�$nһ���������������ȡ�ߡ�\n", me, ob);
	}

	if(me->query_temp("guard_ob"))
		obj = find_living(me->query_temp("guard_ob"));

	if( objectp(obj) && environment(obj) )
	{
		obj->delete("guard_for");
		if(obj != me)
		{
			tell_object(obj, me->query("name") + " ���ٱ������ˡ�\n");
			tell_object(me, "��ֹͣ�˶� " + obj->query("name") +" �ı�����\n");
		}
	}

	me->set_temp("guard_ob", arg);
	
	if( !userp(ob) && ob->query("combat_exp") > me->query("combat_exp") )
	{
		enemy = ob->query_enemy();
		i = sizeof(enemy);
		while(i--)
		{
			if( enemy[i] && living(enemy[i]) )
			{
				if( userp(enemy[i]) )
				{
					enemy[i]->start_busy(5);
					enemy[i]->fight_ob(me);
				}
				else
					enemy[i]->kill_ob(me);
				
				me->kill_ob(enemy[i]);
				ob->remove_all_killer();
			}
		}
	}
	
	return 1;
}

int help(object me)
{
	write(@TEXT
ָ���ʽ��guard [<ĳ��>|<����ĳ��>|<ĳ������>|None]

���ָ�����������÷�ʽ���ֱ����᣺

guard <ĳ��>      ����<ĳ��>�����������ܵ�����ʱ�������߻��Զ�����ս��������
                  �ܹ�����˳λ�����ڱ�������ǰ�棬���ֻ�й���˳λǰ�ĸ�Ŀ��
                  �Ż��ܵ����������������������ĸ���  guard �㣬��Ͳ�����
                  ���κι�����

guard <����ĳ��>  ��ס���ڵ��ϵ�ĳ����������ֹ�������ã�ֻҪ�㻹��������䣬
                  ����û��æ�������£����˾��޷�������������������뿪���ٻ�
                  ����ֻҪ�������ڣ����Խ������ػ�֮�¡�

guard <ĳ������>  ��סĳ�����ڷ�ֹ�����˴���������뿪���������������������
                  �ĵ��˻���·��������¡�
                  Ŀǰ�ݲ������س���������ܡ�

guard None      ȡ����ǰ�� guard ����

ע�⣬ͨ������ guard <ĳ��> ���������⣬ֻҪ��һ�ƶ���guard ��״̬�ͻ�����
TEXT
	);
	return 1;
}
