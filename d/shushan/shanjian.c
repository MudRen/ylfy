//����ɽ�ɡ�mhxy-yushu 2001/2
inherit ROOM;
int do_climb(string arg);
void create ()
{
  set ("short","ɽ��");
  set ("long", @LONG

���������Դ�ʹ������������ҿ�û��ˤ��������������������
����������(climb)��ȥ��Ҳ������ǰ���߿�����
LONG);

  set("exits", ([      
         "north" : __DIR__"shanjian2",
 ]));
 setup();
}

void init ()
{
  add_action ("do_climb","climb");
}

int do_climb(string arg)
{
  object me;me=this_player();
  if ((arg != "ya" && arg != "��") || !arg)
       return notify_fail("������ʲô��\n");
  if (me->is_busy()) return notify_fail("��æ���أ�\n");
 if (arg="ya"&&arg="��") 
  {
  message_vision("$N������������ȥ������\n",me);
  message_vision ("$N�������������ϡ���������\n",me);
  me->move(__DIR__"jby");
}

  return 1;
}