//【蜀山派】mhxy-yushu 2001/2
inherit ROOM;
void create ()
{
  set ("short","村路");
  set ("long", @LONG

    这是一条村中的石子路。路西是一家当铺，路东面是一条小巷。东南方是
一家酒店，向西南走就要到村头了。
LONG);

  set("outdoors", 2);
  set("exits", ([      
     "north" : __DIR__"road1",
 "southwest" : __DIR__"road3",
 "southeast" : __DIR__"jiudian",
      "east" : __DIR__"xiaoxiang",
      "west" : __DIR__"dangpu",
 ]));
 setup();
}






