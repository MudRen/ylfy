//room: changlang.c
inherit ROOM;

void create()
{
  set("short","����");
  set("long",@LONG
����ͨ�������޹��ĳ��ȣ����Ӻ������϶������������Ĺ�
���������һ�䷿�䣬�����洫�������ӵ��������ƺ��кܶ��ˡ�
LONG
     );

  set("exits",([
      "west" : __DIR__"foodroom",
      "east" : __DIR__"bingqi",
      "north" : __DIR__"yihua_ge",
      "south" : __DIR__"changlang1",
     ]));

 setup();
 replace_program(ROOM);
}