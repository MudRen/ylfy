// /clone/board/studio_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("巫师工作进程留言板", ({ "board" }) );
        set("location", "/d/wizard/studio");
	set("board_id", "studio_b");
	set("long", "这里是专门供巫师交流工作进程的流言版。\n" );
	setup();
	set("capacity", 150);
	replace_program(BULLETIN_BOARD);
}

