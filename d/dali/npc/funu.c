// girl.c
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("���Ҹ�Ů", ({ "funu" }) );
        set("gender", "Ů��" );
        set("title", HIR "���ܴݲ�" NOR);
        set("age", 18);
        set("long",
                "һ�����ܴݲе����Ҹ�Ů\n");
        set("attitude", "friendly");
        set("per",30);
        setup();
        carry_object(__DIR__"obj/nocloth")->wear();
}

/*
void init()
{
        ::init();
        if( this_player()->query_temp("dalikill") )
        {
                 kill_ob(this_player());
        }
        add_action("do_kill","kill");
}

int do_kill(string arg)
{
        this_player()->set_temp("dalikill", 1);
        return 0;
}
*/
