
inherit NPC;
#include <ansi.h>
void create()
{
	set_name("����", ({ "a fei"}) );
	set("gender", "����" );
    set("title", HIG "��Ϊ����" NOR);
    set("class", "jianxia");	
	set("age", 20);
	set("int", 30);
	set("per", 30);
	set("int", 30);
	set("long","�����޵У���������\n");
    set("force_factor", 200);
    set("nickname",RED"ħ��"NOR);	
	set("no_suck",1);
	set("is_boss", 1);
    set("combat_exp", 1500000000);
    set("xyzx_sys/level", 30000);	   
    set("score", 90000);
    
    set("max_neili",100000000);  	
    set("neili",150000000);  	
    set("max_jingli",500000);  	 	
    set("jingli",400000);  	
    set("max_jing",50000000);  	
    set("max_qi",100000000);  	
    set("shen",300000000);
    set("jiali",500000);  	
    
    set_skill("sword", 4000);
    set_skill("unarmed", 4000);	
    set_skill("force", 4000);	
    set_skill("parry", 4000);
    set_skill("literate", 3000);
    set_skill("dodge", 4000);
	
    set_skill("lonely-sword", 10000);
    set_skill("piaomiao-shenfa", 1500);        	
    set_skill("zhentian-quan", 1500);            	
    map_skill("dodge", "piaomiao-shenfa");     	
    map_skill("unarmed", "zhentian-quan");         	
    map_skill("sword", "lonely-sword");	
    map_skill("parry", "lonely-sword");
	
	create_family("ʥ��ħ��", 5, "����");	
    set("chat_chance_combat", 300);
    set("chat_msg_combat", ({
       (: perform_action, "sword.jiushi" :),	
       (: perform_action, "sword.zongjue" :),	
       (: perform_action, "sword.pozhao" :),  	
       (: perform_action, "sword.pojian" :),	
       (: perform_action, "sword.podao" :),	
       (: perform_action, "sword.pobian" :),	
       (: perform_action, "sword.poqi" :),	
       (: perform_action, "sword.pozhang" :),	
        }) );
	setup();
	    carry_object("clone/cloth/cloth")->wear();
        carry_object(__DIR__"obj/toysword")->wield();
}
int accept_fight(object me)
{
        command("grin");
        command("say �ҵĽ�������ɱ�˵ģ����������Ȼ�����ģ�");
        return 0;
}
void init()
{
	add_action("do_killing", "kill");
}

int do_killing(string arg)
{
	
	object player, victim;
	string name;
	player = this_player();
	if( !arg) return 0;
	if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
	{
		name = (string)victim->name();
		if( (string)name == "���ɶ�")
		{
		message_vision("$N��Цһ�������ҿ�����̫���ˡ�\n", this_object());
		this_object()->kill_ob(player);
		player->kill_ob(this_object());
		return 1;
		}
	}
	return 0;		
}
void attempt_apprentice(object ob)	
{
if((int)ob->query("shen",1) < 150000000)               	
{
command("say �ҵĽ���ֻ��������ʿ�����ڵ��з��滹���ò����ɡ�");	
return 0;	
}
command("say �ðɣ��Ҿ������������ˣ��Ժ�Ҫ����������塣");	
command("chat �ҵľ����������д����ˣ��������ֶ���λ��������Ĵ���������.....");	
command("recruit " + ob->query("id"));	
ob->set("class","jianxia");                  	
}
