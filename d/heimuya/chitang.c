//room: 
inherit ROOM;
void create()
{
  set("short","����");
  set("long",@LONG
����һ��С����,������������ԧ��������䣬�ر߻�����ֻ�׺�����ʳ��
LONG 
     );
  set("exits",([
      "north"      : __DIR__"baihutang",
      "west" : __DIR__"shenggu",
	   "east" :__DIR__"chufang2",
     ]));
 setup();
 replace_program(ROOM);
}
