//by : pipip
inherit ITEM;
#include <ansi.h>
void init()
{
        add_action("do_eat", "eat");
}
void create()
{
    set_name(HIB "̫����" NOR, ({"taiji dan", "dan"}));
        set("unit", "��");
    set("long", "�䵱��Զ���͸�������İ�����񣬲�֪Ϊ�λ��䵽�����С�\n");
        setup();
}
int do_eat(string arg)
{
    if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
  if(this_player()->query("id")==query("value"))
  return notify_fail("��õ�����������,��Ը�ʲô����\n");

   this_player()->set_skill("force",this_player()->query_skill("force",1) + 1 ); 
   message_vision(HIC "$N����̫������һ�������ӵ������𣬽���������ȫ��Ѫ����\n" NOR,this_player() );
    destruct(this_object());
    return 1;
}

