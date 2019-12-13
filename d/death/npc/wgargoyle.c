// wgargoyle.c
#include <ansi.h>
#include <command.h>
#include <login.h>
inherit NPC;
int ask_me();

int is_ghost(){	return 1;}
string *death_msg = ({
	HIW "���޳�˵����ι�������ģ����ʲô���֣�\n\n" NOR,
	HIW "���޳���������۹ⶢ���㣬����Ҫ�������һ���Ƶġ�\n\n" NOR,
	HIW "���޳����ߡ���һ�����������ͳ�һ�����ʲ�Ķ�����������\n\n" NOR,
	HIW "���޳����ϲ��ӣ�˵�����ף�����δ������ô���ܣ�\n\n" NOR,
	HIW "���޳�ɦ��ɦͷ��̾�������˰��ˣ����߰ɡ�\n\n"
		"һ�������Ũ��ͻȻ���֣��ܿ�ذ�Χ���㡣\n\n" NOR,
});
void create()
{
	set_name("���޳�", ({ "white gargoyle", "gargoyle" }) );
	set("long",
		"���޳�������������ͷ�����㣬���׵����Ͽ������κ�ϲŭ���֡�\n");
	set("attitude", "peaceful");
	
	set("age", 217);
	set("no_die",1);
	set("end_boss",1);
    set("xyzx_sys/level", 30000000);
	set("str", 5000000);
    set("con", 5000000);
    set("int", 5000000);
    set("dex", 5000000);
	set("no_get", 1);
    set("max_qi", 5000000000);
    set("qi", 5000000000);
    set("max_jing", 5000000000);
    set("jing", 5000000000);
    set("neili", 3000000000);
    set("max_neili", 300000000);
    set("jingli", 3000000000);
	set("jiali", 30000000);
    set("max_jingli", 300000000);
	set_temp("apply/attack",  12150);
    set_temp("apply/defense", 12130);
	set_skill("dodge", 400000);
	set_skill("unarmed", 400000);
	set_skill("dodge", 400000);
	set_skill("force", 400000);
	set_skill("parry", 400000);
	set_skill("sword", 400000);
	set_skill("tianmo-jian", 400000);
	set_skill("piaomiao-shenfa", 400000);
	set_skill("tianmo-quan", 400000);
	set_skill("tianmo-shengong", 400000);
	map_skill("parry", "tianmo-jian");	
    map_skill("force", "tianmo-shengong");           	
    map_skill("dodge", "piaomiao-shenfa");           	
    map_skill("unarmed", "tianmo-quan");
    map_skill("sword", "tianmo-jian"); 	
	set("chat_chance", 15);
	set("chat_msg", ({
		"���޳�����һ����������������������������ע��������ʱ�򣬵�����һ�ۡ�\n",
		"���޳��ѳ�������ͷ��������������������Լ��ְ��ֳ�����ָ��\n",
	}) );
	set("inquiry", ([
		"��ħ����"       : (: ask_me :),
	]));
	setup();
	
	carry_object("/clone/weapon/yuenv")->wield();
    carry_object("/clone/cloth/cloth")->wear();
}
void init()
{
	::init();
	call_out( "death_stage", 5,this_player(), 0 );
}
void death_stage(object ob, int stage)
{
	int i, lvl;
        object *inv,me;
	me = this_player();
	if( !ob || !present(ob) ) return;
	if( !ob->is_ghost() ) {
		command("say ι��������������ʲô��");
		kill_ob(ob);
		ob->fight_ob(this_object());
		return;
	}
	tell_object(ob, death_msg[stage]);
	if( ++stage < sizeof(death_msg) ) {
		call_out( "death_stage", 5, ob, stage );
		return;
	} else
		ob->reincarnate();
	
    inv =  all_inventory(ob);
    for (i = 0; i < sizeof(inv); i++)
	{
		if ( intp(lvl=inv[i]->query("bind_master_level/"+ob->query("id"))) 
			&& lvl>1 ) continue; 
        DROP_CMD->do_drop(ob, inv[i]);
	}
ob->clear_condition();
ob->clear_condition(1);	
if(ob->query("block"))
ob->move("/clone/misc/block");
else    ob->move(REVIVE_ROOM);	
ob->delete_temp("last_damage_from");
ob->delete_temp("die_for");
ob->set("startroom","/d/city/wumiao");
	message("vision",
		"���Ȼ����ǰ�����һ����Ӱ����������Ӱ�ֺ����Ѿ�������\n"
		"�ܾ��ˣ�ֻ����һֱû������\n", environment(ob), ob);
	
}
int ask_me()
{
        mapping my_fam;
 
        object  me;
        int my_age, already_age;
	me = this_player();
        my_fam = (mapping)me->query("family");
	my_age = me->query("age");
	already_age = (int)me->query("already_age");
//            if (my_fam["family_name"] != "ؤ��")	
if (me->query("class",1) != "beggar")
		return notify_fail("�㲻��ؤ��ĵ��ӣ�������ħ���塣\n");
	if( already_age >= my_age)
		return notify_fail("��������ħ��������Ѿ������ˣ�\n");
	if( (int)me->query("max_neili") < 50)
		return notify_fail("����������������ħ����󷨣�\n");
	if(random(5) >= 2)
	{
                me->set_skill("force",me->query_skill("force",1)+10);
		me->add("con_improve_time", 1);
		me->add("max_neili", -50);
		me->set("already_age", my_age);
	        message_vision(HIY"ֻ�����޳��������еĿ�ɥ�����૵����˼��������ڵ������ͻȻ��\n" +
			"��һ�����磬�������ͷ������ֻ���û������Ǳ�������һ��ů���С����\n" +
			"���������ˣ�\n"NOR, me);
	}
	else
		message_vision(HIY"ֻ�����޳��������еĿ�ɥ�����૵����˼���������ʲôҲû������\n"NOR, me);
	return 1;
	
}
