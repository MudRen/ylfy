// Room: /d/dali/dongdajie1.c
// Data: 哈迪斯(hades)
// Time: 公元：1999年4月21日，北京时间：17时31分11秒。

inherit ROOM;

void create()
{
	set("short", "东大街");
	set("long", @LONG
这里的街道宽敞而干净，汉白玉砌的路面被雨水冲得光明如镜，但街
道两侧的店铺群立而又参差不齐，过往的人来去匆匆，只听到树上的小鸟
时而不时的啾鸣几声，这里到处都散发着安祥宁静的气氛。往东通向大理
城东门，往西就到了大理城的中心。路的两旁种满了珍奇的花草。透过一
株株开的正艳的茶花向两旁看去，你会发现路的南面有一家[1;32m药铺[2;37;0m，路的北
面是[1;32m朝阳路[2;37;0m。
LONG
	);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"dbdajie1",
  "west" : __DIR__"guangchang",
  "east" : __DIR__"dongdajie2",
  "south" : __DIR__"yaopu",
]));

	set("objects", ([ /* sizeof() == 2 */
        __DIR__"npc/girl" : 1,
        __DIR__"npc/girl1" : 1,
]));

	setup();
}
