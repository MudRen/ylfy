// ji.c ������
// By csy 1999.03

inherit NPC;

void create()
{
        set_name("������", ({"ji qingxu", "ji"}));
        set("gender", "����");
        set("age", 24);
        set("class", "taoist");
        set("long",
                "����һλ���ǿ���������ʿ���ƺ������ա�\n");
        set("attitude", "friendly");
        set("shen_type",1);
        set("str", 26);
        set("int", 25);
        set("con", 25);
        set("dex", 26);

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "sword.qixing" :),
                (: exert_function, "recover" :),
        }) );

        set("qi", 500);
        set("max_qi", 500);
        set("jing", 400);
        set("max_jing", 400);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 10);

        set("combat_exp", 60000);
        set("score", 10000);

        set_skill("force", 40);
        set_skill("tiangang-zhengqi", 40);    
        set_skill("sword", 40);
        set_skill("quanzhen-jianfa",40);  //ȫ�潣
        set_skill("dodge", 40);
        set_skill("qixing-huanwei", 40);  
        set_skill("parry", 40);
        set_skill("strike",40);
        set_skill("unarmed",40);
        set_skill("qixing-array", 40);  
        set_skill("literate",40);
        set_skill("taoism",40);

        map_skill("force", "tiangang-zhengqi");
        map_skill("sword", "quanzhen-jianfa");
        map_skill("dodge", "qixing-huanwei");
        map_skill("parry", "quanzhen-jianfa");

        create_family("ȫ���", 4, "����");

        set("inquiry", ([
                "ȫ���" :  "��ȫ��������µ����������ڡ�\n",
        ]) );

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/quanzhen/obj/greyrobe")->wear();

}

