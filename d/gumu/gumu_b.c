// /clone/board/gumu_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("��Ĺ�������԰�", ({ "board" }) );
        set("location", "/d/gumu/rukou");
        set("board_id", "gumu_b");
        set("long", "����һ������Ĺ�����½��������԰塣\n" );
        setup();
        set("capacity", 50);
        replace_program(BULLETIN_BOARD);
}


