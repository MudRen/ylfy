// /clone/board/wiz_b.c

inherit BULLETIN_BOARD;

void create()
{
set_name("意见簿", ({ "board" }) );	
set("location", "/d/city/wumiao");    	
	set("board_id", "wiz2_b");
	set("long", "这是一个供玩家和巫师交换意见的留言板。\n" );
	setup();
        set("capacity", 300);
	replace_program(BULLETIN_BOARD);
}

