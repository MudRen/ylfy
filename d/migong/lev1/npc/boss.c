#include <ansi.h>
inherit NPC;

string *random_item = ({
	"/clone/gem/gem",
	"/clone/gem/robe",
	"/clone/tzbox/sx-box",
	"/clone/tzbox/jm-box",
	"/clone/map/obj/longwen-chijin",
	"/clone/tzbox/qf-box",
	});

void create()
{
	seteuid(getuid());
	
	set_name("������", ({ "heiyi ren", "heiyi", "boss" }));
    set("long", "��������˽���ɵ�������Ѱ�ұ���ĵ��ӣ�������˽�»�����Կ��������˶���һ���֡�������\n");
    set("title", "������");
    set("gender", "����" );
    set("icon", "30005" );
    set("age", random(30)+20);   
    set("attitude", "aggressive");
    set("class", "lvlin");
    set("str", 90);
    set("con", 90);
    set("int", 90);
    set("dex", 90);
    set("max_qi", 100000000);
	set("qi", 100000000);
    set("max_jing", 50000000);
	set("jing", 50000000);
    set("neili", 300000000);
    set("max_neili", 300000000);
	set("jingli", 300000000);
    set("max_jingli", 300000000);
	set("no_suck",1);
    set("jiali", 50000);
	set("end_boss", 1);
    set("env/wimpy", 50);
    set_temp("apply/attack",  5000);
    set_temp("apply/defense", 3000);
    set("combat_exp", 2100000000);
	set("xyzx_sys/level", 5000);
	set("xyzx_sys/fanying", 60000);
	set("xyzx_sys/jingzhun", 60000);
	set("xyzx_sys/minjie", 60000);
	set("xyzx_sys/lingxing", 60000);
    set_skill("force", 15750);
    set_skill("unarmed", 15900);
    set_skill("dodge", 15800);
    set_skill("parry", 15940);
    set_skill("staff", 15000);
    set_skill("hamagong", 5980);
    set_skill("chanchu-bufa",5870);
    set_skill("training",5500);	
    set_skill("shexing-diaoshou",5800);
    set_skill("lingshe-zhangfa",5000);
    map_skill("force", "hamagong");
    map_skill("dodge", "chanchu-bufa");
    map_skill("unarmed", "hamagong");
    map_skill("parry", "lingshe-zhangfa");
    map_skill("staff", "lingshe-zhangfa");
    create_family("������Ѱ����", 3, "����");
    set("chat_chance", 15);
	set("chat_msg", ({
		(: random_move :)
		}) );
    
	setup();
    
	carry_object("/clone/weapon/gangzhang")->wield();
    carry_object("/clone/cloth/cloth")->wear();
    add_money("gold", random(1000));
}

int just_kill(object guai,object player)
{
    int kar = player->query("kar");
    int kill=0;
	if(random(kar) >= random(30))
	{
	guai->command("haha");
	guai->command("say �����������������ڲ��붯�֣�����");
	}
	else
	{
	guai->command("say ���������ͷ�ˣ������������鲻�ã����Ҹ��˿���");
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
	if ( ob->query("xyzx_sys/level") < 5000 ) return;
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
	me->set("xyzx_sys/level", ob->query("xyzx_sys/level") * 12 / 10);
	me->set("xyzx_sys/jingzhun", ob->query("xyzx_sys/jingzhun") * 12 / 10);
	me->set("xyzx_sys/minjie", ob->query("xyzx_sys/minjie") * 12 / 10);
	me->set("xyzx_sys/lingxing", ob->query("xyzx_sys/lingxing") * 12 / 10);
	me->set("xyzx_sys/fanying", ob->query("xyzx_sys/fanying") * 12 / 10);
	//______________________________�������_________________________________
}

void die()
{
	object ob, me, corpse, baoshi, env;
	string room;
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

	if ( objectp(me) && objectp(ob) && random(100) < 20 )
	{
		baoshi = new(random_item[random(sizeof(random_item))]);
		message("party", HIW"��"+room+"��"+HIM"��˵ "HIG+me->name(1)+HIM" �� "+ob->name(1)+HIM" ʬ���Ϸ����� "+baoshi->name(1)+HIM"��\n"NOR,users() );	
		baoshi->move(corpse);
	}

	COMBAT_D->announce(ob, "dead");
	destruct(ob);
	return;
}