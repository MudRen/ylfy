// /clone/board/wiz_b.c
inherit BULLETIN_BBSD;
void create()
{
        set_name("��ʦ���Բ�", ({ "board","thousand-gold" }) );
	set("location", "/d/wizard/wizard_room");
	set("board_id", "wiz_b");
	set("long", "����һ��ר����ʦʹ�õ����԰塣\n" );
	setup();
	set("capacity", 300);
    replace_program(BULLETIN_BBSD);
}

