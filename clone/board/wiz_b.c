// /clone/board/wiz_b.c
inherit BULLETIN_BBSD;
void create()
{
        set_name("巫师留言簿", ({ "board","thousand-gold" }) );
	set("location", "/d/wizard/wizard_room");
	set("board_id", "wiz_b");
	set("long", "这是一个专供巫师使用的留言板。\n" );
	setup();
	set("capacity", 300);
    replace_program(BULLETIN_BBSD);
}

