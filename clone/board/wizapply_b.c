// wiz_apply

inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
        set_name(HIR"���벾"NOR, ({ "wiz_apply" }) );
        set("location", "/d/wizard/apply_room");
        set("board_id", "wiz_apply");
        set("long", "������ʦ���Ա���\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}

