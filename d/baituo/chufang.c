//chufang.c
inherit ROOM;
void create()
{
  set("short","����");
  set("long",
  "���Ǽ���ĳ�������ʦ����չʾ���Ե���⿾��\n"
  "�����������������˴������εĲ��㡣ǽ������һ����Ŀ\n"
  "������(note)��\n"
  );
  set("exits",([
  "west" : __DIR__"huayuan",
  "east" : __DIR__"chaifang",
  ]));
  set("item_desc",([
  "note" : "����������С����ÿ��һ���񣬸����������ӡ�\n",
  ]));
  set("objects",([
  __DIR__"npc/feifei" : 1,
  __DIR__"obj/doujiang" : random(5),
  __DIR__"obj/cake"  : random(3),
  ]));
  setup();
  }
int valid_leave(object me, string dir)
{
	object ob;
	ob=present("fei fei", environment(me));
	if (objectp(ob) && living(ob) )
	if ( present("jiang", me) || present("cake", me) )
	return notify_fail("�ʷ�һ��קס������죬�ż��ؽе������˲��ܴ���ȥ����������Ѿ������ˡ�\n");
	return ::valid_leave(me, dir);
}
