// jingkong.c ����
// create by host dec,11
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("����", ({ "jing kong", "jing", "kong"}));
        set("long",
        "���Ƕ�������ʦ�㣬�������ʲ������ߣ�ֻ�ô������ʦ̫��һ��ָ����\n");
        set("gender", "Ů��");
        set("age", 38);
        set("attitude", "peaceful");
        set("nickname", HIY "��ʦ��" NOR);
        set("shen_type", 1);
        set("str", 24);
        set("int", 26);
        set("con", 26);
        set("dex", 28);

        set("qi", 1600);
        set("max_qi", 1600);
        set("jing", 1000);
        set("max_jing", 1000);
        set("neili", 1300);
        set("max_neili", 1300);
        set("jiali", 40);

        set("combat_exp", 1750000);
        set("score", 100000);

        set_skill("force", 160);
        set_skill("dodge", 180);
        set_skill("parry", 180);
        set_skill("unarmed",170);
        set_skill("linji-zhuang",180);
        set_skill("zhutian-bu",180);
        set_skill("tiangang-zhi",180);
        set_skill("literate", 180);
        map_skill("dodge","zhutian-bu");
        map_skill("parry", "tiangang-zhi");
        map_skill("unarmed", "tiangang-zhi");
        map_skill("force","linji-zhuang");
        prepare_skill("unarmed", "tiangang-zhi");

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
    if ((int)ob->query("dex") < 26) 
        {
		command("say " + RANK_D->query_respect(ob) + 
			"������Ϊ���㣬��������ѧϰ������ָ����");
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
