//inherit NPC;
inherit NPC;
inherit F_MASTER;
void consider();
void create()
{
        set_name("�����", ({"qu lingfeng", "qu", "lingfeng"}));
        set("gender", "����");
        set("age", 30);
        set("long", 
        "�����һ����������ڵ���֮һ��������ǰ�һ��������������ӡ�\n"
        "���ӣ���ҩʦһŭ֮���ۼ��޹������ڵ��ӵĽŽ�ȫ�����ϣ�\n");
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 30);
        set("con", 29);
        set("dex", 20);
        set("qi", 1000);
        set("max_qi", 1000);
        set("jing", 800);
        set("max_jing", 800);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 30);
        set("combat_exp", 150000);
        
        set_skill("force", 60);
        set_skill("bibo-shengong", 60);
        set_skill("unarmed", 90);
        set_skill("luoying-zhang", 90);
        set_skill("dodge", 50);
        set_skill("literate",80);
        set_skill("anying-fuxiang", 80);
        set_skill("parry", 90);
        set_skill("sword", 70);
        set_skill("luoying-shenjian",70);
        map_skill("force"  , "bibo-shengong");
        map_skill("unarmed", "luoying-zhang");
        map_skill("dodge"  , "anying-fuxiang");
        map_skill("sword"  , "luoying-shenjian") ;
        map_skill("parry"  , "luoying-zhang") ;
        create_family("�һ���", 2, "����");
        setup();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}
void attempt_apprentice(object ob)
{
        if (ob->query_int() >= 25) 
        {
                command("pat " + ob -> query("id") ) ;
                command("say �һ�Ӱ����񽣣��̺����������\n");
                command("recruit "+ob->query("id"));
                if((string)ob->query("class") != "scholar")
                        ob->set("class", "scholar");
                return;
        }
        command("say ��......���һ����ĵ��ӱ������ʴ������ҿ���������ƺ����ʺ�"
            "�����һ������书��\n") ;
}
