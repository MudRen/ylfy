#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  add_action("do_eat", "eat");
}

void create()
{
  set_name( GRN "��ת��" NOR , ({"jiuzhuan dan", "dan"}));
  set_weight(90);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "һ�Ž��ɫ�ĵ��裬��΢���ŵ�Щ��������\n");
    set("value", 0);
    set("drug_type", "��Ʒ");
  }
  set("is_monitored",1);
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="dan" && arg!="jiuzhuan dan")   return 0;
  
  me->add_skill("dodge",1);
  message_vision(HIG "$N���˵Ľ��˼�����\n" NOR, me);
  destruct(this_object());
  return 1;
}

