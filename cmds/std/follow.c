// follow.c
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob, env, *obs;
	int i;

	if ( !arg ) return notify_fail("ָ���ʽ��follow <ĳ��>|none��\n");
	if ( arg=="none" )
	{
		if ( objectp(ob=me->query_leader()) ) 
		{
			message_vision("$N�������ٸ���$nһ���ж���\n", me, ob);
			me->set_leader(0);
			return 1;
		} 
		else 
		{
			write("�����ڲ�û�и����κ��ˡ�\n");
			return 1;
		}
	}
	env = environment(me);
	if ( !objectp(env) ) return 0;
	if ( !objectp(ob = present(arg, env)) )
	{
		if ( !playerp(me) )
		{
			obs = all_inventory(env);
			for ( i=0; i<sizeof(obs); i++ )
			{
				if ( objectp(obs[i]) 
					&& obs[i]->query("id")==arg 
					&& (sscanf(base_name(obs[i]), "/clone/map/npc/%*s") 
						|| sscanf(base_name(obs[i]), "/clone/migong/npc/%*s")) )
				{
					ob = obs[i];
					break;
				}
			}
		}
	}
	if ( !objectp(ob) ) return notify_fail("����û�� " + arg + "��\n");
	if ( !ob->is_character() ) return notify_fail("ʲô������...." + ob->name() + "��\n");
	if ( ob==me ) return notify_fail("�����Լ���\n");
	if ( ob == me->query_leader() ) return notify_fail("���Ѿ�����"+ob->name()+"�ˡ�\n");
	/*if ( ob->query_leader()==me ) 
	{
		if ( playerp(me) ) return notify_fail("�����������ء�\n");
		ob->set_leader(0);
	}*/
	
	me->set_leader(ob);
	message_vision("$N������ʼ����$nһ���ж���\n", me, ob);
	return 1;
}

int help (object me)
{
        write(@HELP
ָ���ʽ : follow [<����>|none]
 
���ָ�������ܸ���ĳ�˻����
������� follow none ��ֹͣ���档
 
HELP
);
        return 1;
}
