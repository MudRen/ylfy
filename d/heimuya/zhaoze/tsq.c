
inherit ROOM;

void create()
{
	set("short", "铁索桥");
	set("long", @LONG
当下扶着铁索，踏上桥板。那桥共是四条铁索，两条在下，上铺木板，以
供行走，两条在旁作为扶手。一踏上桥，几条铁索便即幌动，行到江心，铁索
晃得更加厉害，一瞥眼间，但见江水荡荡，激起无数泡沫，如快马奔腾般从脚
底飞过，只要一个失足，卷入江水，任你多好的水性也难活命。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"lczb1",
  "west" : __DIR__"zbdd",
]));
	set("outdoors", "tsq");

	setup();
	replace_program(ROOM);
}
