// labazou.c ������

#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("������", ({"laba", "zhou"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����࣬����������ð��أ����һ�������ݴ���
�׳彫������һ���ྡ������֮ɫ������ȥ˵�����Ĺ��졣����ҩ���̱ǣ��䶾��֪��\n");
                set("value", 50000);
        }
        setup();
}

int do_eat(string arg)
{
       
        object me = this_player();     

        if (!id(arg))
        return notify_fail("��Ҫ��ʲô��\n");
        if ( (int)me->query_temp("num" ) > 0 )
        {
                me->add_temp("num", 1);
                me->add("max_neili", -100);
                message_vision(HIR "$N�ֺ���һ�������ֻ࣬���øγ���ϣ��������ѣ�ԭ���ȵ�̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
        }

        else
        {

                me->add("max_neili", 100);
                me->add("neili", 100);

                message_vision(HIY "$N����һ�������࣬��Ȼ��ֻ��һ�ɺƵ��ޱȵ�����ֱ�嶥��...\n" NOR, this_player());
                me->set_temp("num", 1);
        }

        me->unconcious();
        destruct(this_object());
        return 1;
}


int query_autoload() { return 1; }