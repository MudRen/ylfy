#include <ansi.h>
inherit ITEM;

void create()
{
     set_name(HIB"��Ů�ľ�  ����ƪ"NOR, ({
              "yunv jing",
              "book"
             }));
     set_weight(200);
     if (clonep())
     set_default_object(__FILE__);
     else {
     set("unit", "��");
     set("long", 
     "����һ�ű�����˿����������Щ���ֺ�ͼ����������ϰ��Ů
�ľ��Ĺ�Ĺ��ܸ��\n");
     set("value", 600);
     set("material", "paper");
     setup();
}
}
void init()
{
   add_action("do_xiuxi", "xiuxi");
}

int do_xiuxi(string arg)
{
   object me = this_player();

   if (arg && id(arg))
{  if ((int)me->query("qi") < 30)
   return notify_fail("����Ҫ��Ϣһ�ᣬ�Ȼ�����ϰ�ɡ�\n");
   message_vision("$N���ű�����˿�ʼ��ϰ��Ĺ�ڹ��ķ���\n", me);
   if (me->query_skill("yunv-xinjing", 1) < 30)
   return notify_fail("��Ů���ľ��ĳ���ƪ�㻹δ��ϰͨ͸���޷�������ϲ���书��\n");
   if (me->query_skill("yunv-xinjing", 1) > 100)
   return notify_fail("�����Ů�ľ�����һ�㣬����˫�˺�����Ů���ˡ�\n");
   me->improve_skill("yunv-xinjing", (int)((me->query_int())/(1+random(1))));
   me->receive_damage("jing", 40);
   me->receive_damage("jingli", 15);
   return 1;
}
   write("��Ҫ��ϰʲô? \n");
   return 1;
}

int query_autoload() { return 1; }