// Room: /inherit/room/liyubei.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "鲤鱼脊");
	set("long", @LONG
这是华山著名的险地“鲤鱼脊”。只见一条长约二十余丈，宽仅数尺的小径
直达对峰，两旁皆是云雾萦绕，深不见底的峡谷，罡风吹过，使人飘飘若起，武
林高手平时也不敢冒险越过此处。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : "/d/huashan/laojun",
  "northup" : __DIR__"houzhiwangyu.c",
]));
	set("鲤鱼脊", "short");

	setup();
	replace_program(ROOM);
}
