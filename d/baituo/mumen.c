//room: mumen.c
inherit ROOM;
void create()
{
  set("short","Ĺ��");
  set("long",
       "���Ǹ�һ������Ĺ�ص�Ĺ�š�����ʯ�񻨵���������ʯ���·�棬\n"
   "�޼�����ĳ���ľ���Ե�ׯ�����¡�Ĺ�ű�����һ�����ɫʯ��(bei)��\n"
      );
  set("exits",([
      "south" : __DIR__"fende",
//      "northeast" : __DIR__"gongzhu",
     ]));
  set("item_desc",([
  "bei" : "   �������ء�  \n�ޡ������ơ��߽��룡\n",
  ]));
  set("objects",([
    __DIR__"npc/shiwei" : 1,
    ]));
 set("outdoors", "baituo");
 setup();
 replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
	object ob=present("shi wei", environment(me));
	if (objectp(ob) && living(ob))
              if (  (dir == "northeast")   && (!present("jinpai",me)))
			return notify_fail("��������һ������û�С������ơ������ܽ�ȥ��\n");
	return ::valid_leave(me, dir);
}
