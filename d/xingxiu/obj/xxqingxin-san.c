#include <ansi.h>
inherit ITEM;
void create()
{
   set_name("����ɢ", ({"qingxin san", "san"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("unit", "��");
      set("value", 1000);
   }
   setup();
}
int init()
{
   add_action("do_eat", "eat");
}
int do_eat(string arg)
{
   object me = this_player();
   if(!id(arg))
       return notify_fail("��Ҫ��ʲô��\n");
   message_vision("$N����һ��" + name() + "��\n", me);
   if ((int)me->query_condition("xx_poison") > 0) {
    if ((int)me->query_condition("xx_poison") < 11) {
      me->apply_condition("xx_poison", 0);
      message_vision("$N���ϵĶ������ˣ���ɫ����ȥ�ö��ˡ�\n", me); }
   else {
   me->apply_condition("xx_poison", (int)me->query_condition("xx_poison") -10);
      message_vision("$N����ɫ��������������\n", me);
   }
  }
    else tell_object(me, "����û����ޱ���ˬ��\n" NOR );
   destruct(this_object());
   return 1;
}
int query_autoload() { return 1; }