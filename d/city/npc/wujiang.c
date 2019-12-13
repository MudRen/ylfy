// wujiang.c �佫
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("�佫", ({ "wu jiang", "wu", "jiang" }));
	set("gender", "����");
	set("age", random(10) + 30);
	set("str", 25);
	set("dex", 16);
	set("long", "��վ�������ȷ��˵���������硣\n");
	set("combat_exp", 500000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set_skill("unarmed", 120);
	set_skill("force", 120);
	set_skill("sword", 120);
	set_skill("dodge", 120);
	set_skill("parry", 120);
	set_temp("apply/attack", 90);
	set_temp("apply/defense", 90);
	set_temp("apply/armor", 90);
	set_temp("apply/damage", 50);
	set("neili", 1000); 
	set("max_neili", 1400);
	set("jiali", 10);
	setup();
    carry_object("/clone/weapon/gangjian")->wield();	
    carry_object("/clone/armor/tiejia")->wear();	
}
void init()
{
	object ob;
	::init();
	if (!living(this_object()))	return;
	if (interactive(ob = this_player())){ 
		if((int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
	if( ob->query_temp("illicit") ){
			command("look "+ob->query("id"));
			command("say "+RED"�ø����ɣ���ο��������ӣ�\n"NOR);
			remove_call_out("kill_ob");
			call_out("kill_ob", 3, ob);
		}}
	add_action("do_kill","kill");
	add_action("do_kill","hit");
}
int do_kill(string arg)
{
	call_out("kill",1,arg,this_player());
	return 0;
}
int kill(string arg,object obj)
{
	object ob;
	int i;
	if (!obj)
		return	0;
	if (environment(obj)!=environment())
		return 0;
	if (this_object()->id(arg)){
	command("say ���ܣ�����������·�� �ֵ��ǣ��ϣ�");
	for(i=0; i<4; i++) {
                if( objectp( ob = present("guan bing", environment(this_object())) ) )
                     if (!ob->is_killing(this_player()))
				 ob->kill_ob(this_player());	
	}
	}
	return 0;
}
int accept_object(object who, object ob)
{
      string nature;
     nature=NATURE_D->room_event_fun();
    if( nature=="event_dawn"||nature=="event_night"||nature=="event_midnight") {
     if (ob->query("money_id") && ob->value() >= 100000/(int)who->query("kar")){
        message_vision(name()+"����"+ob->name()+"�����е��˵࣬��$N˵������"+RANK_D->query_rude(who)+"����ʶ�࣬��ȥ�ɡ�\n",who);
        who->set_temp("paid_money_bing",1);
        return 1;
        }
    else
        message_vision(name()+"����"+ob->name()+"�����е��˵࣬��$N���������"+RANK_D->query_rude(who)+"����ô��Ǯ����򷢱������������\n", who);
        return 0;
    }
   else {
        message_vision(name()+"����"+ob->name()+"�����е��˵࣬������Ц��$N˵������"+RANK_D->query_rude(who)+"������Ե�޹��ͱ�����\n��ô��Ǯ������ʱ�������š�\n",who);
         return 1;
     }
}
