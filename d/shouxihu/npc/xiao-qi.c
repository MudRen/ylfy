#include <ansi.h>
inherit NPC;

void create()
{ 
    set_name(HIR"С��"NOR, ({"xiao qi"}) );
    set("title", HIM"����" NOR);
    set("gender", "Ů��" );
    set("age", 15);
    set("long", "���ı������˵�֪���ݽ������ԣ�С�߱��Ǹ�ĸ������Ӥ����"              
				"����������֮�б��������������֣�����ԭ�����أ��������佥��֮��"
				"�������Լ��ڻ�Ұ�ĸ�ĸ����֮����Ը���ã�����ͬ�Ž�������������\n");
    //set("attitude", "aggressive");
    //set("class", "yuanling");
    set("str", 150);
    set("con", 150);
    set("int", 150);
    set("dex", 150);
	set("per", 150);
	set("no_get", 1);
    set("max_qi", 100000000);
    set("qi", 100000000);
    set("max_jing", 50000000);
    set("jing", 50000000);
    set("neili", 300000000);
    set("max_neili", 13000000);
    set("jingli", 30000000);
    set("max_jingli", 3000000);
    set("no_suck", 1);
    set("jiali", 150000);
    //set("end_boss", 1);
    set_temp("apply/attack",  950);
    set_temp("apply/defense", 530);
    set("combat_exp", 2100000000);
    set("xyzx_sys/level", 13000);
    set("xyzx_sys/fanying", 370000);
    set("xyzx_sys/jingzhun", 370000);
    set("xyzx_sys/minjie", 370000);
    set("xyzx_sys/lingxing", 370000);
    set_skill("force",50000); 
    set_skill("unarmed", 50000);
    set_skill("dodge", 50000);
    set_skill("parry", 50000);
    set_skill("blade", 50000);
	set_skill("sword", 50000);
    set_skill("demon-blade", 15000);
    set_skill("yunshang-xinjing", 15000); 
    set_skill("liuyin-guimai", 15000);
    set_skill("ai-sword", 15000); 
    set_skill("shuiyue", 15000);
    map_skill("force", "yunshang-xinjing");
    map_skill("unarmed","liuyin-guimai");
    map_skill("parry", "ai-sword");
	map_skill("sword", "ai-sword");
    map_skill("blade", "demon-blade");
    map_skill("dodge", "shuiyue");
	set("chat_chance_combat", 100);
   /* set("chat_chance", 1);
    set("chat_msg", ({
                "ÿ���˵�һ����ʵ����һ��Զ�У��ҡ����ڴ��������õ�ʱ���и�����̤���ĺ���û���ź����಻��ڡ�\n",               
        }) );*/
    setup();
    
    carry_object("/clone/cloth/pink_cloth")->wear();
    carry_object("clone/weapon/yuenv")->wield();
    add_money("gold", random(300));
}

