inherit NPC;
void create()
{
      
        set_name("С����",({"hu zai"}));
	set("race", "Ұ��");
        set("long", "һֻ�ճ��������µ�С�ϻ�������ͬ�����˴���Ϸ��\n");
	set("age", 1);
	set("attitude", "peaceful");

	set("max_ging", 400);
	set("max_qi", 1400);

	set("str", 40);
	set("con", 150);

	set("limbs", ({ "ͷ��", "����", "β��" ,"��"}) );
	set("verbs", ({ "bite" }) );

	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_temp("apply/attack", 100);
	set_temp("apply/damage", 100);
	set_temp("apply/defense", 40);
	set_temp("apply/armor", 80);

	set("combat_exp", 200000);
 
        set_weight(20000);

	setup();
}
void init()
{
        object me;

        if (interactive(me = this_player()))
        {
      	       remove_call_out("kill_ob");
              call_out("kill_ob", 1, me);
        }
        ::init();
}