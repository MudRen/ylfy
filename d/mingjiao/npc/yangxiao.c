// yangxiao.c ����

inherit NPC;
#include <ansi.h>
inherit F_MASTER;

object ob = this_object();
void create()
{
        set_name("����",({"yang xiao","yang","xiao"}));
        set("title","���̹�����ʹ");
         set("title",RED"���̹�����ʹ"NOR);
        set("long", 
                "���������̵Ĺ�����ʹ��\n"
                "��ɫ���۵���������,��ò����.ֻ��˫ü�´�,\n"
                "���¶��������������,�����Դ�˥�����֮��.\n"
                "�����Բ���,��ɫĮȻ,�ƺ��ĳ�Զ��,������ʲô����.\n");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", 0);
        set("str", 22);
        set("int", 28);
        set("con", 12);
        set("dex", 20);
        set("per", 28);
        
        set("max_qi",3500);
        set("max_jing", 1000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 80);
        set("combat_exp", 9000000);
        
        set_skill("sword",280);
        set_skill("dodge",280);
        set_skill("unarmed",280); 
        set_skill("literate",280);
        set_skill("force",280);
        set_skill("shenghuo-shengong",280);
        set_skill("qingyunwu", 280);
        set_skill("shenghuo-jian",280);
         set_skill("shenghuo-jian", 280);
        set_skill("parry", 280);
        
        map_skill("dodge", "qingyunwu");
        map_skill("force","shenghuo-shengong");
        map_skill("sword","shenghuo-jian");
        map_skill("parry","shenghuo-jian");
        
        create_family("����",34,"ʹ��");
        
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
        if( ((int)ob->query("score") < 100 || ob->query("shen") < 1000 ) && ob->query("family/master_id")=="yang xiao")
        {
                    command("chat "+ob->query("name")+"����Ϊ�˲��Ҳ��壬�������������㣿\n");
                    command("expell "+ ob->query("id"));
                    this_player()->set("title","����" + RED + "��ͽ" NOR);   
        }

}

*/
void attempt_apprentice(object ob)
{
        if ((int)ob->query_int() < 32) {
                command("say " + RANK_D->query_respect(ob) +
                        "����Ƿ�ϣ���ѧ������һ���书��");
                return;
        }
       if ((string)ob->query("family/family_name")!="����" || (string)ob->query("class")!="shizhe") {
                command("say " + RANK_D->query_respect(ob) + "����������ɣ��������ȥ����");
                return;
        }        

        if ((int)ob->query_dex() < 27) {
                command("say " + RANK_D->query_respect(ob) +
                        "���ֲ��ݣ����������ʦ�ɡ�");
                return;
        }
        if ((int)ob->query("shen") < 5000) {
                command("say " + RANK_D->query_respect(ob) +
                        "������֪����ƽ����޼�թ֮�ˣ�������̫�ͣ��Ҳ��������������书���ˡ�");
                return;
        }
        if ((int)ob->query("score") <= 100) {
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "�ƺ��Ա��̲������ģ��һ��������㡣");
                return;
        }
        command("say ������ �������ֵ�һ���ģ������պ󿵷����壬�������̷�����");
        command("recruit " + ob->query("id"));
        if((string)ob->query("class") != "shizhe")
        ob->set("class", "shizhe");
        ob->set("title","���̹�����ʹ���½���");
}

