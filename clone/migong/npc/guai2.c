#include <ansi.h>
inherit NPC;

string *random_item = ({      
    "/clone/map/weapon/axe",
    "/clone/map/weapon/blade",
    "/clone/map/weapon/club",
    "/clone/map/weapon/hammer",
    "/clone/map/weapon/spear",
    "/clone/map/weapon/staff",
    "/clone/map/weapon/whip",
    "/clone/map/weapon/sword",
    "/clone/map/armor/boot",
    "/clone/map/armor/cloth",
    "/clone/map/armor/hand",
    "/clone/map/armor/head",
    "/clone/map/armor/neck",
    "/clone/map/armor/ring",
    "/clone/map/armor/shield",
    "/clone/map/armor/surcoat",
    "/clone/map/armor/waist",
    "/clone/map/armor/wrists",
    "/clone/map/armor/armor",
	"/clone/map/armor/pants",
    });

string *random_item2 = ({
	"/clone/tzbox/qf-box",
	"/clone/tzbox/sx-box",
	"/clone/tzbox/jm-box",
	});
void create()
{
	int tsjndj;
	string weapon = "null";
	tsjndj = 10000 + random(10000);
    seteuid(getuid());
    
    set_name(WHT"ɥʬ"NOR, ({"sang shi"}) );
    set("title", WHT "����Թ��" NOR);
    set("gender", "����" );
    set("icon", "30003" );
    set("age", random(100)+100);
    set("long", "���Ե�����Թ�飬����������һ��а��֮����\n");
    set("attitude", "aggressive");
    set("class", "yuanling");
    set("str", 40);
    set("con", 40);
    set("int", 40);
    set("dex", 40);
    set("max_qi", 100000000);
    set("qi", 100000000);
    set("max_jing", 50000000);
    set("jing", 50000000);
    set("neili", 150000000);
    set("max_neili", 100000000);
    set("jingli", 30000000);
    set("max_jingli", 3000000);
    set("no_suck", 1);
    set("jiali", 70000);
    //set("end_boss", 1);
    set("env/wimpy", 10);
    set_temp("apply/attack",  550);
    set_temp("apply/defense", 530);
    set("combat_exp", 2100000000);
    set("xyzx_sys/level", 50000+random(40000));
	set("xyzx_sys/fanying", 150000+random(100000));
	set("xyzx_sys/jingzhun", 150000+random(100000));
	set("xyzx_sys/minjie", 150000+random(100000));
	set("xyzx_sys/lingxing", 150000+random(100000));
    set_skill("force", 50000); 
    set_skill("unarmed", 50000);
    set_skill("dodge", 50000);
    set_skill("parry", 50000);
    set_skill("sword", 50000);
	set_skill("blade", 50000);
    create_family("�����ػ���", 3, "����");
    set("chat_chance", 20);
    set("chat_msg", ({
        (: random_move :)
        }) );
    switch( random(2) ) {
	case 0:{
	set_skill("tianmo-jian", tsjndj);
    set_skill("tianmo-shengong", tsjndj); 
    set_skill("tianmo-zhang", tsjndj); 
    set_skill("shaolin-shenfa", tsjndj);
    map_skill("force", "tianmo-shengong");
    map_skill("unarmed","tianmo-zhang");
    map_skill("parry", "tianmo-jian");
    map_skill("sword", "tianmo-jian");
    map_skill("dodge", "shaolin-shenfa");
	weapon = "/clone/weapon/hanbing-jian";	
	}
	break;	
	case 1: {
	set_skill("tianmo-dao", tsjndj);
    set_skill("tianmo-shengong", tsjndj); 
    set_skill("tianmo-quan", tsjndj); 
    set_skill("shaolin-shenfa", tsjndj);
    map_skill("force", "tianmo-shengong");
    map_skill("unarmed","tianmo-quan");
    map_skill("parry", "tianmo-dao");
    map_skill("blade", "tianmo-dao");
    map_skill("dodge", "shaolin-shenfa");
	weapon = "/clone/weapon/hanbing-dao";	
	}
	break;	
	}
	set("weapon", weapon);	
	setup();
	if( weapon != "null" ) carry_object(weapon)->wield();
    carry_object("/clone/cloth/hanbing-jia")->wear();
    add_money("gold", random(100));
}

