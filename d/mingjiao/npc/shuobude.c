// shuobude.c ˵����
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

object ob = this_object();
void create()
{
        set_name("˵����",({"shuo bude","shuo"}));
       set("nick",YEL"˵���ú���"NOR);
       set("title",RED"������ɢ��"NOR);
        set("long", 
                "���������̵���ɢ��֮һ��\n"
                "��һ��ɮ�˴�磬������Ц�ݣ���������̵Ļ���˵���ú��С�\n");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", 0);
        set("str", 25);
        set("int", 28);
        set("con", 24);
        set("dex", 25);
        
        set("max_qi",1600);

        set("max_jing", 1000);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 40);
        set("combat_exp", 500000);
        
        set_skill("sword",180);
        set_skill("dodge",180);
        set_skill("unarmed",160); 
        set_skill("literate",160);
        set_skill("force",180);
        set_skill("shenghuo-shengong",80);
        set_skill("qingyunwu", 180);
        set_skill("shenghuo-jian",180);
        set_skill("shenghuo-quan",180);
        set_skill("parry", 180);
        
        map_skill("dodge", "qingyunwu");
        map_skill("force","shenghuo-shengong");
        map_skill("sword","shenghuo-jian");
        map_skill("parry","shenghuo-jian");
        map_skill("unarmed","shenghuo-quan");
        
        create_family("����",34,"����");


        setup();
        carry_object("/clone/cloth/cloth")->wear();
        
}


/*
void init()
{
       object ob;

       ::init();

        ob = this_player();
        if( ((int)ob->query("score") < 20 || (int)ob->query("shen") < -10 ) && ob->query("family/master_id")=="shuo bude")
        {
                    command("chat "+ob->query("name")+"����Ϊ�˲��Ҳ��壬�������������㣿\n");
                    command("expell "+ ob->query("id"));
                    this_player()->set("title","����" + RED + "��ͽ" NOR);   
        }

}

*/
void attempt_apprentice(object ob)
{
/*
        if((int)this_player()->query("combat_exp") >=10000){
        command("smile");
        command("say �ܺã�" + RANK_D->query_respect(ob) + 
"���Ŭ�������ձض����гɾͣ���һ��ΰҵ��\n");
        command("recruit " + ob->query("id") );
        ob->set("class", "shizhe");
        command("haha");
        } else
*/
        if((int)this_player()->query("combat_exp") < 10000)
        {
        command("shake");
        command("say ����" + RANK_D->query_respect(ob) + 
"��Ҫ�ḻ��ʵս���顣\n");
                return;
      }
        if ((int)ob->query("shen") < 0) {
                command("say " + RANK_D->query_respect(ob) +
                        "������֪����ƽ����޼�թ֮�ˣ�������̫�ͣ��Ҳ�������������̰벽��");
                return;
        }
       if ((string)ob->query("family/family_name")!="����" || (string)ob->query("class")!="shizhe") {
                command("say " + RANK_D->query_respect(ob) + "����������ɣ��������ȥ����");
                return;
        }        

        if ((int)ob->query("score") <= 20) {
                command("say ��λ" + RANK_D->query_respect(ob) +
          "�ƺ����ҽ̻��������ģ��һ��������㡣");
                return;
        }

        command("say ������ �������ֵ�һ���ģ������պ󿵷����壬�������̷�����");
        command("recruit " + ob->query("id"));
        if((string)ob->query("class") != "shizhe")

        ob->set("class", "shizhe");
}
