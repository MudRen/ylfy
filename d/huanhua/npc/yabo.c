
// yabo.c �Ʋ�
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�Ʋ�", ({ "ya bo", "bo" }));
        set("long", 
                "���Ǹ���Լ6���������ˣ�����һ�������£���������������ϸ�ĵ�ɨ�ŵء�\n"
		"����ɨ����һ�ֺ�ΰ��Ĺ����Ƶġ�\n");
	set("gender", "����");
	set("age", 58);
	set("attitude", "heroism");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
set("max_qi", 55000);
set("max_jing", 35000);
set("neili", 4000000);
	set("max_neili", 4000);
set("jiali", 1000);
set("combat_exp", 80000000);
	set("score", 30000);

set_skill("force", 700);
set_skill("unarmed",700);
set_skill("dodge", 700);
set_skill("parry",700);
set_skill("sword", 700);
set_skill("literate", 200);
set_skill("strike",700);
set_skill("huanhua-jian",700);
set_skill("tiexian-quan",770);
set_skill("guiyuan-dafa",700);	
set_skill("feihua-wuping",700);

	 map_skill("force","guiyuan-dafa");
	 map_skill("unarmed","tiexian-quan");
	 map_skill("sword","huanhua-jian");
	 map_skill("dodge","feihua-wuping");



set("chat_chance_combat", 300);
	set("chat_msg_combat", ({
(: perform_action, "sword.snow" :),
		(: perform_action, "sword.zhenjian" :),
	}) );

	setup();
carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();
		set("chat_chance",5);
	set("chat_msg",({
	    "�Ʋ��������е�ɨ�㣬���˴����������ˣ���ͷҲ���ˡ���\n",
	    "�Ʋ�̧ͷ���˿���̾�˿�������ү��֪��ʲôʱ��Ż�����\n",
	    "�Ʋ�������˵��������ɲ���һ��ı������������˵á���\n"
	   }) );
 
}

