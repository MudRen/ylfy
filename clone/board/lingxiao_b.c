// /clone/board/shashou_b.c

inherit BULLETIN_BOARD;

void create()
{
set_name("�����ǵ������԰�", ({ "board" }) );
set("location", "/d/lingxiao/dadian");	
set("board_id", "lingxiao_b");
set("long", "����һ���������ǵ��ӽ��������԰塣\n" );
	setup();
	set("capacity", 60);
	replace_program(BULLETIN_BOARD);
}