void init()
{
    object ob, me, get_ob;
    int level;
    
    me = this_object();
    ob = this_player();

    // ��������ǿ��Զ����ģ���ֻ������
    if ( !objectp(ob) || !living(me) || !playerp(ob) ) return;
    // �����ɱ
    me->kill_ob(ob);
    command("follow "+ob->query("id"));
    // ֻ���Ƶȼ����Լ��ߵ���ҵȼ�
	if ( ob->query("xyzx_sys/level") < me->query("xyzx_sys/level") ) return;
    // �������ܵȼ�
    level = ob->query("combat_exp")/LEVUP_EXP+ob->query("xyzx_sys/level");
    // ֻ������ߵȼ����
    if ( me->query_temp("kill_ob_lvl") >= level ) return;
    // ��ֹ�ظ�����ͬһ��
    if ( objectp(get_ob=me->query_temp("fight_killer_id")) && get_ob==ob ) return;
    //__________________���Ŀǰ����״��___________________
    me->set_temp("fight_killer_id", ob);
    me->set_temp("kill_ob_lvl", level);
	//me->set_temp("copy_ob_time", time()+2);
    //______________________��ǽ���_______________________
    //__________________________�ȼ���ز�������_____________________________
    me->set("xyzx_sys/level", me->query("xyzx_sys/level")*11/10);
    //______________________________�������_________________________________
}

void die()
{
    object ob, me, corpse, baoshi, env;
    string room, name;
    int m;

    ob = this_object();

    if ( !objectp(env=environment(ob)) 
        || !stringp(room=env->query("short")) ) 
    {
        ::die();
        return;
    }

    if ( ob->query_temp("last_damage_from") )
    {
        me = ob->query_temp("last_damage_from");
        m = random(50000);
        
        if ( interactive(me) )
        {
            message_vision(HIG"\n��ɱ���� "+ob->name(1)+HIG" �������� "HIM+(m*me->query_exp_times())+HIG" �㾭��� "HIY+(m/10)+HIG" Ǳ�ܡ�\n"NOR, me);
            message("party", HIW"��"+room+"��"+HIG+me->name(1)+HIM" ɱ���� "+ob->name(1)+HIM" �������� "HIC+(me->query_exp_times()*m)+HIM" �㾭��� "HIY+(m/10)+HIM" Ǳ�ܡ�\n"NOR,users() );    
            me->add("combat_exp",m);
            me->add("potential",m / 10);
        }
    }
    
    if ( objectp(corpse = CHAR_D->make_corpse(ob, me)) )
        corpse->move(environment(ob));

    if ( objectp(me) && objectp(ob) && random(100) > 70 )
    {
        baoshi = new(random_item[random(sizeof(random_item))]);
		name = baoshi->name(1);		    
        switch ( random(2))
        {
            case 0 : 
                baoshi->set("xyzx_item/pinji", 4);
                baoshi->set("name", YEL"��" + name);
                break;
            case 1 : 
                baoshi->set("xyzx_item/pinji", 3);
                baoshi->set("name", MAG"����" + name);
                break;           
        }
        message("party", HIW"��"+room+"��"+HIM"��˵ "HIG+me->name(1)+HIM" �� "+ob->name(1)+HIM" ʬ���Ϸ�����"HIW+baoshi->name(1)+"("+baoshi->query("id")+")��\n"NOR,users() );    
        baoshi->move(corpse);
    }
	if ( random(100) < 2 )
		    {
			baoshi = new(random_item2[random(sizeof(random_item2))]);
            message("party", HIW"��"+room+"��"+HIM"��˵ "HIG+me->name(1)+HIM" �� "+ob->name(1)+HIM" ʬ���Ϸ�����"HIW+baoshi->name(1)+"("+baoshi->query("id")+")��\n"NOR,users() );	
			baoshi->move(corpse);
		}
    
    COMBAT_D->announce(ob, "dead");
    destruct(ob);
    return;
}