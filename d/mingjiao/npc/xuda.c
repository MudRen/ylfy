// xuda.c ���
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
object ob = this_object();
void create()
{
        set_name("���",({"xu da","xu"}));
       set("nick",YEL"�Ƕ���"NOR);
            set("nickname", YEL "�Ƕ���" NOR);
        set("long", 
                "���ǹ������ϵ��������Ƕ��ǡ�\n"
                "��ͷ��һ����ñ������һ������������һ���;��������Ƕ�ı��\n");
        set("age", 25);
        set("attitude", "peaceful");
        set("shen_type", 0);
        set("str", 20);
        set("int", 38);
        set("con", 18);
        set("dex", 23);
        set("neili", 800);

        set("max_neili", 800);
        set("jiali", 10);
        set("combat_exp", 20000);
        set_skill("sword",50);
        set_skill("dodge",50);
        set_skill("unarmed",60); 
        set_skill("literate",80);
        set_skill("force",50);
        set_skill("shenghuo-shengong",60);
        set_skill("qingyunwu", 60);
        set_skill("shenghuo-jian",60);
        set_skill("shenghuo-quan",60);
        set_skill("parry", 60);
        map_skill("dodge", "qingyunwu");
        map_skill("force","shenghuo-shengong");
        map_skill("sword","shenghuo-jian");
        map_skill("parry","shenghuo-jian");
        map_skill("unarmed","shenghuo-quan");
        create_family("����",35,"����");
        setup();
         carry_object("/clone/cloth/cloth")->wear();
}

/*
void init()
{
       object ob;

       ::init();

        ob = this_player();
        if((int)ob->query("score") < -50 &&ob->query("family/master_id")=="xu da")
        {
                    command("chat "+ob->query("name")+"����Ϊ�˲��Ҳ��壬�������������㣿\n");
                    command("expell "+ ob->query("id"));
                    this_player()->set("title","����" + RED + "��ͽ" NOR);   
        }

}

*/
void attempt_apprentice(object ob)

{
        if ((int)ob->query("shen") < 0) {
        command("say ��ֻ�²��ʺ������ʦ�����㻹����Ͷ�߾Ͱɡ�");
                return;
        }
        command("say �������������ϲ��������������֮ʿ������......��");
        command("recruit " + ob->query("id"));
        if((string)ob->query("class") != "shizhe")

        ob->set("class", "shizhe");
}

