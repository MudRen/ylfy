#include <ansi.h>
inherit NPC;

void create()
{
	set_name( "�����" , ( { "zhu banxian","zhu","halfgod","xian"}) );
	set("gender", "����" );
	set("age", 56);
	set("long","������Ǹ���������ϼһ\n");
	set("no_die",1);
	set("env/wimpy", 70);
	set("max_jingli", 1000);
	set("max_neili", 100);
	set("jingli", 100000);
	set("neili",10000000);
	set("jiali",1000);
	set("str", 530);
	set("con", 30);
	set("int", 10);
	set("dex", 530);
	set("combat_exp", 100000000);

	set_skill("force", 50);
	set_skill("unarmed", 200+random(2000));
	set_skill("sword", 200+random(2000));
	set_skill("parry", 2000);
	set_skill("dodge", 200+random(2000));

	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/armor", 200);
	set_temp("apply/dodge", 800);

	setup();
	set("water",max_water_capacity());
	set("food",max_food_capacity());
	carry_object(__DIR__"obj/wizardsword")->wield();
	carry_object(__DIR__"obj/cloth")->wear();


}


void init()
{
	add_action("give_quest", "quest");
}


string time_period(int timep)
{
	int t, d, h, m, s;
	string time;
	t = timep;


	s = t % 60;
	t /= 60;
	m = t % 60;
	t /= 60;
	h = t % 24;
	t /= 24;
	d = t;


	if(d)
		time = chinese_number(d) + "��";
	else
		time = "";


	if(h)
		time += chinese_number(h) + "Сʱ";
	if(m)
		time += chinese_number(m) + "��";
	time += chinese_number(s) + "��";


	return " ��" + time + "��,";
}


int give_quest()
{
	object me,*ob;
	int i,j,num,combatexp;
	string tag;
	mapping quest=([ ]) ;
	string *levels = (
	{
		"1000",
		"3000",
		"5000",
		"10000",
		"20000",
		"50000",
		"100000",
		"150000",
		"200000",
		"250000",
		"300000",
		"400000",
		"500000",
		"1000000",
		"2000000",
	});
	me = this_player();
	combatexp = (int)(me->query("combat_exp"));


	if((quest =  me->query("quest")))
	{
		if( ((int)me->query("quest/task_time")) >  time() )
		{
			message_vision("$N����$pһ��: "+RANK_D->query_respect(me)+"�ƺ�������������ɣ�\n", this_object(),me);
			return 0;
		}
		else
		{
			me->set("quest_failed",(int)me->query("quest/task_time") + random(100)+10);
			me->delete("quest");
		}
	}
	if( time() >= me->query("quest_failed") )
	{
		me->delete_temp("count");
		me->delete("quest_failed");
	}
	if(me->query("quest_failed") )
	{
		message_vision("$N��$p����һ��: �ϴε�������ɲ��ˣ������Ҿ�ɱ���㣡\n", this_object(),me);
		return 1;
	}
	for(j = sizeof(levels) - 1 ; j >= 0; j--)
	{
		if( atoi(levels[j])  <= combatexp )
		{
			num = random(j);
			break;
		}
	}


	tag = levels[num];
	while(1)
	{
		if (random(10)>5)
		{
			quest = QUEST_D(tag)->query_quest();
			if (!mapp(quest))	return 0;
			quest["time"]=quest["diff"]*(random(70)+150);
			tag=time_period(quest["time"]);
			command("whisper "+me->query("id")+tag+ "�����ҡ�" + quest["quest"] + "����\n");
			me->set("quest", quest);
			me->set("quest/quest_type","Ѱ");
			me->set("quest/task_time", (int)time() + (int)quest["time"]);
			me->add_temp("quest_count",1);
			return 1;
		}
		else
		{
			ob=livings();
			for (j=0; j<sizeof(ob); j++)
			{
				i=random(sizeof(ob));
				if (ob[i]->query("combat_exp")<= combatexp+10 )
				{
					if (!environment(ob[i])) continue;
					if (userp(ob[i]) || !living(ob[i]) ) continue;
					if (environment(ob[i])->query("no_fight")) continue;
					if (ob[i]->query("no_die")) continue;
					if (sscanf(base_name(ob[i]),"/u/%*s" )) continue;
					if (sscanf(base_name(ob[i]),"/clone/%*s" )) continue;
					me->set("quest/time",random(200)+150);
					tag=time_period(me->query("quest/time"));
					command("whisper "+me->query("id")+tag+ "ɱ��" + ob[i]->short() + "��\n");
					me->set("quest/quest", ob[i]->short());
					me->set("quest/quest_type","ɱ");
					me->set("quest/diff",random(4)+2);
					me->set("quest/task_time", (int)time() + me->query("quest/time"));
					me->add_temp("quest_count",1);
					return 1;
				}
			}
			continue;
		}
	}


}


int accept_object(object me, object obj)
{
	mapping quest,target;
	object home;
	int i;


	if( time() < me->query("quest_failed") || mapp(quest=me->query("quest")))
	{
		i=me->query("combat_exp");
		if (i>100000 ) i=100000;
		if (obj->query("money_id") && obj->value() >= i )
		{
			command("say �ðɣ�"+me->name()+"���ϴε���������ˣ�");
			me->delete("quest_failed");
			me->delete("quest");
			return 1;
		}
	}
	if (!mapp(quest))
	{
		command("say �Ҷ�"+obj->name()+CYN+"������Ȥ��");
		return 0;
	}
	if ( quest["quest_type"] != "Ѱ" )
	{
		say( CYN+this_object()->name()+"ҡ��ҡͷ��"+RANK_D->query_respect(me)+"�����������ҵ���ƨ��\n"NOR);
		return 0;
	}


	target = quest["quest"];
	if ( target!=obj->name() )
	{
		command("say �Ҷ�"+obj->name()+CYN+"������Ȥ��");
		return 0;
	}
	if(!home = find_object(query("startroom")) )
		home = load_object(query("startroom"));
	if (environment()!=home)
	{
		command("say ��������æ���أ����һ�ȥ��˵�ɣ�");
		return 0;
	}
	if( quest["task_time"] >  time() )
	{
		i=quest["diff"]*50+1;
		if(!(me->query_temp("quest_count")%8))
			i*=2;
		command("smile");
		i=(i/3+1)*2;
		tell_object(me, sprintf(WHT"��Բ��������������:\n������%s��ս�����飡", chinese_number(i)) );
		me->add("combat_exp", i);
		i=random(i)*2+1;
		tell_object(me, sprintf(HIY"\n%s��Ǳ�ܣ�\n"NOR, chinese_number(i)) );
		me->add("potential",i);
		i=random(i)*2/3+10;
		tell_object(me, sprintf(YEL"��������������%s�㣡\n"NOR, chinese_number(i)) );
		me->add("score",i);
		me->delete("quest");
		return 1;
	}
	else
	{
		me->set("quest_failed",(int)me->query("quest/task_time") + (int)me->query("quest/time"));
		if( time() >= me->query("quest_failed") )
		{
			me->delete_temp("quest_count");
			me->delete("quest_failed");
		}
		message_vision(CYN+"$N�������ض�$n˵������ô����¶��첻�ã���û�ã�\n"+NOR, this_object(), me);
		me->delete("quest");
		return	1;
	}
}






