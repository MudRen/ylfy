// /clone/board/studio_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("��ʦ�����������԰�", ({ "board" }) );
        set("location", "/d/wizard/studio");
	set("board_id", "studio_b");
	set("long", "������ר�Ź���ʦ�����������̵����԰档\n" );
	setup();
	set("capacity", 150);
	replace_program(BULLETIN_BOARD);
}

