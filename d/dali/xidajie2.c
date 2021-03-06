// Room: /d/dali/xidajie2.c
// Data: 哈迪斯(hades)
// Time: 公元：1999年4月19日，北京时间：21时40分48秒。

inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
这里的街道宽敞而干净，汉白玉砌的路面被雨水冲得光明如镜，但街
道两侧的店铺群立而又参差不齐，过往的人来去匆匆，只听到树上的小鸟
时而不时的啾鸣几声，这里到处都散发着安祥宁静的气氛。往西通向大理
城西门，往东就到了大理城的中心。路的两旁种满了珍奇的花草。透过一
株株开的正艳的茶花向两旁看去，你会发现路的北面有一家[1;32m石铺[2;37;0m，路的南
面是大理最有名的青楼[1;35m鸣玉坊[2;37;0m。
LONG
	);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"zhubaodian",
  "west" : __DIR__"xidajie3",
  "east" : __DIR__"xidajie1",
  "south" : __DIR__"mingyu",
]));

	setup();
}
