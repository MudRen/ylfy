// jingxu.c ����
// create by host dec,11
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("����", ({ "jing xu", "jing", "xu"}));
        set("long",
          "���Ƕ����ɶ�ʦ�㣬�������¶��꣬һ�׶����Ʒ�������������\n");
        set("gender", "Ů��");
        set("age", 40);
        set("attitude", "peaceful");
        set("nickname", HIY "��ʦ��" NOR);
        set("shen_type", 1);
        set("str", 27);
        set("int", 25);
        set("con", 27);
        set("dex", 25);

        set("qi", 2000);
        set("max_qi", 2000);
        set("jing", 1000);
        set("max_jing", 1000);
        set("neili", 1700);
        set("max_neili", 1700);
        set("jiali", 40);

        set("combat_exp", 3000000);
        set("score", 100000);

        set_skill("force", 210);
        set_skill("dodge", 200);
        set_skill("parry", 220);
        set_skill("unarmed",220);
        set_skill("linji-zhuang",210);
        set_skill("zhutian-bu",200);
        set_skill("jinding-zhang",220);
        set_skill("yugalism", 180);  
        set_skill("literate", 180);
        map_skill("dodge","zhutian-bu");
        map_skill("parry", "jinding-zhang");
        map_skill("unarmed", "jinding-zhang");
        map_skill("force","linji-zhuang");
        prepare_skill("unarmed", "jinding-zhang");

        create_family("������", 4,"����");
        set("class","bonze");
        setup();
        carry_object("/clone/cloth/cloth")->wear();
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
    if ((int)ob->query("str") < 26) 
        {
		command("say " + RANK_D->query_respect(ob) + 
			"�ı������㣬�����޷��������ߵ��Ʒ���");
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
