#include <ansi.h>
inherit NPC;

void create()
{
	seteuid(getuid());
    set_name("������ͷ", ({"peilian jiaotou", "peilian", "jiaotou" }) );
    set("title", HIW "������ʿ" NOR);
    set("gender", "����" );
    set("age", 50);
    set("long", "һλ����������������Ϊ���Ĺ��ˡ�\n");
    set("attitude", "heroism");
    set("class", "party");
    set("str", 21);
    set("con", 30);
    set("int", 27);
    set("dex", 23);
    set("max_qi", 12000000);
    set("max_jing", 500);
    set("neili", 4000);
    set("max_neili", 2000);
	set("add-exp-xyzx",1);
	set("no_suck",1);
	set("no_get",1);
	//set("no_zhineng",1);
    set("jiali", 350);
    set("shen", -1000);
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
    
	setup();
    
    carry_object("/clone/weapon/changjian")->wield();
    carry_object("/clone/cloth/cloth")->wear();
    add_money("silver",50);        
}
int accept_fight(object ob)
{
    object me;
    mapping hp_status, skill_status, map_status;
    string *sname, *mname;
    int i, temp;
    me = this_object();
    if (is_fighting()) return 0;
    if (me->query("damaged")){
        tell_object(ob,"�����ͷ�������������\n"); 
        return 0;
    }

    me->set("last_fighter", ob->query("id"));
    me->add("fight_times", 1);
    remove_call_out("renewing");    
    call_out("renewing", 300 + random(300), me);  
/* delete and copy skills */
    if ( mapp(skill_status = me->query_skills()) ) {
        skill_status = me->query_skills();
        sname  = keys(skill_status);
        temp = sizeof(skill_status);
        for(i=0; i<temp; i++) {
            me->delete_skill(sname[i]);
        }
    }
    if ( mapp(skill_status = ob->query_skills()) ) {
        skill_status = ob->query_skills();
        sname  = keys(skill_status);
        for(i=0; i<sizeof(skill_status); i++) {
        me->set_skill(sname[i], skill_status[sname[i]]);
        }
    }

/* delete and copy skill maps */
    if ( mapp(map_status = me->query_skill_map()) ) {
        mname  = keys(map_status);
        temp = sizeof(map_status);
        for(i=0; i<temp; i++) {
            me->map_skill(mname[i]);
        }
    }
    if ( mapp(map_status = ob->query_skill_map()) ) {
        mname  = keys(map_status);
        for(i=0; i<sizeof(map_status); i++) {
            me->map_skill(mname[i], map_status[mname[i]]);
        }
    }
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
    if ( ob->query("xyzx_sys/level") <= 5000){
        me->set("xyzx_sys/level", ob->query("xyzx_sys/level") + 20);
        tell_object(ob,"������ͷ�������ʵ���������Լ���״̬\n");
    }
    else
{
    tell_object(ob,"������ͷ�Ѿ�û���������������ˡ�\n");
    return 0;
    }
    /*me->set("xyzx_sys/jingzhun", ob->query("xyzx_sys/jingzhun")); 
    me->set("xyzx_sys/lingxing", ob->query("xyzx_sys/lingxing"));
    me->set("xyzx_sys/minjie", ob->query("xyzx_sys/minjie"));
    me->set("xyzx_sys/fanying", ob->query("xyzx_sys/fanying"));*/
    return 1;
}
void renewing(object me)
{
    me->delete("last_fighter");
}

