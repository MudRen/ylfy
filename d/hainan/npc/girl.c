inherit NPC;

void create()
{
        set_name("�񱴿ǵ�СŮ��", ({"girl","kid","xiaohai"}));
        set("gender", "Ů��" );
        set("age", 9);
        set("long", "�����˸߲��ҵ�����,�����ջ�С��\n");
        set("combat_exp", 5000);
        set("attitude", "peaceful");
        set_skill("dodge", 100);
        set_skill("unarmed", 200);
        set_skill("literate", 300);
        set("per", 25);
        set("max_qi", 200);
        set("max_jing", 100);
        set("max_neili", 100);
        setup();
        carry_object("/d/hainan/obj/hua-cloth")->wear();
        carry_object("/d/hainan/obj/beike2");
}


