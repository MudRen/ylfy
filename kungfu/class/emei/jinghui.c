// jinghui.c ����
// create by host dec,11
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("����", ({ "jing hui", "jing", "hui"}));
        set("long",
           "���Ƕ�������ʦ�㣬ֻ��������˸˸���񣬲�ͣ��ɨ�������ܡ���\n");
        set("gender", "Ů��");
        set("age", 38);
        set("attitude", "peaceful");
        set("nickname", HIY "��ʦ��" NOR);
        set("shen_type", 1);
        set("str", 27);
        set("int", 24);
        set("con", 27);
        set("dex", 24);

        set("qi", 1500);
        set("max_qi", 1500);
        set("jing", 800);
        set("max_jing", 800);
        set("neili", 1200);
        set("max_neili", 1200);
        set("jiali", 40);

        set("combat_exp", 3080000);
        set("score", 100000);

        set_skill("force", 210);
        set_skill("dodge", 200);
        set_skill("parry", 210);
        set_skill("blade",220);
        set_skill("linji-zhuang",200);
        set_skill("zhutian-bu",200);
        set_skill("yanxing-dao",220);
        set_skill("literate", 180);
        map_skill("dodge","zhutian-bu");
        map_skill("parry", "yanxing-dao");
        map_skill("blade", "yanxing-dao");
        map_skill("force","linji-zhuang");

        create_family("������", 4,"����");
        set("class","bonze");
        setup();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/gangdao")->wield();
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
     if ((int)ob->query("shen") < 0)
        {
        command("say �Ҷ������������������ɣ��Ե���Ҫ���ϡ�");
        command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                 "�Ƿ����ò�����");
                return;
        }
    if ((int)ob->query("str") < 25 && (int)ob->query("con") < 25 ) 
        {
		command("say " + RANK_D->query_respect(ob) + 
			"����̫������ñ��Ź��������ɡ�");
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
