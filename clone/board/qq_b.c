// /clone/board/qq.c
inherit BULLETIN_BOARD;
void create()
{
set_name("风云再起讨论版",({ "board" }) );	
        set("location", "/d/city/qq");
        set("board_id", "qq_b");
set("long", "这是ＭＵＤ爱好者相互交流心得的留言板。\n" );	
	setup();
	set("capacity", 30);
	set("unit","块");
	replace_program(BULLETIN_BOARD);
}
