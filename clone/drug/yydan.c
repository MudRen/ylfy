// ���յ�

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_drop","��ô����ĵ�ҩ�����˶��ϧѽ��\n");
    set("no_sell","��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
  }
  add_action("do_eat", "eat");
}

void create()
{
  set_name( HIY "���յ�" NOR , ({"yangyan dan", "dan"}));
  set_weight(90);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "һ�Ž��ɫ�ĵ��裬��΢���ŵ�Щ��������\n");
set("value", 1000000000);        	
set("no_sell",1);
    set("drug_type", "��Ʒ");
  }
  set("is_monitored",1);
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="dan" && arg!="yangyan dan")   return 0;
  
  me->set("per", 30);
  message_vision(HIG "$N��������һ�����յ��������У�$N������ͻȻ�����ޱ�...
Ҳ��֪�����˶��,$N�����Ͼ�����һ��Ƥ����...\n" NOR, me);
  destruct(this_object());
  return 1;
}

