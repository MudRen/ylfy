
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void greeting(object);
void init();
void create()
{
	set_name("�ƻ�����ū", ({ "hua nu", "hua", "nu"}));
	set("long",
	    "���Ǹ���ò���˵�Ů��, ��������,\n"+
	    "�������, �������.\n"+
	    "���Ǿ�������.\n");
	set("gender", "Ů��");
	set("age", 18);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);

	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 500);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 20);

	set("combat_exp", 100000);
	set("score", 10000);
	set_skill("force", 170);
	set_skill("dodge", 180);
	set_skill("parry", 170);
	set_skill("sword",200);
	set_skill("unarmed",200);

	set_skill("jueqing-zhang",180);
	set_skill("mingyu-shengong",200);
	set_skill("yihua-jiemu",180);
	set_skill("yifeng-jian",180);

	map_skill("unarmed", "jueqing-zhang");
	map_skill("force", "mingyu-shengong");
	map_skill("dodge", "yihua-jiemu");
	map_skill("parry", "yihua-jiemu");
	map_skill("sword", "yifeng-jian");

	prepare_skill("sword","yifeng-jian");
	create_family("�ƻ���",3,"��ū");
	setup();
    carry_object("/d/yihua/obj/jinlvyi")->wear();
        carry_object("/clone/weapon/changjian")->wield();
	add_money("silver",15);
}

void init()
{
        object ob;
 
        ::init();
 
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
       if ((string)ob->query("family/family_name") == "�ƻ���") 
             {
               message_vision("��ū����$N���ͷ��΢΢Ц��Ц��\n",ob);
               return;
              }
        if (!(string)ob->query("family/family_name"))
             {
               message_vision("��ū����$N΢Ц˵���ƻ����Ĺ���������µ�һ��\n",ob);
               return;
              }
}

void attempt_apprentice(object ob)
{
   if ((string)ob->query("gender")=="Ů��")
   {
		message_vision("��ū��Ŀ��˼Ƭ��, ˵�������ð�, �Ҿ��������ˡ����������ù���֪��,��Ȼ�ҿɱ������㡱\n",ob);
       command("recruit " + ob->query("id"));
		if((string)ob->query("class") != "huanu")
			ob->set("class", "huanu");
       return;}
   else
      {
		message_vision("��ū�����㿴�˰���,˵�������ƻ������������е���,���ٽ��Ҿ�ȥ���߹���!��\n",ob);
       return;}
}
