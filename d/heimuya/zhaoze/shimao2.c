// Room: /d/heimuya/zhaoze/shimao2.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "石屋");
	set("long", @LONG
只见室中小几上点着一炉檀香，几旁两个蒲团上各坐一个僧人。一个肌肤
黝黑，高鼻深目，显是天竺国人。另一个身穿粗布僧袍，两道长长的白眉从眼
角垂了下来，面目慈祥，眉间虽隐含愁苦，但一番雍容高华的神色，却是一望
而知。
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"shimao1",
]));
    set("objects", ([
        __DIR__"npc/tzhuseng" : 1,
        __DIR__"npc/yideng" : 1,
    ]));


	setup();
	replace_program(ROOM);
}
