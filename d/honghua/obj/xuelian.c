//xuelian.c ѩ����
inherit ITEM;
#include <ansi.h>
void init()
{
        add_action("do_eat", "eat");
}
void create()
{
        set_name(HIW "ѩ����" NOR, ({"xuelian", "xuelian"}));
        set("unit", "��");
        set("long", "����һ��������ѩɽ�ϵ�ѩ��������׵Ļ����ϸ��ż��ž�
Ө��¶�飬��ɢ���ŵ���������\n");
        setup();
}
int do_eat(string arg)
{
        object me;
        me = this_player();
        if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
        if( me->query("max_neili") < 10000 ) 
        {
                me->add("max_neili",random(180));
//              this_player()->add("max_jing",random(15));
                message_vision( HIG"$N����һ��"NOR,me );
                message_vision( HIW"ѩ����"NOR,me );
                message_vision( HIG"����ʱ������̨һ�壬һ������ֱ���ζ�������ͷ��ð��˿˿������\n"NOR,me );
        }
        else {
                message_vision( HIG"$N����һ��"NOR,me );
                message_vision( HIW"ѩ����"NOR,me );
                message_vision( HIG"�����Ǻ���û�����κ����á�\n"NOR,me );
        }
        destruct(this_object());
        return 1;
}
