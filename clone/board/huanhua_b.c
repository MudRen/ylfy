// /clone/board/huanhua_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("佻����ɵ������԰�", ({ "board" }) );
        set("location", "/d/huanhua/dating");
	set("board_id", "huanhua_b");
	set("long", "����һ����佻����ӽ��������԰塣\n" );
	setup();
	set("capacity", 30);
	replace_program(BULLETIN_BOARD);
}

