// Room: /d/honghua/caoyuan.c
// Date:  98/10/29
inherit ROOM;
void create()
{
	set("short", "草原");
	set("long", @LONG
这里就是人迹罕至的大草原，一望无际的草地随风波动，天地交
接处有几个黑点，四周非常的安静，只是不时有牧女清亮的歌声不知
从哪儿飘渺的传来.
LONG
	);
	set("exits", ([
		"north" : __DIR__"shanxia",
		"south" : "/d/xingxiu/saimachang",
		]));
	set("outdoors", "honghua");
	set("coor/x",-130);
	set("coor/y",60);
	set("coor/z",0);
	set("coor/x",-130);
	set("coor/y",60);
	set("coor/z",0);
	set("coor/x",-130);
	set("coor/y",60);
	set("coor/z",0);
	set("coor/x",-130);
	set("coor/y",60);
	set("coor/z",0);
	setup();
}
