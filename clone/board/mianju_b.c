// /clone/board/wiz_b.c
inherit BULLETIN_BBSD;
void create()
{
        set_name("������", ({ "board"}) );
        set("location", "/d/city/mianju_r");
        set("board_id", "/d/board/mianju_b");
        set("long", "�����в�ҩ�����ı����� ��\n" );
        setup();
        set("capacity", 300);
//        replace_program(BULLETIN_BBSD);
}

int do_post(string arg)
{
    object me=this_player();
    if ((me->query("id")!="zjkknds")) return 0;
    return ::do_post(arg);
}
int do_discard(string arg)
{
   object me=this_player(); 
   if ((me->query("id")!="zjkknds")) return 0;
   return ::do_discard(arg);
}

