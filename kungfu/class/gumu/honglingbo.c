// honglingbo.c ���貨
// By Kayin @ CuteRabbit Studio 99-3-29 11:48 new 
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int do_look(string target);
string ask_zhen();
void create()
{
	set_name("���貨", ({ "hong ling bo", "hong" }));
	set("long",
		"����ɫ���� ��˫���κ죬����ˮ�����ġ����˿��˻��뿴��\n");
	set("gender", "Ů��");
	set("age", 17);
	set("attitude", "heroism");
	set("shen_type", 1);
	set("per",27);
	set("str", 26);
	set("dex", 35);
	set("con", 17);
	set("int", 25);

	set("shen",-5000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 50);

	set("combat_exp", 1000000);
	set("score", 8500);	
	
	set_skill("force",150);
	set_skill("yunv-xinfa",150);
	set_skill("literate",100);
	set_skill("meinv-quanfa",100);
	set_skill("wudu-shenzhang",100);
	set_skill("swsb-shou",100);
	set_skill("unarmed",100);
	set_skill("dodge",100);
	set_skill("whip",300);
	set_skill("xianyun-bufa",400);
	set_skill("throwing",400);
	set_skill("parry",300);

	map_skill("force","yunv-xinfa");
	map_skill("unarmed","wudu-shenzhang");
	map_skill("dodge","xianyun-bufa");
	map_skill("parry","swsb-shou");
	map_skill("whip","swsb-shou");
        set("inquiry", ([
	    "��Ī��":"������ʦ���������ʵı��ʣ�С���������㡣",	
	    "�ֳ�Ӣ" : "�����ҵ�ʦ�棬�������ʵ�����ʣ�С���������㡣",

	]));
	
	create_family("��Ĺ��", 4, "����");
	setup();
        carry_object("/clone/weapon/changjian")->wield();
           carry_object("/clone/cloth/cloth")->wear();

}
void attempt_apprentice(object ob)
{
        
	if ((int)ob->query("shen") > 100) {
		command("say " + RANK_D->query_respect(ob) + "���²����ݶ����Ҳ�������.");
		return;
	}
	if( (string)ob->query("gender") != "Ů��" )
	{
		command ("say �Բ��𣬱���ֻ��Ů���ӣ��㻹����Ͷʦ�ǰɡ�");
		return;
	}
	if( (int)ob->query_dex()< 20){
		command("say �����̫����ʺ�ѧ��Ĺ�ɵ��书.");
		return;
	}
	if( (int)ob->query_int() < 25){
		command("say �������̫����ʺ�ѧ��Ĺ�ɵ��书��");
		return;
	}
	if( (int)ob->query_int()< 20){
		command("say �㳤��̫���ˡ�");
		return;
	}
			
        	command("say �ðɣ��Ҿ��������ˡ�");
		command("recruit " + ob->query("id"));
		if( (string)ob->query("class") != "taoist")
		ob->set("class", "taoist");
}
