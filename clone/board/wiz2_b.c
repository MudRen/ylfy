// /clone/board/wiz_b.c

inherit BULLETIN_BOARD;

void create()
{
set_name("�����", ({ "board" }) );	
set("location", "/d/city/wumiao");    	
	set("board_id", "wiz2_b");
	set("long", "����һ������Һ���ʦ������������԰塣\n" );
	setup();
        set("capacity", 300);
	replace_program(BULLETIN_BOARD);
}

