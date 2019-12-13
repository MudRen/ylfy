
inherit ROOM;

void create()
{
	set("short", "村东口");
	set("long", @LONG
你正走在一条青石铺成的山路上，路旁杂草丛生，一片荒凉。再往东走
就到了无量山了。
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
        "west" : __DIR__"cun8",
        "northeast" : "/d/heimuya/zhaoze/xiaodou",
	]));
   
	setup();
	replace_program(ROOM);
}

