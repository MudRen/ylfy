// jail.c

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
	duration--;
        if (duration < 1) {
                me->move("/d/city/xidajie1");
                me->set("title",(string)me->query("oldtitle"));
                me->delete("oldtitle");
                message("vision",
                        HIY "ֻ��ƹ��һ����������һ��������һ����\n"
                        "ԭ����һ���������ļһ�������ﱻ���˳�����\n" NOR, environment(me), me);
                tell_object(me, HIY "ֻ��һ�����Ƽ���㣬��������ر��ӳ����ݼ�����\n" NOR);
                me->set("startroom", START_ROOM);
                return 0;
        }
//      tell_object(me, "debug: " + duration + " beats more to go...\n");
        me->apply_condition("jail", duration);
        return 1;
}

