//����ɽ���ɡ�dhxy-evil 2000.7.5
// modified by vikee 2000.11
inherit NPC;

void create()
{
        set_name("��������", ({ "dragon", "long" }));
               set("title",HIB "�����ķ�������" +NOR);
        set("race","Ұ��");
        set("age", 999);
        set("attitude", "aggressive");
        set("str", 40);
        set("int", 25);
        set("con", 40);
        set("cor", 40);

		set("end_boss", 1);
		set("no_suck", 1);
        
        set("max_qi", 5000000);
        set("max_jing", 5000000);
        set("neili", 15000000);
		set("jingli", 15000000);
        set("max_neili", 3000);
		set("max_jingli", 3000);
        set("jiali", 3000);
        set("combat_exp", 2100000000);
        set("limbs", ({ "ͷ��", "����", "ǰצ", "β��", "��Ƥ", "��צ"}) );
        set("verbs", ({ "bite", "claw"}) );

        set_temp("apply/attack", 900);
		set_temp("apply/damage", 900);
		set_temp("apply/armor", 900);
		set_temp("apply/defence",900);
		set_skill("dodge", 5000);
		set_skill("unarmed", 5000);
		set_skill("dragon", 5000);
		set_skill("spells", 5000);
		set_skill("magic-old", 5000);
		map_skill("unarmed", "dragon");
		map_skill("dodge", "dragon");
		map_skill("spells", "magic-old");
		prepare_skill("unarmed", "dragon");
		set("chat_chance_combat", 50);
		set("chat_msg_combat", ({
			(: perform_action, "unarmed.yaoyao" :),
			(: perform_action, "unarmed.penhuo" :),
			(: perform_action, "unarmed.tuwu" :),
			(: perform_action, "spells.magic1" :),
			(: perform_action, "spells.magic2" :),
			(: perform_action, "spells.magic3" :),
			(: perform_action, "spells.magic4" :),
			(: perform_action, "spells.magic5" :),
			(: perform_action, "spells.magic6" :),
			(: perform_action, "spells.magic7" :),
			}) );
        setup();
}

