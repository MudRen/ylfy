//room: changlang1.c
inherit ROOM;

void create()
{
  set("short","õ����");
  set("long",@LONG
����ͨ����λ�����޹��ĳ��ȣ����Ӻ������϶������������Ĺ�
���������һ�䷿�������ǹ��������ң����������¹��������ҡ�
LONG
     );

  set("exits",([
      "north" : __DIR__"changlang",
      "west" : __DIR__"lianxing",
      "east" : __DIR__"yaoyue",
     ]));

 setup();
 replace_program(ROOM);
}