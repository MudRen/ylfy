// gongnu.c

inherit NPC;

void create()
{
        set_name("��Ů",({ "gong nu", "girl" }) );
        set("gender", "Ů��" );
        set("age", 17);
        set("long", "һλ����ʹ������幬Ů�������󷢣��̳�������һ��װ��Ŀ�ޱ��顣\n");
        set_temp("apply/defense", 5);
        set("combat_exp", 7000);
        set("shen_type", 1);
        set("per", 28);
        set("str", 14);
        set("dex", 15);
        set("con", 16);
        set("int", 15);
        set("attitude", "friendly");
        setup();
        carry_object(__DIR__"obj/whitecloth1")->wear();
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
