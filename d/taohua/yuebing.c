#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(RED+"�����±�"+NOR, ({"cake",}));
    set_weight(20000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "һ��СС�������±��������������ֱ����ˮ����޲������ϳ�(eat)��ȥ��\n");
    set("value", 1);
    set("no_drop", "�����ĺö�����Ҳ�������ӣ���\n");
    set("no_get", "ע�����ʳ��������Ҫ�洦�����ԡ�\n");
  }
    setup();
}
void init()
{
    add_action("do_chi", "eat");
}
int do_chi(string arg)
{
    object me = this_player();
    
  if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
  if (me->query("m_cake")) 
   message_vision(HIC "$Në��ë�žͰ�С�±��������ͣ����������̵�����ú�Ʒ��Ʒ����������һ����С�±�\n�������ϣ�ˤ���ˣ���ô��ô��С�İ����ô�\n" NOR,me);
  else { 
   me->add("max_neili", 100);
   message_vision(HIC "$Në��ë�žͰ�С�±��������ͣ����������̵�����ú�Ʒ��Ʒ�������Ϲ���һ����Ȼ��\n��������ȥ��ҭ��$N�ò����ײŻ������������ô�Һ��ô�Ц��\n" NOR, me);
   me->set("m_cake", 1);
  }
   destruct(this_object());
   return 1;
}
void owner_is_killed() { destruct(this_object()); }
