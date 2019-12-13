// /NPC lianxin.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("����", ({ "lian xing", "lian", "xing" }));
	set("long",
	    "�����ǡ��ƻ������Ŀ�ɽ��ʦ.\n"+
	    "���ñ�������ɴ������,����͸���ǿ���ɴ����Ȼ��ϡ�ɼ�\n"+
	    "����ɫɷ��,�Բ����˼����˿�����,�㲻�ɵö࿴��һ��.\n");
	set("title", "�ƻ���������");
	set("gender", "Ů��");
	set("age", 36);
	set("shen_type",0);
	set("attitude", "peaceful");

     set("str", 1350);
	set("int", 250);
	set("con", 300);
	set("dex", 200);

	set("qi", 4500000);
	set("max_qi", 4500000);
	set("jing", 1500000);
    set("max_jing", 1500000);
    set("neili", 90000000);
    set("max_neili", 300000); 	
    set("jiali", 30000);	
    set("combat_exp", 600000000);
	set("xyzx_sys/level", 2000);
	
	set("score", 2000000);
	set_skill("force", 3850);
	set_skill("unarmed", 3850);
	set_skill("dodge", 3700);
	set_skill("parry", 3750);
	set_skill("sword",3850);
    set_skill("literate", 2900);
	set_skill("jueqing-zhang",1750);
	set_skill("mingyu-shengong",1750);
	set_skill("yifeng-jian",1750);
    set_skill("yihua-jiemu",1700);

	map_skill("force", "mingyu-shengong");
	map_skill("unarmed", "jueqing-zhang");
	map_skill("dodge", "yihua-jiemu");
	map_skill("parry", "yihua-jiemu");
    map_skill("sword","yifeng-jian");

	create_family("�ƻ���",1, "���ǹ���");
    set("chat_chance_combat", 100);	
	set("chat_msg_combat", ({
		(: perform_action, "sword.yifeng" :),
		(: perform_action, "parry.yi" :),
			}) );
	setup();
	carry_object("/clone/weapon/changjian")->wield();
    carry_object("/d/yihua/obj/jinlvyi")->wear();
       
}

void attempt_apprentice(object ob)
{
   
   if ((string)ob->query("gender")!="Ů��")
           {
 		command("heihei");
                command("chat �ҽ��ƽ�����������ˣ��������ҽ������ɱ�ˣ��������Ұ����ɱ��,������!");
                kill_ob(this_player());
                command("perform yifeng");
		return;
	   }
   if ((int)ob->query_skill("dodge", 1) < 100) 
           {
		command("say " + RANK_D->query_respect(ob) + "���������!");
		return;
	   }
   if ((int)ob->query_skill("mingyu-shengong", 1) < 330) 
           {
		command("say " + RANK_D->query_respect(ob) + "�Ƿ�Ӧ�ö�����ڤ���񹦣�");
		return;
	   }
   if ((int)ob->query_skill("yifeng-jian", 1) < 130) 
           {
		command("say " + RANK_D->query_respect(ob) + "�Ƿ�Ӧ�ö������Ʒ罣����");
		return;
	   }
   if (ob->query_per() < 19) 
      	   {
		command("say ƾ����ģ���������Ϊʦ.");
		return;
	   }
   if (ob->query_con() < 40) 
      	   {
		command("say ���Ź�����Ϊ����,��ĸ����ƺ�����.");
		return;
	   }
   command("recruit " + ob->query("id"));
   if((string)ob->query("class") != "chuanren")
     ob->set("class", "chuanren");
   return;
}

void init()
{
	object ob;

	::init();

	ob = this_player();

	if (interactive(ob) && (!ob->query("gender") || ob->query("gender")!="Ů��"))
	{
			command("heihei");
			command("say �ҽ��ƽ�����������ˣ��������ҽ������ɱ�ˣ��������Ұ����ɱ��,�����ɣ�\n");
			remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob); 
                        command("perform yifeng");
	}
	else if(ob->query("gender")=="Ů��")
	{
	command("smile");
	command("say �����㲻�����˲�Ȼ������úܲҡ�");
	}
}
