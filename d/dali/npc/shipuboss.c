//shipuboss.c ����ʯ
inherit NPC;
void create()
{
        set_name("����ʯ", ({ "leng mengshi", "leng", "mengshi" }));
        set("gender", "����");
        set("age", random(10) + 50);
        set("str", 25);
        set("title", "ʯ���ϰ�");
        set("dex", 16);
        set("long","����������ʯ�����ϰ壬��˵����������ʱ������һ�������\n"
"����ʯ����Ϊ������Ϊ����ʯ���Ǵ���һ��һ�ĺ�ʯ��\n");
        set("combat_exp", 50000);
        set("shen_type", 1);
        set("attitude", "peaceful");
        set_skill("unarmed", 60);
        set_skill("force", 60);
        set_skill("sword", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 30);
        set("neili", 400); 
        set("max_neili", 400);
        set("jiali", 10);
        set("chat_chance", 5);
        set("chat_msg", ({
        "\n�����ʯ���������£��͹����ǲ���Ҳ����һ�档\n",
        "\nСɽ��С�ĵ㣬��һ�������������ġ�\n",
        }) );
 
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
