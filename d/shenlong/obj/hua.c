inherit ITEM;
#include <ansi.h>
void init()
{
        add_action("do_eat", "eat");
}
void create()
{
        set_name(HIG "���㻨" NOR, ({"hua", "baixiang"}));
        set("unit", "��");
        set("long", "����һ�����޵Ļ�������Ũ���쳣��\n");
        setup();
}
int do_eat(string arg)
{
    if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
        message_vision(HIY "$N����һ��"+this_object()->name()+"��Ȼ��ֻ��һ������ֱ���ķ�...\n" NOR, this_player());
        this_player()->add("max_neili",2);
        this_player()->unconcious();
       this_object()->move(VOID_OB);
        destruct(this_object());
        return 1;
}
int query_autoload() { return 1; }