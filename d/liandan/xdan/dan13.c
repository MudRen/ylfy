//by : pipip
inherit ITEM;
#include <ansi.h>
void init()
{
        add_action("do_eat", "eat");
}
void create()
{
    set_name(HIR "�ⶾ��" NOR, ({"jiedu wan", "wan"}));
        set("unit", "��");
    set("long", "���żҴ���ҩ��ר������ٶ���\n");
        setup();
}
int do_eat(string arg)
{
    if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
  if(this_player()->query("id")==query("value"))
 return notify_fail("��õ�����������,��Ը�ʲô����\n");
    this_player()->set_temp("nopoison", 1); 
	this_player()->clear_condition();
    this_player()->set("eff_jing",this_player()->query("max_jing"));
    this_player()->set("jing",this_player()->query("max_jing"));
    this_player()->set("eff_qi",this_player()->query("max_qi"));
    this_player()->set("qi",this_player()->query("max_qi"));
   message_vision(HIC "$N���½ⶾ�裬һ�������ӵ������𣬽���������ȫ��Ѫ����\n" NOR,this_player() );
    destruct(this_object());
    return 1;
}

