// yang_ming.c ��ң
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

object ob = this_object();
void create()
{
        set_name("��ң",({"fan yao","fan","yao"}));
        set("title","���̹�����ʹ");
         set("title",RED"���̹�����ʹ"NOR);
        set("long", 
                "���������̵Ĺ�����ʹ��\n"
                "���������ͷ��,��ſ�ΰ,\n"
                "�����������˵Ķ��ǵ���,������ò�Ѳ��ɱ�.\n");
        set("age", 43);
        set("attitude", "peaceful");
        set("shen_type", 0);
        set("str", 26);
        set("int", 14);
        set("con", 18);
        set("dex", 22);
        
        set("max_qi",2000);
        set("max_jing", 1000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 80);
        set("combat_exp", 4000000);
        
        set_skill("sword",280);
        set_skill("dodge",280);
        set_skill("unarmed",280); 
        set_skill("literate",280);
        set_skill("force",280);
        set_skill("shenghuo-shengong",280);
        set_skill("qingyunwu", 280);
        set_skill("liehuo-jian",280);
        set_skill("parry", 280);
        
        map_skill("dodge", "qingyunwu");
        map_skill("force","shenghuo-shengong");
        map_skill("sword","liehuo-jian");
        map_skill("parry","liehuo-jian");
        
        create_family("����",34,"����");
        
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
        if( ((int)ob->query("score") < 100 || (int)ob->query("shen") < 1000 ) && ob->query("family/master_id")=="fan yao")
        {
                    command("chat "+ob->query("name")+"����Ϊ�˲��Ҳ��壬�������������㣡\n");
                    command("expell "+ ob->query("id"));
                    this_player()->set("title","����" + RED + "��ͽ" NOR);   
        }

}

*/
void attempt_apprentice(object ob)
{
        if ((int)ob->query_dex() < 27) {
                command("say " + RANK_D->query_respect(ob) +
                        "���ֲ��ݣ����������ʦ�ɡ�");
                return;

        }
        if ( (int)ob->query("score") <= 100 ) {
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "�ƺ����ҽ����Ĳ��������Ҳ������㡣");
                return;
        }

       if ((string)ob->query("family/family_name")!="����" || (string)ob->query("class")!="shizhe") {
                command("say " + RANK_D->query_respect(ob) + "����������ɣ��������ȥ����");
                return;
        }        

        if ((int)ob->query("shen") < 5000) {
                command("say " + RANK_D->query_respect(ob) +
                        "������֪����ƽ����޼�թ֮�ˣ�������̫�ͣ��Ҳ��������������书���ˡ�");
                return;
        }
        command("say ������ �������ֵ�һ���ģ������պ󿵷����壬�������̷�����");
        command("recruit " + ob->query("id"));
        if((string)ob->query("class") != "shizhe")
        ob->set("class", "shizhe");
        ob->set("title","���̹�����ʹ���½���");
}

