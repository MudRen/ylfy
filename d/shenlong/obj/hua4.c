inherit ITEM;
#include <ansi.h>
void init()
{
        add_action("do_eat", "eat");
}
void create()
{
    set_name(HIC "�����" NOR, ({"hua", "feicui"}));
        set("unit", "��");
    set("long", "����һ��ǧ���ѵ�һ���������,��˵�ܽ�ٶ���\n");
        setup();
}
int do_eat(string arg)
{
    if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
    this_player()->set_temp("nopoison", 1);
    this_player()->set("eff_jing",this_player()->query("max_jing"));
    this_player()->set("jing",this_player()->query("max_jing"));
    this_player()->set("eff_qi",this_player()->query("max_qi"));
    this_player()->set("qi",this_player()->query("max_qi"));
    message_vision(HIG "$Nֻ��һ�����������ķ�,��ʱ��̨һƬ����,������ˬ��\n" NOR,this_player() );
       this_object()->move(VOID_OB);
    destruct(this_object());
    return 1;
}
int query_autoload() { return 1; }