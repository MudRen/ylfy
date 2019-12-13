// ma.c
#include "/quest/quest.h"
#include <ansi.h>
inherit NPC;

string ask_me(object who);

void create()
{
        set_name("����", ({ "ma jingzhong","ma" }) );
        set("title", "佻������ܹ�");
        set("gender", "����" );
        set("age", 56);

        set("str", 22);
        set("int", 26);
        set("per", 23);
        set("kar", 25);
        set("con", 23);
        set("dex", 23);
        set("long",
                
"���ճ������磬�������еĴ�С���񶼺���Ϥ��\n"
"�����е��¿�û���������ù�����\n");

set("combat_exp", 80000000);	
        set("attitude", "friendly");
set("max_qi",50000);
set("max_jing",50000);
        set("env/wimpy", 30);

        set("max_neili", 1000);  
set("neili", 1000000);      
set("jiali", 2000);	

set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "sword.zhenjian" :),
(: perform_action, "sword.snow" :),
                }) );
set_skill("cuff", 1000);
set_skill("strike",1000);
set_skill("force", 1000);
set_skill("dodge", 1000);
set_skill("parry", 1000);
set_skill("sword", 1000);
set_skill("literate",1000);
set_skill("unarmed",1000);
set_skill("huanhua-jian",1000);
set_skill("tiexian-quan",1000);
set_skill("guiyuan-dafa",1000);
set_skill("feihua-wuping",1000);

	 map_skill("force","guiyuan-dafa");
	 map_skill("unarmed","tiexian-quan");
	 map_skill("sword","huanhua-jian");
	 map_skill("dodge","feihua-wuping");
	
/*
	 set("chat_chance",30);
         set("chat_msg",({
         "��������������������ϵ��¡����ٺ�\n",
         "���մ�Ц����˭�ܹ����ù��ҵ��۾���\n",
          }));
*/

        create_family("佻�����", 3, "����");
      
        setup();
        
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();

        add_money("gold", 10);
}

/*
void init()
{
	add_action("do_where", "where");
}

*/
int do_where(string arg)
{
	object ob,me,where;
	mapping fam;
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "佻�����")
		{command( "say �㲻�Ǳ��ɵ��ӣ��Ҳ��ܸ����㡣");return 1;}
		
	if(!arg || arg=="") {
		command("say ������˭��");
		return 1;
	}
	me=this_player();
	ob = find_player(arg);
	if( !ob ) ob = find_living(arg);
	if (!ob) {
		command("say ����û�����.");
		return 1;
	}
	where = environment(ob);
	if (!where) {
		command("say ����˲�֪��������Ү...");
		return 1;
	}
	printf(CYN"���������룬˵����%s(%s)������%s.\n"NOR,
		(string)ob->name(),
		(string)ob->query("id"),
		(string)where->query("short"));
	return 1;
}

