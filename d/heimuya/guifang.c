// Room: /d/heimuya/guifang.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "闺房");
	set("long", @LONG
房内花团锦簇，脂粉浓香扑鼻，东首一张梳妆台畔坐着一人，身穿粉红衣
衫，左手拿着一个绣花绷架，右手持着一枚绣花针，抬起头来，脸有诧异之色。
此人剃光了胡须，脸上竟然施了脂粉，身上那件衣衫式样男不男、女不女，颜
色之妖，便是穿在女人身上，也显得太娇艳、太刺眼了些。
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"xiaoshe",
]));
 set("objects", ([
                __DIR__"npc/dongfang" : 1,
           ]));                                                    


	setup();
	replace_program(ROOM);
}
