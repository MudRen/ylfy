//����ɽ�ɡ�mhxy-yushu 2001/2
#include <ansi.h>
inherit ROOM;
int do_qian(string arg);
void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG

    ������һ��С��ˮ̶�����������ϵ��ٲ���������ˮ�������µ�����
��ȥ��������ˮ̶�ɣ�������Ŀ��˿����ܣ�ȫ���������ͱڣ���
�����������ȥ�ǲ������ˣ�ֻ�������漣������
LONG);

  set("exits", ([      
         "south" : __DIR__"shanjian",
 ]));
  set("item_desc",([ "ˮ̶" : "���ˮ̶��ˮ�ǳ������������������ε�������",
]));
 setup();
}

void init()
{
  add_action("do_qian", "qian");
}
int do_qian(string arg)
{
  object me;me=this_player();
  if ((arg != "shui" && arg != "ˮ") || !arg)
                       return notify_fail("����ˮ����ô�Σ�\n");
  if (me->is_busy()) return notify_fail("��æ���أ�\n");
  if (me->query("family/family_name") == "��ɽ��")
  {
   message_vision(HIM"$N������ȫ������������ε���ˮ���ϡ�\n"NOR, me);
   me->move(__DIR__"midao");
  }
else 
 {
  tell_object (me,"����ˮ̶��������һ�ᣬ����������ǻ�ȥ�ɣ���Ҫ����������!\n");
 }
 return 1;
}
