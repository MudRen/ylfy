// shipopo.c ʷ����

inherit NPC;
inherit F_UNIQUE;
//inherit F_SKILL;

void create()
{
        set_name("ʷ����", ({ "shi", "popo" }));
        set("title", "������������");
        set("gender", "Ů��");
        set("long", "����ѩɽ�������˰����ڵ����ӣ���˵���������Եò��ϣ�\n"
        "����ʮ��ǰ���𡰽���һ֦����ʷС������������ȴ�����˲�֪��\n");
        set("age", 68);

        set("int", 30);
        set("str",400);

        set("qi", 50000);
        set("max_qi", 50000);
        set("jing", 5000);
        set("max_jing", 5000);
        set("shen_type", 1);

        set("combat_exp", 17500000);
        set("attitude", "friendly");

        set_skill("force", 470);
        set_skill("dodge", 470);
        set_skill("blade", 440);
        set_skill("parry", 490);
        set_skill("unarmed", 490);
       set_skill("snowstep", 70);
       set_skill("jinwu-blade", 100);

        set_temp("apply/attack", 350);
        set_temp("apply/defense", 350);
        set_temp("apply/damage", 335);


        map_skill("blade", "jinwu-blade");
        map_skill("parry", "jinwu-blade");
        map_skill("dodge", "snowstep");
        setup();
        carry_object("/clone/weapon/gangdao")->wield();
}

