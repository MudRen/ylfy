//shijie.c
inherit ROOM;
void create()
{
  set("short","ʯ��");
  set("long","��������ʯ���̳ɵ�ʯ�ס�\n");
  set("exits",([
      "east" : __DIR__"caoping",
	"northup" : __DIR__"damen",
      "southdown" : __DIR__"guangchang" ,
     ]));
  set("outdoors", "baituo");
  setup();
 replace_program(ROOM);
}
