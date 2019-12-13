// sunpopo.c ������
// By Kayin @ CuteRabbit Studio 99-3-29 11:48 new 
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int ask_in();

void create()
{
	set_name("������", ({ "sun popo", "sun" }));
	set("long",
		"����һ���Ͱ����׵������ţ�һ��������Ƥ���ĳ���,�����֮��ȴ���ʴ�����֮��.\n");
	set("gender", "Ů��");
	set("age", 56);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	
	set("max_qi", 800);
	set("max_jing", 300);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 25);

	set("combat_exp", 1500000);
	set("score", 8500);	
	
	set_skill("force",110);
	set_skill("yunv-xinfa",110);
	set_skill("literate",90);
	set_skill("meinv-quanfa",100);
	set_skill("tianluo-diwang",100);
	set_skill("sword",120);
	set_skill("yunv-jianfa",120);
	set_skill("unarmed",100);
	set_skill("dodge",150);
	set_skill("xianyun-bufa",150);
	set_skill("throwing",100);
	set_skill("parry",90);

	map_skill("force","yunv-xinfa");
	map_skill("unarmed","meinv-quanfa");
	map_skill("sword","yunv-jianfa");
	map_skill("dodge","xianyun-bufa");
	map_skill("parry","yunv-jianfa");
        set("inquiry", ([
	"��Ĺ":(: ask_in :),
	"����Ĺ":(: ask_in :),
	"С��Ů":"�Դ��Ǵ��Ժ�����û�л�������������˵����������ɽ�ϼ�������\n",
	]));
	
	create_family("��Ĺ��", 4, "����");
	setup();
	carry_object("/clone/weapon/changjian")->wield();
          carry_object("/clone/cloth/cloth")->wear();

}
void attempt_apprentice(object ob)
{
        mapping myfam;
        if(ob->query_temp("gumu/��1",1))
        {
        	command("say �ðɣ��Ҿ��������ˡ�");
        	command("say ���Ժ������ask sun about ��Ĺ��ask sun about ����Ĺ,�����ҽ����Ĺ��");
		command("recruit " + ob->query("id"));
		ob->delete_temp("gumu/��1");
        }
        else
        {
	if ((int)ob->query("shen") < 0) {
		command("say ��Ĺ���Ѿ�����һ��ħͷ���Ҳ�Ը�ù�Ĺ����������·�����");
		command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
			"�Ƿ����ò�����");
		return;
	}
	if( (string)ob->query("gender") != "Ů��" )
	{
		command ("say �Բ��𣬱���ֻ��Ů���ӣ��㻹����Ͷʦ�ǰɡ�");
		return;
	}
	if( (int)ob->query_kar()< 20){
		command("say ������Ե���㻹����Ѱȥ���ɡ�");
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
	if( (int)ob->query_int()< 25){
		command("say �����ò���������ǹ����ǲ�������ġ�");
		return;
	}
	 myfam = (mapping)ob->query("family");
        if(myfam && myfam["family_name"] == "��Ĺ��")
        if(ob->query("class")=="taoist")
		{
			command("say ���Ѿ����Ǹ���ͽ�ĵ�����,���������ʲô?");
			return;
		}
	command("say ���Լ������ȥ��ʦ�����ŵĻ���ɡ�");
	ob->set_temp("marks/��ʦ",1);
	ob->move("/d/gumu/xiaoss1");
}
}
int ask_in()
{
	object me=this_player(1);
	mapping myfam;
	 myfam = (mapping)me->query("family");
        if(myfam && myfam["family_name"] == "��Ĺ��")
            {
            	if(me->query("class")==!"taoist")
            	{
            		command("say ��ȥ��.\n");
            		me->move("/d/gumu/dating");
            		return 1;
            	}
            	else
            	{
            		command("say ���Ѿ����ǹ�Ĺ�ɵĵ�����,�������ȥ.\n");
            		return 1;
            	}
        }
        else
        {
        	command("say �㲻�ǹ�Ĺ�ɵ���,�Ҳ��������ȥ.\n");
        }
}

            
