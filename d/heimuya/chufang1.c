//chufang1.c
inherit ROOM;
void create()
{
  set("short","����");
  set("long",
  "���Ƿ����õĳ�����һλ������Ů������Ц��\n"
  "�����������,��֬��������ǽ������һ����\n"
  "Ŀ������(note)��\n"
  );
  set("exits",([
  "east" : __DIR__"grass2",
  ]));
  set("item_desc",([
  "note" : "������,���Ǹ�,һ�ٲ��Զ��ûš�\n",
  ]));
  set("objects",([
  __DIR__"npc/shinu" : 1,
  __DIR__"obj/tea" : random(6),
  __DIR__"obj/sherou"  : random(4),
  ]));
  setup();
  }
int valid_leave(object me, string dir)
{
	if (( present("tea", me)||present("she rou", me))
	&&objectp(present("shi nu", environment(me))) )
	return notify_fail
	("��Ů��Ŀһ��,�㻹������������\n");
	return ::valid_leave(me, dir);
}

