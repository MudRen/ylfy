// shenliwan.c ������

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIG "������" NOR, ({ "shenli wan", "wan"}) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��԰԰�������裬��˵���˿�����ǿ������\n");
set("value", 1000000000);	
set("no_sell",1);
                set("unit", "��");
        }
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
object me = this_player();	
object ob;	

        if (! id(arg))
                return notify_fail("��Ҫ��ʲô��\n");
if( !objectp(ob = present(arg, me)) )		
return notify_fail("ʲô?\n");		

        me = this_player();
        message_vision("$Nһ������������һ��" + this_object()->name() +
                       "��\n", me);
        if (me->query("gift/shenliwan") >= 5)
        {
                message_vision("$Nգգ�ۡ�\n", me);
                tell_object(me, "�������ҩûɶζ���������绨���óԡ�\n");
        } else
        if (random(5) == 0)
        {
                tell_object(me, "��������ú���ûʲô���á�\n");
        } else
        {
                tell_object(me, HIR "�����˫�ۼ������ѣ�������������\n" NOR);
                me->add_temp("apply/strength", 1);
        }

        me->add("gift/shenliwan", 1);
        destruct(this_object());
        return 1;
}

