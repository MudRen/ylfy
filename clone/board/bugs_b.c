// /clone/board/bugs_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("�������԰�", ({ "board" }) );
        set("location", "/d/city/wumiao");
        set("board_id", "bugs_b");
        set("long", "���԰��ϵ����������棬����������Ϊ�������æ�Ĳ����ֺ���\n" );
		set("private_board", 1);
        setup();
        set("capacity", 1000);
        replace_program(BULLETIN_BOARD);
}
