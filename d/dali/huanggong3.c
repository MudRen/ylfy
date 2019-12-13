// Room: /d/dali/huanggong3.c
// Data: 心(ami)
// Time: 公元：1999年4月19日，北京时间：13时22分2秒。

inherit ROOM;

void create()
{
	set("short", "[1;33m广场[2;37;0m");
	set("long", @LONG
这里是正德殿前的一个广场，四周种满了大理的名茶花，中间一
条白玉大道直通正德殿，大道两旁站着一排整齐严肃的禁卫军，显得
格外的庄严肃穆。
LONG
	);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"huanggong17",
  "south" : __DIR__"huanggong2",
  "northup" : __DIR__"huanggong4",
]));

                 set("objects", ([
                __DIR__"npc/taijian" : 2,
                __DIR__"npc/weishi2" : 4,
        ]));

        setup();

}

