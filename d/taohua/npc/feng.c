inherit NPC;
inherit F_MASTER;
void consider();
void create()
{
        set_name("��Ĭ��", ({"feng mofeng", "feng", "mofeng"}));
        set("gender", "����");
        set("age", 27);
        set("long", 
        "�����һ����������ڵ���֮һ��������ǰ�һ��������������ӡ�\n"
        "���ӣ���ҩʦһŭ֮���ۼ��޹������ڵ��ӵĽŽ�ȫ�����ϣ�\n");
        set("attitude", "peaceful");
        set("str", 20);
        set("int", 29);
        set("con", 29);
        set("dex", 25);
        set("qi", 800);
        set("max_qi", 800);
        set("jing", 800);
        set("max_jing", 800);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 20);
        
        set("combat_exp", 100000);
        
        set_skill("force", 70);
        set_skill("bibo-shengong", 70);
        set_skill("unarmed", 80);
        set_skill("luoying-zhang", 80);
        set_skill("dodge", 60);
        set_skill("literate",70);
        set_skill("anying-fuxiang", 70);
        set_skill("parry", 80);
        set_skill("qimen-wuxing",50) ;
        map_skill("force"  , "bibo-shengong");
        map_skill("unarmed", "luoying-zhang");
        map_skill("dodge"  , "anying-fuxiang");
        map_skill("parry"  , "luoying-zhang") ;
        
        create_family("�һ���", 2, "����");
        setup();
        carry_object("/clone/cloth/cloth")->wear();
}
void attempt_apprentice(object ob)
{
        if (ob->query_int() >= 25) 
        {
                command("say �ðɣ��Ҿ������㡣�Ժ�Ҫ���һ�������ѽ��\n" ) ;
                command("say �һ�Ӱ����񽣣��̺����������\n");
                command("recruit "+ob->query("id"));
                if((string)ob->query("class") != "scholar")
                        ob->set("class", "scholar");
                return;
        }
        command("say ��......���һ����ĵ��ӱ������ʴ������ҿ���������ƺ����ʺ�"
            "�����һ������书��\n") ;
}
