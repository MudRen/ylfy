// Room: /d/city/pine.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "大榕树上");
	set("long", @LONG
你现在正攀附在大榕树的树干上，从这里可以很清楚地望见树下的
一切动静，而不被人发觉，似乎是个干偷鸡摸狗勾当的好地方。
LONG
);

	setup();
	replace_program(ROOM);
}
