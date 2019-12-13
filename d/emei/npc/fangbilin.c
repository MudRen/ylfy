// fangbilin.c ������
// create by host dec,16 1997

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("������", ({ "fang bi lin", "fang", "bilin"}));
        set("long",
      "����һλ�����ɵ��׼�Ů���ӣ�ר�Ź���һЩ�������\n");
        set("gender", "Ů��");
        set("age", 25);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);

        set("qi", 400);
        set("max_qi", 400);
        set("jing", 300);
        set("max_jing", 300);
        set("neili", 400);
        set("max_neili", 400);

        set("combat_exp", 9000);
      
        set_skill("force", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_skill("strike",40);
      
        create_family("������", 5,"����");
        setup();
        carry_object("/clone/cloth/cloth")->wear();
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
	if( !ob || environment(ob) != environment() ) return;

	say("������Ц������˵������λ" + RANK_D->query_respect(ob) + "����������" + "����͸����ϲ衣\n");
}

void serve_tea(object who)
{
	object obn;
	object room;

	if( !who || environment(who) != environment() ) return;

	if( !who->query_temp("marks/sit") ) return;
	
	if( !objectp(room = environment()) ) return;

 	obn = new("d/wudang/obj/xiangcha");
	obn->move(who);
	message_vision("�����ն˳���һ�����µ�С��������˱���裬�������ϡ�\n",who);

 	obn = new("d/wudang/obj/mitao");
	obn->move(who);
	message_vision("�������ó�һ�����ʵ�ˮ���ң��������ϣ�\n", who);
	
	return;
}
void attempt_apprentice(object ob)
{
   command("shake");  
   command("say Ҫ��ʦѧ�գ��㻹���Ҵ�ʦ�㱴���ǰɣ�\n");
                return;
 }
