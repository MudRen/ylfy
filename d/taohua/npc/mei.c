#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void consider();
void create()
{
        set_name("÷����", ({"mei chaofeng", "mei"}));
        set("nickname", RED "��ʬ" NOR ); 
        set("gender","Ů��") ;
        set("age", 34);
        set("long", 
        "�����һ����������ڵ���֮һ��Ҳ��Ψһ��Ů���ӡ�\n"
        "��Ƥ����΢����һ�㣬����ò���ǽ�����\n");
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 29);
        set("con", 20);
        set("dex", 25);
        set("qi", 1000);
        set("max_qi", 1000);
        set("jing", 1000);
        set("max_jing", 1000);
        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 100);
        set("combat_exp", 300000);
        set("shen", -50000);
        
        set_skill("force", 30);
        set_skill("bibo-shengong", 30);
        set_skill("unarmed", 90);
        set_skill("luoying-zhang",50) ;
        set_skill("jiuyin-baiguzhao", 90);
        set_skill("dodge", 70);
        set_skill("literate",50);
        set_skill("anying-fuxiang", 70);
        set_skill("parry", 60);
        map_skill("force"  , "bibo-shengong");
        map_skill("unarmed",   "jiuyin-baiguzhao");
        map_skill("dodge"  , "anying-fuxiang");
        map_skill("parry"  , "jiuyin-baiguzhao") ;
        map_skill("unarmed","luoying-zhang") ;
        create_family("�һ���", 2, "����");
        setup();
        carry_object("/clone/cloth/cloth")->wear();
}
void attempt_apprentice(object ob)
{
        if (ob->query_int() >= 25) 
        {
                command("hmm") ;
                command("say �����һ����Ĳ�Ф���ӣ�����Ӧ��ͽ�������Ȼ���İ��ң��Ҿͳ�ȫ��ɡ�\n");
                command("say �һ�Ӱ����񽣣��̺����������\n");
                command("recruit "+ob->query("id"));
                if((string)ob->query("class") != "scholar")
                        ob->set("class", "scholar");
                return;
        }
        command("say ��......���һ����ĵ��ӱ������ʴ������ҿ���������ƺ����ʺ�"
            "�����һ������书��\n") ;
}
