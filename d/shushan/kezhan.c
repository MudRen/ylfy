//【蜀山派】mhxy-yushu 2001/2
inherit ROOM;
void create ()
{
  set ("short","悦来客栈");
  set ("long", @LONG

    这里是外地客人落脚的首选,平时村里来了客人也会到这里来住店的，几个
跑堂的小二来来回回地招待着四方来客。楼上是客房。
LONG);

  set("exits", ([ 
     "east" : __DIR__"road1",
       "up" : __DIR__"up",
 ]));
  set("objects", ([ 
  __DIR__"npc/xiaoer2" : 1,
 ]));
  set("no_time", 1);
  set("no_fight", 1);
  set("no_magic", 1);
  set("freeze",1);
  set("resource", ([   
  "water" : 1,
]));

 setup();
}
