// /clone/board/qq.c
inherit BULLETIN_BOARD;
void create()
{
set_name("�����������۰�",({ "board" }) );	
        set("location", "/d/city/qq");
        set("board_id", "qq_b");
set("long", "���ǣͣգİ������໥�����ĵõ����԰塣\n" );	
	setup();
	set("capacity", 30);
	set("unit","��");
	replace_program(BULLETIN_BOARD);
}
