// xiaoyaozi.c ��ң��
// shilling 97.2

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name("��ң��", ({ "xiaoyao zi", "xiaoyao","zi" }));
       set("title", "��ң�ɿ�ɽ��ʦ");
       set("long", 
               "��������ң�ɿ�ɽ��ʦ��������Ϊ��ң������һ���ڽ�����\n"
               "�����ܽ��ɣ��������ڽ����в��Ǻܶ���֪��������ʵ����\n"
               "����ȴ�ǡ���������������Ѯ��������⣬��ü�԰ס�\n");
       set("gender", "����");
       set("age", 75);
       set("shen_type", 1);
       set("str", 40);
       set("int", 40);
       set("con", 40);
       set("dex", 40);
       set("per", 40);
       
       set("max_qi", 5500);
       set("max_jing", 3000);
       set("neili", 3000);
       set("max_neili", 3000);
       set("jingli", 2000);
       set("max_jingli", 2000);
       set("jiali", 100);
       set("combat_exp", 15000000);
       set("score", 200000);

      set_skill("force", 500);
      set_skill("beiming-shengong", 500); 
       set_skill("dodge", 550);   
      set_skill("lingboweibu", 550);   
       set_skill("unarmed", 500);    
       set_skill("liuyang-zhang", 480);   
       set_skill("parry", 500);   
       set_skill("blade", 500);   
       set_skill("ruyi-dao", 480);   
       set_skill("zhemei-shou", 550);   
//     set_skill("hand", 200);
      set_skill("literate", 600);

       map_skill("force", "beiming-shengong");
       map_skill("dodge", "lingboweibu");
       map_skill("unarmed", "zhemei-shou");
//     map_skill("strike", "liuyang-zhang");
       map_skill("parry", "ruyi-dao");
       map_skill("blade", "ruyi-dao");

//     prepare_skill("hand","zhemei-shou");
//     prepare_skill("strike","liuyang-zhang");

       create_family("��ң��", 1, "��ɽ��ʦ");
       set("class", "taoist");

       setup();
}

void attempt_apprentice(object ob)
{
       if ((int)ob->query_skill("beiming-shengong", 1) < 80) {
               command("say ����ң���ڹ���ԴȪ�����ڱ�ڤ�񹦵��ķ���"); 
               command("say " + RANK_D->query_respect(ob) + 
                       "�ı�ڤ���Ƿ�Ӧ��������߰���");
               return;
       }

       if (ob->query_int() < 35) {
               command("say ����ң���书�����ӡ���ң�����֡�");
               command("say ����ν����ң������ֻ�ܿ����Լ�ȥ����");
               command("say ����" + RANK_D->query_respect(ob) + "�������ƺ����д���߰���");
               return;
       }
       command("smile");
       command("say �벻���������Ͼ�Ȼ�����˿��Լ̳��ҵ���ң�ķ���");
       command("recruit " + ob->query("id"));
       ob->set("title","��ң�ɻ���ʹ��");
}

