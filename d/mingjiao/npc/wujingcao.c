// yang_ming.c �⾢��
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

object ob = this_object();
void create()
{
        set_name("�⾢��",({"wu jingcao","wu","cao"}));
        set("title","����츱ʹ");
         set("title",HIY"����츱ʹ"NOR);
        set("long", 
                "���������̵ĺ�ˮ�츱ʹ��\n"
                "����ſ���,���ո�ǿ,������˽,һ��Ϊ����ִ��.\n");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", 0);
        set("str", 24);
        set("int", 16);
        set("con", 16);
        set("dex", 24);
        
        set("max_qi",600);
        set("max_jing", 300);
        set("neili", 1000);
        set("max_neili", 600);
        set("jiali", 40);
        set("combat_exp", 50000);
        
        set_skill("sword",60);
        set_skill("dodge",60);
        set_skill("unarmed",60); 
        set_skill("force",60);
        set_skill("shenghuo-shengong",60);
        set_skill("qingyunwu", 60);
        set_skill("liehuo-jian",60);
        set_skill("parry", 60);
        
        map_skill("dodge", "qingyunwu");
        map_skill("force","shenghuo-shengong");
        map_skill("sword","liehuo-jian");
        map_skill("parry","liehuo-jian");
        
        create_family("����",35,"������ʹ");
        
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
        
}

/*
void init()
{
       object ob;

       ::init();

        ob = this_player();
        if((int)ob->query("score") < -10 && ob->query("family/master_id")=="wu jingcao")
        {
                    command("chat "+ob->query("name")+"����Ϊ�˲��Ҳ��壬�������������㣿\n");
                    command("expell "+ ob->query("id"));
                    this_player()->set("title","����" + RED + "��ͽ" NOR);   
        }

}

*/
void attempt_apprentice(object ob)
{
       if ((string)ob->query("family/family_name")!="����" || (string)ob->query("class")!="shizhe") {
                command("say " + RANK_D->query_respect(ob) + "����������ɣ��������ȥ����");
                return;
        }        

        command("say ������ �������ֵ�һ���ģ������պ󿵷����壬�������̷�����");
        command("recruit " + ob->query("id"));
        if((string)ob->query("class") != "shizhe")

        ob->set("class", "shizhe");
        ob->set("title","����������½���");
}

