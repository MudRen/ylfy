// jingxuan.c ����
// create by host dec,11
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("����", ({ "jing xuan", "jing", "xuan"}));
        set("long",
          "���Ƕ����ɴ�ʦ�㣬�������ʦ̫��ʮ���أ������ɵĻ��������Ѿ���������\n");
        set("gender", "Ů��");
        set("age", 40);
        set("attitude", "peaceful");
        set("nickname", HIY "��ʦ��" NOR);
        set("shen_type", 1);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("dex", 28);

        set("qi", 2300);
        set("max_qi", 2300);
        set("jing", 1500);
        set("max_jing", 1500);
        set("neili", 1800);
        set("max_neili", 1800);
        set("jiali", 40);

        set("combat_exp", 3850000);
        set("score", 100000);

        set_skill("force", 210);
        set_skill("dodge", 210);
        set_skill("parry", 220);
        set_skill("sword", 220);
        set_skill("linji-zhuang",210);
        set_skill("huifeng-jian",225);
        set_skill("zhutian-bu",210);
        set_skill("yugalism", 180);  
        set_skill("literate", 200);
        map_skill("dodge","zhutian-bu");
        map_skill("parry", "huifeng-jian");
        map_skill("sword", "huifeng-jian");
        map_skill("force","linji-zhuang");

        create_family("������", 4,"����");
        set("class","bonze");
        setup();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
  }

void attempt_apprentice(object ob)
 {
     
     object me;
     me = this_player();

     if ((string)ob->query("gender") != "Ů��" )
      {
        command("say ����ô�ܹ�������Ϊͽ�أ�");
       return;
      }
/*     if(!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "������")
	{
		command("say " + RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
		return;
	}  */
     if ((int)ob->query("shen") < 0)
        {
        command("say �Ҷ������������������ɣ��Ե���Ҫ���ϡ�");
        command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                 "�Ƿ����ò�����");
                return;
        }
    if ((int)ob->query_skill("linji-zhuang", 1) < 50) 
        {
		command("say " + RANK_D->query_respect(ob) + 
			"���ڹ�����Ƿ񻹲�����Ӧ�����ټ�ʮ��ׯ�϶��µ㹦��");
		return;
  	}       
    if( (string)me->query("class")=="bonze" )
       {
             command("nod");
             command("recruit " + ob->query("id"));
       }
     
      else {

                command("say �����ӷ����գ����գ�ʩ������������ҷ𣬿�ȥ���������ܽ䡣\n");
		return ;
            }

  }
