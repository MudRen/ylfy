// main.c �¼���

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
string ask_me();
string ask_ling();
int count=1;
void create()
{
	set_name("�¼���", ({ "chen jialuo", "chen" }));
	set("nickname", HIR "�仨��" NOR );
	set("long", 
		"���������������ĺ컨����ܶ����¼���\n"
		"��һ���ɸɾ�������ɫ���ۡ�\n"
		"����������ʮ���꣬����ݳ�������һ�ѳ������˲�������\n");
	set("gender", "����");
	set("age", 22);
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
set("max_qi", 500000);	
set("max_jing", 150000);	
set("neili", 5000000);	
	set("max_neili", 5000);
set("jiali",15000);	
set("combat_exp", 1500000000);   	
	set("score", 700000);

set_skill("force", 2100);	
set_skill("honghua-shengong", 850);	
set_skill("dodge", 2850);	
set_skill("youlong-shenfa", 850);	
set_skill("unarmed", 2850);	
set_skill("baihua-cuoquan", 850);	
set_skill("parry", 2850);	
set_skill("sword", 1500);	
set_skill("luohua-jian", 850);	
set_skill("literate", 2000);	

	map_skill("force", "honghua-shengong");
	map_skill("dodge", "youlong-shenfa");
	map_skill("unarmed", "baihua-cuoquan");
	map_skill("parry", "luohua-jian");
	map_skill("sword", "luohua-jian");

	create_family("�컨��", 2, "�ܶ���");

	set("inquiry", ([
		"�컨��" : (: ask_me :),
	]));

        

        set("chat_chance", 5);         // ����������� 25%
        set("chat_msg", ({
                "�¼���̾��һ����������....�벻��Ǭ¡�������ֵܣ��������Ǻã�\n",
                "�¼������˵�������Ǻ��˵Ľ�ɽ��һ��Ҫ���������ж����\n",
                "�¼���˵������λ�ֵܣ���Ҫ�������Ǻ컨����\n",
        }) );
set("chat_chance_combat", 100);  
        set("chat_msg_combat", ({
                "�¼���˵����������ң�׷�����ĺ����Ҷ�Ҫɱ���㣡\n",
(: perform_action, "sword.chan" :),	
(: perform_action, "sword.kuangda" :),	
(: perform_action, "sword.shisan" :),	
		(: exert_function, "recover" :),
                
        }) );

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();

}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("shen") <50000) {
		command("say �컨���н��Ǹ����ҵ��ĺú��ӣ�����С��Ҳ������ô��");
		command("say ��Ҫ����컨��" + RANK_D->query_respect(ob) +
			"����ȥɱ�����幷��˵��");
		return;
	}
        command("say ���¶�"+RANK_D->query_respect(ob)+
                "�������Ѿã��ӽ�������Ǿ���һ�����ˣ�");
	command("recruit " + ob->query("id"));
	if( (string)ob->query("class") != "taoist")
		ob->set("class", "taoist");
}
/*
void init()
{
        object ob;

        ::init();

        ob = this_player();

        if((int)ob->query("shen") < -1000 && ob->query("family/master_id")=="chen jialuo")
        {
                command("chat "+ob->query("name")+"!�����а���թ֮ͽ���������������ʦ����\n");
                command("expell "+ ob->query("id"));
                this_player()->set("title","�컨��" + RED + "��ͽ" NOR);
        }

        add_action("do_say", "say");
}
*/
int do_say(string arg)
{

	if( !arg || arg=="" ) return 0;
 
	if( arg=="��Ҷ�컨����ź") 
        
	{
		write("�¼���˵��������Ӣ����һ��\n");
		message("vision", "ԭ�����Լҵ��֣���֪�кμ��̣�\n", this_player());
		set("inquiry", ([
		"�컨��" : (: ask_ling :),
	
	]));

	}
}
string ask_me()
{
	
	return RANK_D->query_respect(this_player()) + ",�Һ컨�������µ�һ��ר���幷���ԣ���.��...";
        
}
string ask_ling()
{
        
  	object ob,me;
	if (count == 0) return "�컨���Ѿ�����ȥ�ˣ�\n";
	message_vision(HIR"�¼���˵��������Ҫ�컨���𣿣��Ƚ������У�\n"NOR,this_player());
	ob = this_object();
	me = this_player();
	COMBAT_D->do_attack(ob, me, query_temp("weapon") );
	COMBAT_D->do_attack(ob, me, query_temp("weapon") );
	COMBAT_D->do_attack(ob, me, query_temp("weapon") );

	me->set_temp("fighter", 1);
		
	ob->fight_ob(me);
	me->fight_ob(ob);

	command("halt");
		
        if (( (int)me->query("qi")*100 / (int)me->query("max_qi") ) >= 30 )
        {
			ob = new("/d/honghua/honghua-ling");
	        	ob->move(this_player());
		        count=0;
			return "�ã���֧�컨���ֵ���Ҫ�úñ��ܣ�\n";
			message_vision(HIY"�¼��彻��$Nһ֧�컨��!\n"NOR,me);
		}
	else
		
			return "�������书�����ƹܺ컨�";	
}
