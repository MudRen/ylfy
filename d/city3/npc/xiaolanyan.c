// bye enter

inherit NPC;

void create()
{
        set_name("С����", ({ "xiao lanyan", "xiao" }));
        set("gender", "����");
        set("age", 19);
        set("long", "���Ǹ�����������С���ۣ������Ĵ�������\n");
        
        set("combat_exp", 1000);
        set("shen_type", -1);

        set("attitude", "peaceful");
        
        set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);

        setup();
        carry_object("/clone/cloth/cloth")->wear();
        add_money("silver",2);
}

