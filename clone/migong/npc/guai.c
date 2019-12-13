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

void create()
{
	seteuid(getuid());
	
	set_name(HIG"����ǿ��"NOR, ({"lvlin qiangdao", "lvlin", "qiangdao"}) );
    set("title", HIY "��������" NOR);
    set("gender", "����" );
    set("icon", "30002" );
    set("age", random(30)+20);
    set("long", "��ڼž�֮ɭ��ǿ����ר��پ��������������Щ�ޱ����⡣\n");
    set("attitude", "aggressive");
    set("class", "lvlin");
    set("str", 30);
    set("con", 30);
    set("int", 30);
    set("dex", 30);
    set("max_qi", 50000);
    set("max_jing", 50000);
    set("neili", 50000);
    set("max_neili", 50000);
	set("no_suck", 1);
	//set("no_zhineng", 1);
    set("jiali", 50);
    set("shen", 0);
    //set("env/wimpy", 50);
    set_temp("apply/attack",  10);
    set_temp("apply/defense", 20);
    set("combat_exp", 500000);
    set_skill("force", 150); 
    set_skill("unarmed", 150);
    set_skill("blade", 150);
    set_skill("dodge", 150);
    set_skill("parry", 150);
    set_skill("jiuyin-baiguzhao", 150); 
    set_skill("wuhu-duanmendao", 150); 
    set_skill("taiji-shengong", 150); 
    set_skill("tiyunzong", 150);
    map_skill("force", "taiji-shengong");
    map_skill("unarmed","jiuyin-baiguzhao");
    map_skill("parry", "jiuyin-baiguzhao");
    map_skill("blade", "wuhu-duanmendao");
    map_skill("dodge", "tiyunzong");
    create_family("���ֱ�����", 3, "����");
    set("chat_chance", 3);
	//set("chat_msg", ({
	//	(: random_move :)
	//	}) );
    
	setup();
    
	if ( random (10) > 5 )
		carry_object("/clone/weapon/hanbing-dao")->wield();
	else
		carry_object("/clone/weapon/hanbing-jian")->wield();

    carry_object("/clone/cloth/hanbing-jia")->wear();
	if ( random (10) > 5 )
    add_money("gold", 1+random(15));
}

void init()
{
	object ob, me, get_ob;
	int i, level, is_time;
	mapping skill_status, map_status, hp_status;
    string *sname, *mname;
    
	me = this_object();
    ob = this_player();

    // ��������ǿ��Զ����ģ���ֻ������
	if ( !objectp(ob) || !living(me) || !playerp(ob) ) return;
    // �����ɱ
	me->kill_ob(ob);
	// command("follow "+ob->query("id"));
	// ս���в�����
	if ( sizeof(me->query_enemy()) > 1 
		&& (is_time=me->query_temp("copy_ob_time")) 
		&& is_time < time() )
		return;
	// ����̫��û�п����ı�Ҫ
	//if ( ob->query("combat_exp") < 210000 ) return;
	// �������ܵȼ�
	level = ob->query("xyzx_sys/level");
	// ֻ������ߵȼ����
	if ( me->query_temp("kill_ob_lvl") > level ) return;
	// ��ֹ�ظ�����ͬһ��
	if ( objectp(get_ob=me->query_temp("fight_killer_id")) && get_ob==ob ) return;
	//__________________���Ŀǰ����״��___________________
	me->set_temp("fight_killer_id", ob);
	me->set_temp("kill_ob_lvl", level);
	me->set_temp("copy_ob_time", time()+3);
	//______________________��ǽ���_______________________
	//______________________________����״̬_______________________________
	hp_status = ob->query_entire_dbase();
    me->set("str", (int)hp_status["str"]);
    me->set("int", (int)hp_status["int"]);
    me->set("con", (int)hp_status["con"]);
    me->set("dex", (int)hp_status["dex"]);
    me->set("max_qi",    (int)hp_status["max_qi"]);
    me->set("eff_qi",    (int)hp_status["max_qi"]);
    me->set("qi",        (int)hp_status["max_qi"]);
    me->set("max_jing",  (int)hp_status["max_jing"]);
    me->set("eff_jing",  (int)hp_status["max_jing"]);
    me->set("jing",      (int)hp_status["max_jing"]);
    me->set("max_neili", (int)hp_status["max_neili"]);
    me->set("neili",     (int)hp_status["max_neili"]);
    me->set("max_jingli",(int)hp_status["max_jingli"]);
    me->set("jingli",    (int)hp_status["max_jingli"]);
    me->set("jiali",     (int)hp_status["jiali"]);
	
	if ( hp_status["combat_exp"] < 1500000000)
		me->set("combat_exp", (int)((hp_status["combat_exp"]/4)*5));
	else
		me->set("combat_exp", 2100000000);
	//____________________________״̬�������_____________________________
    // û�м��ܿɸ���
	if ( !(skill_status = ob->query_skills()) ) return;
	
	sname = keys(skill_status);
    for ( i=0; i<sizeof(skill_status); i++ )
	{
		me->set_skill(sname[i], skill_status[sname[i]]);
    }
    // û�м������ܿɸ���
	if ( !(map_status = ob->query_skill_map()) ) return;

	//ж����������
    me->map_skill("unarmed");
    me->map_skill("dodge");
    me->map_skill("parry");
	me->map_skill("sword");
	me->map_skill("force");
	me->map_skill("blade");
    
	mname  = keys(map_status);
    for(i=0; i<sizeof(map_status); i++) 
	{
		me->map_skill(mname[i], map_status[mname[i]]);
    }
}

