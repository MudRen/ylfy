// xixiangfang。c 西厢房
// mlf设计，lks编程

inherit ROOM;
#include <room.h>

void create()
{
	set("short","西厢房");
        set("long",@LONG
这里是血河派的西厢，房间内极尽简朴，一张红木屏风，屏风的左两
侧是由派内弟子平时在边陲采来的奇石异草，自己动手做的工艺品，极富
创造想象力。血河派疏于和外派来往，这儿便成为弟子闲聊，施展才华的
场所。因此显得格外干净，蓬壁生辉。
LONG);
               set("valid_startroom",1);
        set("exits",([
                "east" : __DIR__"zoulang1",
                "north" : __DIR__"zoulang3",
     	]));
     	setup();
     	replace_program(ROOM);
}
