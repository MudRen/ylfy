// /clone/board/quanzhen_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("ȫ��̵������԰�", ({ "board" }) );
	set("location", "/d/quanzhen/sanqingdian");
	set("board_id", "quanzhen_b");
	set("long", "����һ����ȫ��̵��ӽ��������԰塣\n" );
	setup();
	set("capacity", 30);
	replace_program(BULLETIN_BOARD);
}
