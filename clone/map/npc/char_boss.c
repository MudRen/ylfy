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
	//"/clone/tzbox/jm-box",
	"/clone/tzbox/rf-box",
	"/clone/map/obj/longwen-chijin",
	});

void create()
{
	string weapon = "null";
	seteuid(getuid());
	
	set_name(HIM"������"NOR, ({"zeidao wang", "wang", "boss"}) );
    set("title", HIC "���ְ���" NOR);
    set("gender", "����" );
    set("icon", "30005" );
    set("age", random(30)+20);
    set("long", "����ɭ�ֵ��������죬����һ���������գ����׶����º���ʮ��֮����\n");
    set("attitude", "aggressive");
    set("class", "lvlin");
    set("str", 100);
    set("con", 100);
    set("int", 100);
    set("dex", 100);
    set("max_qi", 30000000 + random(60000000));
	set("qi", 30000000 + random(60000000));
    set("max_jing", 10000000+ random(20000000));
	set("jing", 10000000+ random(20000000));
    set("neili", 500000000);
    set("max_neili", 50000000);
	set("jingli", 100000);
    set("max_jingli", 100000);
	set("no_suck",1);
    set("jiali", 20000 + random(50000));
	set("end_boss", 1);
    set("env/wimpy", 10);
    set_temp("apply/attack",  500);
    set_temp("apply/defense", 300);
    set("combat_exp", 2100000000);
	set("xyzx_sys/level", 50000 + random(30000));
	set("xyzx_sys/fanying", 200000);
	set("xyzx_sys/jingzhun", 200000);
	set("xyzx_sys/minjie", 200000);
	set("xyzx_sys/lingxing", 200000);
    set_skill("force", 30000); 
    set_skill("unarmed", 30000);
    set_skill("dodge", 30000);
    set_skill("parry", 30000);
	set_skill("sword", 30000);
	set_skill("blade", 30000);
    create_family("���ֱ�����", 3, "����");
    set("chat_chance", 15);
	set("chat_msg", ({
		(: random_move :)
		}) );
    switch( random(2) ) {
	case 0:{
	set_skill("douzhuan-xingyi", 10000);
    set_skill("guiyuan-tunafa", 10000); 
    set_skill("tiezhang-zhangfa", 5000+random(5000)); 
    set_skill("wuming-jianfa", 5000+random(5000)); 
    set_skill("shaolin-shenfa", 10000);
    map_skill("force", "guiyuan-tunafa");
    map_skill("unarmed","tiezhang-zhangfa");
    map_skill("parry", "douzhuan-xingyi");
    map_skill("sword", "wuming-jianfa");
    map_skill("dodge", "shaolin-shenfa");
	weapon = "/clone/weapon/yuenv";	
	}
	break;	
	case 1: {
	set_skill("douzhuan-xingyi", 10000);
    set_skill("guiyuan-tunafa", 10000); 
    set_skill("liumai-shenjian", 5000+random(5000)); 
    set_skill("badao", 5000+random(5000)); 
    set_skill("shaolin-shenfa", 10000);
    map_skill("force", "guiyuan-tunafa");
    map_skill("unarmed","liumai-shenjian");
    map_skill("parry", "douzhuan-xingyi");
    map_skill("blade", "badao");
    map_skill("dodge", "shaolin-shenfa");
	weapon = "/clone/weapon/longya";
	}
	break;
    default: // others      BUG!!!
    set("long","�书���ô���BUG������");	
	}
	set("weapon", weapon);	
	setup();
	if( weapon != "null" ) carry_object(weapon)->wield();
    carry_object("/clone/cloth/hanbing-jia")->wear();
    add_money("gold", random(1000));
}

int just_kill(object guai,object player)
{
    int kar = player->query("kar");
    int kill=0;
	if(random(kar) >= random(40))
	{
	guai->command("haha");
	guai->command("say ���������������������鲻���Ͻ����ɣ�����");
	}
	else
	{
	guai->command("say ����С�ӵ�ù�������������鲻�ã������Ҹ��˿�������������ˣ�");
	    kill=1;
	}	
    if(kill==1)
    {
	if(!objectp(guai)||!objectp(player))
	    return 1;
	if(environment(guai) != environment(player))
	    return 1;
	guai->kill_ob(player);
	player->fight_ob(guai);
    }
    return 1;
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
	call_out("just_kill",1,me,ob);
	// command("follow "+ob->query("id"));
    // ֻ����>5000�����״̬
	if ( ob->query("xyzx_sys/level") < me->query("xyzx_sys/level") ) return;
	// �������ܵȼ�
	level = ob->query("xyzx_sys/level");
	// ֻ������ߵȼ����
	if ( me->query_temp("kill_ob_lvl") >= level ) return;
	// ��ֹ�ظ�����ͬһ��
	if ( objectp(get_ob=me->query_temp("fight_killer_id")) && get_ob==ob ) return;
	//__________________���Ŀǰ����״��___________________
	me->set_temp("fight_killer_id", ob);
	me->set_temp("kill_ob_lvl", level);
	//______________________��ǽ���_______________________
	//__________________________�ȼ���ز�������_____________________________
	//me->set("xyzx_sys/level", me->query("xyzx_sys/level")*11/10);
	//______________________________�������_________________________________
}

void die()
{
	object ob, me, corpse, baoshi, env;
	string room, name;
	int m, my_level;

	ob = this_object();
    my_level = ob->query("xyzx_sys/level", 1);
	if ( !objectp(env=environment(ob)) 
		|| !stringp(room=env->query("short")) ) 
	{
		::die();
		return;
	}

	if ( ob->query_temp("last_damage_from") )
	{
		me = ob->query_temp("last_damage_from");
		m = my_level*(100+random(200));
		
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
		baoshi->set("xyzx_item/pinji", 4);
		baoshi->set("name", YEL"��" + name);  
		 message("party", HIW"��"+room+"��"+HIM"��˵ "HIG+me->name(1)+HIM" �� "+ob->name(1)+HIM" ʬ���Ϸ�����"HIW+baoshi->name(1)+"("+baoshi->query("id")+")��\n"NOR,users() );	
		baoshi->move(corpse);
	}
	else if ( random(100) < 5 )
		    {
			baoshi = new(random_item2[random(sizeof(random_item2))]);
             message("party", HIW"��"+room+"��"+HIM"��˵ "HIG+me->name(1)+HIM" �� "+ob->name(1)+HIM" ʬ���Ϸ�����"HIW+baoshi->name(1)+"("+baoshi->query("id")+")��\n"NOR,users() );				
			baoshi->move(corpse);
		}

	COMBAT_D->announce(ob, "dead");
	destruct(ob);
	return;
}
