// finger.c

#include <ansi.h>

inherit F_CLEAN_UP;

int help(object me);

void create()
{
	seteuid(getuid());
}

mixed query(string arg)
{
	if (arg && arg == "channel_id") return HIY "���Ӿ���(Finger)";
    return 0;
}
private void finger_user(object me,mixed ob)
{
	if (!me || !ob) return;
    
	if (objectp(ob))
	{
		if ( ob == me)
		{
			write( FINGER_D->finger_user(geteuid(ob)) );
			return;
		}

		me->set_temp("finger_time",time());

		if ( wizardp(ob) )
			tell_object(ob, HIY+me->short(1)+"���ڲ鿴������ϡ�\n"NOR);
		else if ( !wizardp(me) )
		{
			if ( random(10) > 6 && me==ob->query_temp("finger_user") )
				tell_object(ob,HIY+me->short(1)+"���ڲ鿴������ϡ�\n"NOR);
			else
				tell_object(ob,HIY"�㲻�ɵô���һ����ս...\n"NOR);
			
			CHANNEL_D->do_channel(this_object(),"sys",sprintf("%s(%s) <=Finger=> %s(%s)",me->query("name"),me->query("id"),ob->query("name"),ob->query("id")));
			ob->set_temp("finger_user",me);
		}
		write( FINGER_D->finger_user(geteuid(ob)) );
	}
	else if (stringp(ob))
	{
		CHANNEL_D->do_channel(this_object(),"sys",sprintf("%s(%s) <=Finger=> %s",me->query("name"),me->query("id"),ob));
		write( FINGER_D->finger_user(ob) );
    }
	
	return;
}

int main(object me, string arg)
{
    object ob;
    string *msg;

    if( !arg )
	{
		if ( wizardp(me) )
		{
			msg = explode( FINGER_D->finger_all(), "\n");
            foreach (string mes in msg)
			{
                write(mes+"\n");
			}
            return 1;
		}
		return help(me);
	}
	
	if( !wizardp(me) )
	{
		if( (int)me->query("jing") < 15 || time() - me->query_temp("finger_time") < 5 )
			return notify_fail("��ľ����޷����С�\n");
		me->receive_damage("jing", 15);
	}

    if ( is_chinese(arg) )
	{
        foreach (ob in users() )
		{
			if ( wizardp(ob) && !wizardp(me) ) continue;
            if ( ob->name(1) == arg )
			{
                finger_user(me,ob );
				return 1;
			}
		}
		return notify_fail("û�������ҡ�\n");
    }
	else
	{
        ob=find_player(arg);
        if (!ob)
                finger_user(me,arg );
        else
                finger_user(me,ob );
    }
    return 1;
}
int help(object me)
{
  write(@HELP
ָ���ʽ : finger <ʹ����id>
 
���ָ�����ʾ�й�ĳ����ҵ�����, Ȩ�޵�����.
 
���������ߣ�Ҳ����ʹ�� finger <ʹ����������>�����в鿴��
see also : who
HELP
    );
    return 1;
}

