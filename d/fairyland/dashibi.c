
inherit ROOM;
void create()
{
	set("short", "大石壁");
	set("long", @LONG
你爬了很久，手肘膝盖都已被坚冰割得鲜血淋漓，总算山坡已不如何陡峭
了，再一步步向前行，走到了此处大山壁，此大山壁如一堵大屏风，阻住你的
去路，东面是一个大平台。
LONG	);
	set("exits", ([
		"east" : __DIR__"dapingtai",
	]));
	set("outdoors", "昆仑山");
	set("no_clean_up", 0);

	setup();
        replace_program(ROOM);
}
