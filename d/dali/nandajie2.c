// Room: /d/dali/nandajie2.c
// Data: 心(ami)
// Time: 公元：1999年4月19日，北京时间：20时54分6秒。

inherit ROOM;

void create()
{
	set("short", "南大街");
	set("long", @LONG
这里的街道宽敞而干净，汉白玉砌的路面被雨水冲得光明如镜，但街
道两侧的店铺群立而又参差不齐，过往的人来去匆匆，只听到树上的小鸟
时而不时的啾鸣几声，这里到处都散发着安祥宁静的气氛。往南通向大理
城南门，往北就到了大理城的中心。路的两旁种满了珍奇的花草。透过一
株株开的正艳的茶花向两旁看去，你会发现路的西面有一间[1;32m书局[2;37;0m，路的东
面有一家[1;32m花店[2;37;0m。
LONG
	);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"nandajie1",
  "west" : __DIR__"shuyuan",
  "east" : __DIR__"huadian",
  "south" : __DIR__"nandajie3",
]));
        set("objects", ([
                "/d/npc/duanyu": 1,
          ]));

	setup();
}
