// huoji ʯ�����
 inherit NPC;
void create()
{
        set_name("ʯ�̻��", ({ "shipu huoji", "huoji" }));
        set("str", 20);
        set("gender", "����");
        set("age", 18);
        set("long", "���ڵ�ʯ������ʹ����ȥʮ��ǿ׳�����󻹻Ἰ���书��\n");
        set("combat_exp", 2500);
        set("attitude", "friendly");
        setup();
        carry_object("/clone/cloth/cloth")->wear();
}

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
