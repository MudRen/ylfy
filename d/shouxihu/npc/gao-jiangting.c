#include <ansi.h>
inherit NPC;

void create()
{ 
    set_name(HIR"�����"NOR, ({"gao jiangting"}) );
    set("title", HIM"�޹Ǿ���" NOR);
    set("gender", "Ů��" );
    set("age", 20);
    set("long", "��ħ֮һ�ġ���ħ��,ͬʱҲ���������㷻������֮һ������ӯ¥�е����㡣���е��ġ��õ����󣬼��հ�ѹȺ���� �С��޹Ǿ��ҡ�֮����\n");
    //set("attitude", "aggressive");
    //et("class", "yuanling");
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
    set("jiali", 100000);
    //set("end_boss", 1);
    set_temp("apply/attack",  1050);
    set_temp("apply/defense", 2030);
    set("combat_exp", 2100000000);
    set("xyzx_sys/level", 10000);
    set("xyzx_sys/fanying", 200000);
    set("xyzx_sys/jingzhun", 200000);
    set("xyzx_sys/minjie", 200000);
    set("xyzx_sys/lingxing", 200000);
    set_skill("force", 50000); 
    set_skill("unarmed", 50000);
    set_skill("dodge", 50000);
    set_skill("parry", 50000);
	set_skill("sword", 50000);
    set_skill("yunshang-xinjing", 10000); 
    set_skill("ai-sword", 10000);
	set_skill("art", 10000);
    set_skill("music", 10000); 
    set_skill("shuiyue", 10000);
    map_skill("force", "yunshang-xinjing");
    map_skill("unarmed","music");
    map_skill("parry", "music");
	map_skill("sword", "ai-sword");
    map_skill("dodge", "shuiyue");
	set("chat_chance_combat", 100);
    setup();
    
    carry_object("/clone/cloth/pink_cloth")->wear();
    carry_object("clone/weapon/yuenv")->wield();
    add_money("gold", random(300));
}

