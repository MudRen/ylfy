// fuer.c

inherit NPC;

void create()
{
        set_name("������", ({ "lai fuer","lai" }) );
        set("gender", "����" );
//	set("title","�����ϰ�");
        set("age", 45);
        set("str", 16);
        set("cor", 24);
        set("cps", 11);
        set("per", 17);
        set("int", 14);
	set("long", "����������ٹȵ�����\n");

        set("attitude", "friendly");

        set("max_force", 200);
        set("force", 200);
        set("force_factor", 10);

        set("combat_exp", 5000);

        set_skill("unarmed", 30);
        set_skill("parry", 40);
        set_skill("dodge", 50);
        set_skill("force", 50);


        setup();

        carry_object("/d/wanjiegu/obj/cloth")->wear();
        carry_object("/d/wanjiegu/obj/bu-shoes")->wear();
}


