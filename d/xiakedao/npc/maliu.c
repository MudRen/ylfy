// maliu.c ����

inherit NPC;

void create()
{
        set_name("����", ({ "ma liu", "ma" }));
        set("long",
                "����Լ��ʮ���꣬�����ܸɣ�����������������ȴ������������һ�\n");
        set("gender", "����");
        set("age", 25);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 300);
        set("int", 35);
        set("con", 27);
        set("dex", 280);

        set("inquiry",([
            "here" : "���ﵱȻ�������͵���",
            "������" : "�������ߣ���ɽ���������",
            "������":"\nȥ���������������Ե�ְɡ�\n",
                 "ʯ����":"\n�����ҵĽ���ֵ�ѽ����Ҳ�����ء�\n",
                 "���Ʒ�����":"\n���������ֵܵ����\n",
        ]) );
        set("max_qi", 20000);
        set("qi", 20000);
        set("max_jing", 2000);
        set("jing", 2000);
        set("neili", 300000);
        set("max_neili", 3000);
        set("jiali", 1000);
        set("combat_exp", 100000000);
        set("score", 60000);

        set_skill("force", 1500);
        set_skill("taiji-shengong", 1500);
        set_skill("dodge", 1500);
        set_skill("tiyunzong", 1500);
        set_skill("unarmed", 1500);
        set_skill("taiji-quan", 2000);
        set_skill("parry", 1500);
        set_skill("sword", 1500);
        set_skill("taiji-jian", 2000);
        set_skill("taoism", 1000);
        set_skill("literate", 100);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");

        create_family("���͵�", 2, "����");
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/whiterobe")->wear();
}

