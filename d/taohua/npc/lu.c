//inherit NPC;
inherit NPC;
inherit F_MASTER;
void consider();
void create()
{
        set_name("½�˷�", ({"lu chengfeng", "lu", "cheng"}));
        set("gender", "����");
        set("age", 30);
        set("long", 
        "�����һ����������ڵ���֮һ��������ǰ�һ��������������ӡ�\n"
        "���ӣ���ҩʦһŭ֮���ۼ��޹������ڵ��ӵĽŽ�ȫ�����ϣ�\n");
        set("attitude", "peaceful");
        set("str", 20);
        set("int", 29);
        set("con", 25);
        set("dex", 27);
        set("qi", 1000);
        set("max_qi", 1000);
        set("jing", 1000);
        set("max_qi", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 50);
        set("combat_exp", 200000);
        set_skill("force", 90);
        set_skill("bibo-shengong", 90);
        set_skill("unarmed", 80);
        set_skill("luoying-zhang", 80);
        set_skill("dodge", 70);
        set_skill("literate",90);
        set_skill("anying-fuxiang", 80);
        set_skill("parry", 85);
        set_skill("sword", 90);
        set_skill("qimen-wuxing",60) ;
        set_skill("luoying-shenjian",90);
        map_skill("force"  , "bibo-shengong");
        map_skill("unarmed", "luoying-zhang");
        map_skill("dodge"  , "anying-fuxiang");
        map_skill("sword"  , "luoying-shenjian") ;
        map_skill("parry"  , "luoying-shenjian") ;
        create_family("�һ���", 2, "����");
        setup();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}
void attempt_apprentice(object ob)
{
        if (ob->query_int() >= 25) 
        {
                command("nod") ;
                command("say �һ�Ӱ����񽣣��̺����������\n");
                command("recruit "+ob->query("id"));
                if((string)ob->query("class") != "scholar")
                        ob->set("class", "scholar");
                return;
        }
        command("say ��......���һ����ĵ��ӱ������ʴ������ҿ���������ƺ����ʺ�"
            "�����һ������书��\n") ;
}
