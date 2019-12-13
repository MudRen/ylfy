// zhou.c ������
// create by host oct,23

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("������", ({ "zhou zhiruo", "zhou", "zhiruo"}));
        set("long",
"����һλ��ò��������ׯ�ɰ��Ĺ����Ȼ��ͺ��ᣬ���ڶ���������\n������͵����\n");
        set("gender", "Ů��");
        set("age", 20);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 20);
        set("int", 35);
        set("con", 30);
        set("dex", 30);
        set("per", 40);

        set("qi", 2200);
        set("max_qi", 2200);
        set("jing", 1600);
        set("max_jing", 1600);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 30);

        set("combat_exp", 8000000);
        set("score", 150000);

        set_skill("force", 280);
        set_skill("dodge", 280);
        set_skill("parry", 280);
        set_skill("sword", 280);
        set_skill("linji-zhuang",280);
        set_skill("jinding-zhang",260);
        set_skill("huifeng-jian",280);
        set_skill("zhutian-bu",285);
        set_skill("yugalism", 260);
        set_skill("dushi-jiren",150);
        set_skill("unarmed", 350);
        set_skill("zhuyan-shu", 320);
        set_skill("jiuyin-baiguzhao", 300);
        set_skill("literate", 120);
        map_skill("dodge","zhutian-bu");
        map_skill("strike","jinding-zhang");
        map_skill("unarmed","jiuyin-baiguzhao");
        map_skill("parry", "huifeng-jian");
        map_skill("sword", "huifeng-jian");
        map_skill("force","linji-zhuang");
        prepare_skill("unarmed", "jiuyin-baiguzhao");

        create_family("������", 4,"����");
        set("class","tao_lady");
        setup();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
  }

void attempt_apprentice(object ob)
 {

    mapping myfam;
    if ( (!(myfam = ob->query("family")) || myfam["family_name"] != "������") )
       {
          command("say ��ֻ�ն������µ��ӣ��㻹����ذɣ�");
          return;
        }
    if ((int)ob->query("shen") < 0) {
           command("say �Ҷ������������������ɣ��Ե���Ҫ���ϡ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                        "�Ƿ����ò�����");
                return;
        }
    if ( (int)ob->query("combat_exp") > 100000 && (int)ob->query("betrayer") > (int)ob->query("K_betrayer"))
     {
         command("heng");
         command("say �������������Ź棬���Ķ��⡣������������Ϊͽ��");
         return;
        }

    if ((int)ob->query("per") < 22 ) {
           command("giggle");
           command("say ��λ"+RANK_D->query_respect(ob)+"��ò̫Ҳ...������������ذɣ�");
           return ;
       }

    if ((int)ob->query_dex() < 26  && (int)ob->query_int() < 28 ) {       
           command("say ��λ"+RANK_D->query_respect(ob)+"�������ʲ���һ�㡣");
           command("say �����д���Ǳ���������Ȼ�ȥĥ��ĥ����");
           return ;
        }
    command("smile");
    command("recruit " + ob->query("id"));
//    if( (string)ob->query("class") != "swordsman");
//    ob->set("class","swordsman");
    ob->set("K_betrayer", (int)ob->query("betrayer") );
}
