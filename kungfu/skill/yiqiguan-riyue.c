
#include <ansi.h>
inherit FORCE;

int valid_enable(string usage)
{
        return usage == "force";
}

int valid_learn(object me)
{
    mapping skl;
    string *sname;
    int t = 1, i;
    int lvl = (int)me->query_skill("yiqiguan-riyue", 1);
    if ( me->query("gender") == "����" && lvl > 49)
        return notify_fail("���޸����ԣ����������������������һ�������¡�\n");
    if(lvl<=100)
    {
        if (lvl > 10 && (int)me->query("shen") < t * 20) 
            return notify_fail("�����������̫���ˣ������������һ�������¡���\n");
    }
    else
    {
        if ((int)me->query("shen") < (51200 + (lvl - 100) * 2000)) 
            return notify_fail("�����������̫���ˣ������������һ�������¡���\n");
    }
   
   if (me->query_skill("force",1)<=lvl)
        return notify_fail("��Ļ����ڹ���򻹲������޷����һ�������¡�\n");
    
	skl = me->query_skills();
    
	sname  = keys(skl);
    
	for (i=0;i<sizeof(skl);i++){
        if (sname[i]=="xixing-dafa") continue;
		if (sname[i]=="huagong-dafa") continue;
		if (sname[i]=="huaxue-dafa") continue;
		if (sname[i]=="longmen-shengong") continue;
		if (sname[i]=="yiqiguan-riyue") continue;
		if( SKILL_D(sname[i])->valid_enable("force") )
        return notify_fail("�㲻��ɢ�˱����ڹ�������ѧһ�������£���\n");
    }

    return 1;
}

int practice_skill(object me)
{
        return notify_fail("һ��������ֻ����ѧ(learn)�������������ȡ�\n");
}

void skill_improved(object me)
{
        switch (me->query_skill("yiqiguan-riyue",1))
        {
                case 50:
                {
                        message_vision(HIY "$N�Ķ�ͷ�ƺ�����ǰ�����˲��١�����������������һ����Ρ�\n" NOR, me);
                        tell_object(me, HIY "���������ѧ����������Է���ָ�������ˣ���\n\n" NOR);
                        break;
                }
                case 100:
                {
                        message_vision(HIC "��ͻȻ����$N��̫��Ѩ���Ե�ͻ���ˡ����$N�Ĺ���������������\n" NOR, me);
                        tell_object(me, HIC "�������һ�������µĽ�һ����������Է������������������ھ��ˣ���\n\n" NOR);
                        me->set("yiqiguan-riyue",1);
                        break;
                }
                case 150:
                {
                        message_vision(HIW "$N��̫��Ѩ��ͻ���״̬�ָֻ�ԭ�����ͳ���һ��������$N�Ĺ����Ѿ���豹����ˡ�\n" NOR, me);
                        tell_object(me, HIW "�������һ�������µĸ���һ����������Է������Ƿ��켫�����ھ��ˣ���\n\n" NOR);
                        me->set("yiqiguan-riyue",2);
                        break;
                }

        }
        return;
}

string exert_function_file(string func)
{
        return __DIR__"yiqiguan-riyue/" + func;
}

