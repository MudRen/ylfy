// qixing-array.c
// tender

#include <ansi.h>

inherit SKILL;

int valid_enable(string usage) { return usage=="array"; }

int form_array(object leader)
{
        object *member,ob;
        int i,j,n;

         j=sizeof (member);
        for (i=0;i<j;i++)
        {
                ob=member[i];
                if (!ob||!living(ob)||!ob->is_character())
                {
                        return notify_fail("�����˭�����?\n");
                }
                if (ob->query_temp("array/name"))
                {
                        return notify_fail("�Ѿ��������\n");
                }
       }
        n=leader->query_skill("qixing-array",1);
        for (i=0;i<j;i++)
        {
                ob=member[i];
                ob->set_temp("array/name","qixing-array");
                ob->set_temp("array/level",n);
                ob->add_temp("apply/attack",n/4/(7-j));
                if (!(ob->query_temp("apply/damage")))
                {
                        ob->set_temp("apply/damage",n/5/(7-j));
                } else {
                        ob->add_temp("apply/damage",n/5/(7-j));
                }
                ob->add_temp("apply/defense",n/3/(7-j));
        }
        message_vision( HIG "$N�������˽�̤�������Ƿ�λ������ˡ�����������󡹣�\n" NOR, leader);
        return 1;
}


int dismiss_array(object person)
{
        int i,j,n;
        object *member,ob;

        member=person->query_team();
        j=sizeof(member);
        n=person->query_temp("array/level");
        for (i=0;i<j;i++)
        {
                ob=member[i];
                ob->delete_temp("array/name");
                ob->delete_temp("array/level");
                ob->add_temp("apply/attack",-n/4/(7-j));
                ob->add_temp("apply/damage",-n/5/(7-j));
                ob->add_temp("apply/defense",-n/3/(7-j));
                tell_object(ob,"�󷨽�ɢ��\n");
        }
}

int effective_level() { return 10;}

int learn_bonus()
{
        return 0;
}
int practice_bonus()
{
        return 0;
}
int black_white_ness()
{
        return 0;
}
