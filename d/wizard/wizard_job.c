// Room: /d/wizard/wizard_room.c
inherit ROOM;
void create()
{
    set("short", "巫师会议室");
    set("long", @LONG
这里就是「夕阳再现之风云再起」巫师的会议室，四周乱	
七八糟地摆着几张凳子。中间桌子的案台上压着一本巫师工作计
划表。
LONG );
    set("exits", ([ /* sizeof() == 1 */
    "down" : __DIR__"wizard_room" ]));
    set("valid_startroom", 1);
	set("objects", ([
    "/clone/misc/player":1,
	]));
    set("no_fight", "1");
    set("no_clean_up", 0);
    setup();
        call_other("/clone/board/wizard_j", "???");
    replace_program(ROOM);
}
