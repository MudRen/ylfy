// /clone/board/kedian_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("�͵����԰�", ({ "board" }) );
	set("location", "/d/tiezhang/wztang");
	set("board_id", "tiezhang_b");
	set("long", "�����õĻ���������˵���ҹ�ˮɱ���⡣\n" );
	setup();
	set("capacity", 30);
	replace_program(BULLETIN_BOARD);
}

