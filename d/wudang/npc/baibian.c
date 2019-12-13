// baibian.c
#include <ansi.h>
inherit NPC;
void create()
{
    seteuid(getuid());
    set_name("����", ({"zhang san", "zhang", "san", "bai bian" }) );
    set("title", HIY "�ٱ����" NOR);
    set("gender", "����" );
    set("age", 50);
    set("long", "һλ�������ݵĵ�ʿ��\n");
    set("attitude", "heroism");
    set("class", "taoist");
    set("str", 30);
    set("con", 30);
    set("int", 30);
    set("dex", 30);
    set("max_qi", 1200);
    set("max_jing", 500);
    set("neili", 4000);
    set("max_neili", 2000);
    set("add-exp-xyzx",1);	
    set("no_suck",1);
    set("jiali", 350);
    set("shen", -1000);
    set("no_suck",1);
    set("env/wimpy", 70);
    set_temp("apply/attack",  10);
    set_temp("apply/defense", 20);
    set("combat_exp", 500000);
    set_skill("force", 80); 
    set_skill("unarmed", 90);
    set_skill("sword", 90);
    set_skill("dodge", 100);
    set_skill("parry", 100);
    set_skill("taiji-quan", 90); 
    set_skill("taiji-jian", 90); 
    set_skill("taiji-shengong", 80); 
    set_skill("tiyunzong", 90);
    map_skill("force", "taiji-shengong");
    map_skill("unarmed","taiji-quan");
    map_skill("parry", "taiji-quan");
    map_skill("sword", "taiji-jian");
    map_skill("dodge", "tiyunzong");
    create_family("�䵱��", 3, "����");
    set("chat_chance", 15);
    set("chat_msg", ({
        (: random_move :)
    }) );
    setup();
    carry_object("/clone/weapon/gangjian")->wield();
    carry_object("/clone/cloth/cloth")->wear();
    if (random(10)>5)               	
carry_object("/clone/misc/mask");        	
    add_money("silver",20);
        
}
void init()
{
    
    object ob, me;
    int i;
    mapping skill_status, map_status, hp_status;
    string *sname, *mname;
    me = this_object();
    ob = this_player();
    ::init();
    if (me->is_fighting() || wizardp(ob)) return;
    if (ob->query("combat_exp") < 500000) return;
    remove_call_out("pretending");
    call_out("pretending", 10, ob);
    
    me->map_skill("unarmed");
    me->map_skill("dodge");
    me->map_skill("parry");
    if ( !(skill_status = ob->query_skills()) ) return;
    sname  = keys(skill_status);
    for(i=0; i<sizeof(skill_status); i++) {
        me->set_skill(sname[i], skill_status[sname[i]]);
    }
    if ( !(map_status = ob->query_skill_map()) ) return;
    mname  = keys(map_status);
    for(i=0; i<sizeof(map_status); i++) {
        me->map_skill(mname[i], map_status[mname[i]]);
    }
// Added by Hop, 1996.12.27
    hp_status = ob->query_entire_dbase();
    me->set("str", hp_status["str"]);
    me->set("int", hp_status["int"]);
    me->set("con", hp_status["con"]);
    me->set("dex", hp_status["dex"]);
    me->set("max_qi",    hp_status["max_qi"]);
    me->set("eff_qi",    hp_status["max_qi"]);
    me->set("qi",        hp_status["max_qi"]);
    me->set("max_jing",  hp_status["max_jing"]);
    me->set("eff_jing",  hp_status["max_jing"]);
    me->set("jing",      hp_status["max_jing"]);
    me->set("max_neili", hp_status["max_neili"]);
    me->set("neili",     hp_status["max_neili"] * 2);
	me->set("max_jingli", hp_status["max_jingli"]);
	me->set("jingli",     hp_status["max_jingli"] * 2);
    me->set("jiali",     (int)hp_status["jiali"]);
	me->set("combat_exp",(int)hp_status["combat_exp"]);
	// ���µ�Ϊ�����ӵ�����
	me->set("xyzx_sys/level", ob->query("xyzx_sys/level") + 3);
	me->set("xyzx_sys/jingzhun", ob->query("xyzx_sys/jingzhun"));
	me->set("xyzx_sys/lingxing", ob->query("xyzx_sys/lingxing"));
	me->set("xyzx_sys/minjie", ob->query("xyzx_sys/minjie"));
	me->set("xyzx_sys/fanying", ob->query("xyzx_sys/fanying"));

}
void pretending(object ob)
{
    object me = this_object();
 
    if(!ob || !userp(ob) || environment(ob) != environment()) return;
    if (!living(me)) return;
    switch( random(3) ) {
        case 0:
                       command("grin " + ob->query("id"));
                       command("pretend " + ob->query("id"));
                       command("exert recover");
               break;
        case 1:
                       command("hi " + ob->query("id"));
                       command("pretend " + ob->query("id"));
                       command("exert heal");
                       command("exert recover");
               break; 
        case 2:
                       command("heihei " + ob->query("id"));
               me->fight_ob(ob);
               ob->fight_ob(me);
               break;
    }
}
