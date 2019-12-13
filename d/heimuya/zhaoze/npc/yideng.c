//yideng.c
inherit NPC;
inherit F_MASTER;
void checking(object me,object ob);
void create()
{
    set_name("һ��", ({"yideng dashi", "yideng", "dashi"}));
    set("nickname", HIY "�ϵ�" NOR );
    set("gender", "����");
    set("age", 42);
    set("long", 
        "����Ŀ���飬���������İ�ü���۽Ǵ���������\n"
        "ü����������࣬��ȴ��һ��Ӻ�ݸ߻�����ɫ��\n");
    set("attitude", "peaceful");
    set("per",32);
    set("class", "bonze");
    set("str", 11571);
    set("int", 80);
    set("con", 86);
    set("dex", 1440);
    set("chat_chance", 1);
    set("chat_msg", ({
        "һ�ƴ�ʦ��ͷ��˼����Ȼ���\n",
    }));
    set("inquiry", ([
    "����ͯ�ܲ�ͨ" : (: command("sigh"),command("buddhi") :),
          "����ͯ" : (: command("sigh"),command("buddhi") :),
          "�ܲ�ͨ" : (: command("sigh"),command("buddhi") :),
            "����" : (: command("buddhi") :),
    ]));
    set("qi", 350000);
    set("max_qi", 350000);
    set("jing", 350000);
    set("max_jing", 350000);
    set("max_jingli", 3000);

    set("jingli", 3000);
    set("neili", 13500000);
    set("max_neili", 13500);
    set("jiali", 300);
    
    set("combat_exp", 510000000);
     
    set_skill("force", 500);             // �����ڹ�
    set_skill("kumu-shengong", 500);
    set_skill("shaolin-shenfa", 1500);
    set_skill("yiyang-zhi", 500);
    set_skill("unarmed", 500);           // ����ȭ��
    set_skill("dodge", 1500);             // ��������
    set_skill("parry", 500);             // �����м�
    set_skill("sword", 500);             // ��������
    set_skill("literate",550);           // ����ʶ��
    set_skill("duanjia-sword",850);          
    set_skill("sword",1100);          
    
    map_skill("force"  , "kumu-shengong");
    map_skill("unarmed", "yiyang-zhi");
    map_skill("dodge"  , "shaolin-shenfa");
    map_skill("sword"  , "duanjia-sword");	
    map_skill("parry"  , "yiyang-zhi");
    
    create_family("����μ�",17,"����");
    set("chat_chance_combat", 300);	
    set("chat_msg_combat", ({
		(: perform_action, "sword.ailao" :),
		(: perform_action, "sword.fenglei" :),
		(: perform_action, "sword.jingtian" :),
		(: perform_action, "unarmed.sandie" :),	
		}) );	
    setup();
	carry_object("/clone/weapon/changjian")->wield();    	
    carry_object(__DIR__"obj/sengpao")->wear();    
}
void init()
{
    object me;
    ::init();
    me=this_player();
    if (me->query_temp("kill_shi")){
          command("buddhi");
          message_vision("$N���˿�$n��ҡ��ҡͷ��̾������λ" + RANK_D->query_respect(me) + "�����ɱ��̫���ˣ�������ذɣ�\n",this_object(),me);
          me->delete_temp("tmark/��");
          me->delete_temp("kill_shi");
    }
}

void attempt_apprentice(object ob)
{       
        if ((int)ob->query("class", "officer"))
		{
			if ((int)ob->query_skill("kumu-shengong",1) < 550 )
			{
				command("say ��ı����ڹ��ķ�̫����,����Ŭ�������һ�°�!");
				return;
			}
			else
				{ 
                command("nod");
                command("say " + RANK_D->query_respect(ob) + "�պ�سɴ��� ��\n");
                command("recruit " + ob->query("id") );
				}
        }
		else
			command("say �������ǳ���֮�ˣ�������ͽ���ˣ�");
}

int accept_object(object me, object ob)
{
    if (me->query_temp("tmark/��"))
	{
		if ( (string) ob->query("id") =="hong juan" )
		{
          message_vision("$N��$n˵���������Ļ������ˣ��������ǻ��������˽�ɣ�\n", this_object(),me);
          message_vision("$N��$n˵����ʩ��֮������������Ϊ����ʩ�����п�Ͼ����ȥ�������ұ���ָ��ָ�㣡\n", this_object(),me);
          //me->set_temp("tmark/��", 1);�ѷŵ����棬����սʤ����ȡ�øò���
          remove_call_out("checking");
          call_out("checking", 1, this_object(),me);
          return 1;
		}
	}
	else
		return 0;
}

void checking(object me, object ob)
{
        if (!ob || !present(ob, environment()) )
			return;
		me->set("eff_qi",me->query("max_qi"));
        me->set("qi",me->query("max_qi"));
        me->set("eff_jing",me->query("max_jing"));
        me->set("jing",me->query("max_jing"));
		me->set("neili",13500000);

        ob->fight_ob(me);
        me->fight_ob(ob);
        remove_call_out("do_checking");
        call_out("do_checking", 1, me,ob);
}
void do_checking(object me,object ob)
{
	int my_qi, his_qi;
	
	if (!me || !ob || !present(ob,environment()) )
		return;

	if (me->is_fighting(ob) && ob->is_fighting(me))
	{
		remove_call_out("do_checking");
		call_out("do_checking", 1, me,ob);
		return;
	}
	
	if (!living(me))
	{
		me->revive();
		my_qi=0;
	}
	else
		my_qi  = (int)me->query("qi")*100/(int)me->query("max_qi");
        his_qi = (int)ob->query("qi")*100/(int)ob->query("max_qi");
	
	if (his_qi > my_qi)
	{
		if(my_qi < 50)
		{
			say(CYN+"һ��˵����ʩ�����ֹ�Ȼ����������������������ڿ�����ȴ��Ե�ˡ�\n"+NOR);
			ob->set_temp("tmark/��", 1);
			ob->set_temp("tmark/��1", 1);
			return;
		}
	}
	else
		{
		say(CYN+"һ��˫�ֺ�ʮ������Եһ��������ʩ����ذɡ�\n"+NOR);
		message_vision("$N��һ�ƴ�ʦ���������ؿ���һ��ͷ��\n", ob);
		me->delete_temp("tmark/��");
		}
}

void die()
{
	object killer;
	
	if( objectp(killer = query_temp("last_damage_from")) )
	{
		say(CYN+"һ��˵�������ް���٢�� ���գ����գ��������ڿ�����ȴ��Ե�ˡ�\n"+NOR);
		killer->delete_temp("tmark");
	}
	::die();
}