void die()
{
	object ob, me, corpse, baoshi, env;
	string room, name;
	int m, flag;

	ob = this_object();
	flag = 1;

	// �Ȱ󶨵����εĶ�����
	if ( !objectp(me = ob->query_temp("last_unconcious_from")) )
		me = ob->query_temp("last_damage_from"); // �󶨵�����˺�����

	if ( !objectp(me) // δ�ɹ��� 
		|| !objectp(env=environment(ob)) 
		|| !stringp(room=env->query("short")) ) 
	{
		::die();
		return;
	}

	if ( me )
	{
		m = 1000+random(1000);
		
		if ( interactive(me) && me->query("xyzx_sys/level") < 100 )
		{
			message_vision(HIG"\n$Nɱ���� "+ob->name(1)+HIG" �������� "HIM+(me->query_exp_times()*m)+HIG" �㾭��� "HIY+(m/10)+HIG" Ǳ�ܡ�\n"NOR, me);
			me->add("combat_exp", m, 1);
			me->add("potential", m / 10, 1);
		}
	}
	
	if ( objectp(corpse = CHAR_D->make_corpse(ob, me)) )
		corpse->move(environment(ob));
	// �󶨵������䶳һ����
	corpse->set("valid_get_from", me->query("id"));

	if ( objectp(me) && objectp(ob) && me->query("xyzx_sys/level") < 100 )
	{
		if ( me->query("xyhy_type") == 2 ) flag = 2;
		if ( random(100) < 10*flag )
		{			
			baoshi = new(random_item[random(sizeof(random_item))]);
            name = baoshi->name(1);	
			message_vision(HIG"\n$N�� "HIY+ob->name(1)+NOR" ��ʬ���Ϸ�����"HIW+baoshi->name(1)+"("+baoshi->query("id")+")��\n"NOR,  me);	
			baoshi->move(corpse);
		}
		else if ( random(100) < 10*flag )
		{			
			baoshi = new("/clone/map/obj/hanyu-jingtie");
			message_vision(HIG"\n$N�� "HIY+ob->name(1)+" ��ʬ���Ϸ�����"HIW+baoshi->name(1)+"("+baoshi->query("id")+")��\n"NOR,  me);	
			baoshi->move(corpse);
		}
	}

	COMBAT_D->announce(ob, "dead");
	destruct(ob);
	return;
}