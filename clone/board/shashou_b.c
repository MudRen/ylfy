// /clone/board/shashou_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("ɱ��¥�������԰�", ({ "board" }) );
        set("location", "/d/shashou/jiaochang");
	set("board_id", "shashou_b");
	set("long", "����һ����ɱ��¥���ӽ��������԰塣\n" );
	setup();
	set("capacity", 60);
	replace_program(BULLETIN_BOARD);
}

