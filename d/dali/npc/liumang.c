// liumang.c ��å
inherit NPC;
void create()
{
        set_name("��å", ({ "liu mang", "liu" }));
        set("gender", "����");
        set("age", 19);
        set("long", "����һ���������ֺ��е���å�����õ��ǰװ����ֵģ�Ҳ����ǰ�й�Ǯ��\n");
        
        set("combat_exp", 1000);
        set("shen_type", -1);
        set("attitude", "peaceful");
        
        set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);
        setup();
        carry_object("//clone/cloth/hic_cloth")->wear();
        add_money("silver",2);
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
