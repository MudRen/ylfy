// shexin.c

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string dest, cmd;
	object ob;
	
	seteuid(getuid());
	
	if( environment(me)->query("no_fight") )
		return notify_fail("�����ֹս����\n");
	
	if( me != this_player() )
		return 0;
	
	me = this_player();
	
	if ( me->query_skill("longxiang",1) < 150 && me->query_skill("xiaowuxiang",1) < 150 )
		return notify_fail("���ѩɽ�ڹ���Ϊ�����޷���ʹ���ģ�\n");
	
	if (me->query_skill("necromancy",1) < 320)
		return notify_fail("��Ľ�������̫ǳ���ˣ�û����ʹ��������\n");
	
	if( !arg || sscanf(arg, "%s to %s", dest, cmd) != 2 )
		return notify_fail("ָ���ʽ: shexin <ĳ��> to <ָ��>\n");
	
	//if (!ob = get_object( dest ) )
	if( !objectp(ob = present(dest, environment(me))))
		return notify_fail("�Ҳ���" + dest + "��\n");
	
	if( !living(ob) )
		return notify_fail("���������ܱ����ġ�\n");
	
	if( !userp(ob) )
		return notify_fail("��ֻ�ܶ����ʩ�����Ĵ󷨡�\n");

	if( ob->query("age") < 18 && !ob->query_condition("killer") )
		return notify_fail("�㲻����С�������Ź��ɣ�\n");

	if( me->is_busy() )
		return notify_fail("����һ��������û����ɣ�û����ʹ��������\n");
	
	if( wiz_level(me) < wiz_level(ob) )
		return notify_fail("��û����" + ob->name() + "��ʹ��������\n");
	
	message_vision("$N��һ���۾������ţ�ֻ������ϸ�죬��ϸ����ӨȻ�й⣬�����������ʡ�$n΢�����ף�Ҫ��תͷ�ܿ�$N���۹⣬����һ˫�۾����Ʊ�$N��Ŀ����ס�ˣ���������������������\n", me, ob);
	
	if( random(me->query_skill("necromancy",1)) < random(ob->query_skill("force",1)))
	{
		message_vision("ͻȻ$n�͵�һ�����ѣ����ǣ�$n���һ����������ˣ���������ʩ��������\n", me, ob);
		me->fight_ob(ob);
		me->start_busy(random(3));
		ob->kill_ob(me);
		return 1;
	}

	if( random(me->query("combat_exp")) < random(ob->query("combat_exp")) )
	{
		message_vision("ͻȻ$n�͵�һ�����ѣ����ǣ�$n���һ����������ˣ���������ʩ��������\n", me, ob);
		me->fight_ob(ob);
		me->start_busy(random(3));
		ob->kill_ob(me);
		return 1;
	}

	if( random(me->query("xyzx_sys/level")) <= random(ob->query("xyzx_sys/level")) )
	{
		message_vision("ͻȻ$n�͵�һ�����ѣ����ǣ�$n���һ����������ˣ���������ʩ��������\n", me, ob);
		me->fight_ob(ob);
		me->start_busy(random(5));
		ob->kill_ob(me);
		return 1;
	}

	if( random(me->query("xyzx_sys/lingxing")) <= random(ob->query("xyzx_sys/lingxing")) )
	{
		message_vision("ͻȻ$n�͵�һ�����ѣ����ǣ�$n���һ����������ˣ���������ʩ��������\n", me, ob);
		me->fight_ob(ob);
		me->start_busy(random(5));
		ob->kill_ob(me);
		return 1;
	}

	if( random((int)me->query("max_neili")) < random((int)ob->query("max_neili")) )
	{
		message_vision("ͻȻ$n�͵�һ�����ѣ����ǣ�$n���һ����������ˣ���������ʩ��������\n", me, ob);
		me->fight_ob(ob);
		me->start_busy(random(15));
		ob->kill_ob(me);
		return 1;
	}

	if( random((int)me->query("max_jingli")) < random((int)ob->query("max_jingli")) )
	{
		message_vision("ͻȻ$n�͵�һ�����ѣ����ǣ�$n���һ����������ˣ���������ʩ��������\n", me, ob);
		me->fight_ob(ob);
		me->start_busy(random(15));
		ob->kill_ob(me);
		return 1;
	}

	if( random(me->query_int()) < random(ob->query_int()) )
	{
		message_vision("ͻȻ$n�͵�һ�����ѣ����ǣ�$n���һ����������ˣ���������ʩ��������\n", me, ob);
		me->fight_ob(ob);
		me->start_busy(random(30));
		ob->kill_ob(me);
		return 1;
	}
	
	if (strsrch(cmd, "give ") >= 0)
	{
		message_vision("���ǣ�$n���Ժ���Ҳ��֪���ǵ���Щʲô��$N��\n", me, ob);
	}
	else
	{
		if (strsrch(cmd, "go ") >= 0)
		{
			if( !userp(ob) )
				return notify_fail("��ֻ�ܶ������ʹ��������\n");
			message_vision("�����$n���Ժ���Ҳ��֪����ô���¾���ǰ�����߿��ˡ�\n", me, ob);
		}
		else
		{
			if (strsrch(cmd, "follow ") >= 0)
			{
				if( !userp(ob) )
					return notify_fail("��ֻ�ܶ������ʹ��������\n");
				message_vision("��Ȼ��$n���Ժ����ؾ͸���$N��ƨ�ɺ������ˡ�\n", me, ob);
			}
			else
				return notify_fail("��ֻ�������˼�����give��go��follow��\n");
		}
	}
	
	if( wizardp(ob) )
		return notify_fail("��ʦ���ܱ������ġ�\n");
	
	if( userp(ob) )
		log_file("shexin_player", sprintf("[%s] %s shexin %s to %s\n",ctime(time()), geteuid(me), geteuid(ob), cmd));
	return ob->force_me(cmd);
}

int help(object me)
{
        write(@Help
 ָ���ʽ: shexin <ĳ��> to <ָ��>

 shexin sb to give sth to sb
 shexin sb to follow sb
 shexin sb to go <dir>

�����������ջ�ĳ���������ϵĶ�������, ���������뿪������
�����㡣��Ȼ�������ѩɽ�ɵ��ӣ������൱�Ľ�������Ϊ��
�Է�����ڹ���񣬶���ѧ�ղ�������ȻҲ�������������������ģ�
Help
        );
        return 1;
}

