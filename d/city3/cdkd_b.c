// /clone/board/cdkd_b.c, xixi

inherit BULLETIN_BOARD;

void create()
{
	set_name("�ɶ����վƵ����԰�", ({ "board" }) );
	set("location", "/d/city3/kedian");
	set("board_id", "beiyou_b");
	set("long", "����һ���ɶ����վƵ�����԰塣\n" );
	setup();
	set("capacity", 30);
	replace_program(BULLETIN_BOARD);
}
