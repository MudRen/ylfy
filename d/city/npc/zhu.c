// zhu.c �쵤��
// CLEANSWORD 1996/2/2
inherit NPC;
void create()
{
	set_name("����", ({ "zhu xi", "zhu" }));
	set("long","����������Ϊ������һ����ѧ�ң��������īˮ�Ⱥ���Ҫ�\n");
	set("gender", "����");
	set("age", 65);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 25);
	set("int", 30);
	set("con", 25);
	set("dex", 25);
	set("max_qi", 1000);
	set("max_jing", 1500000);
	set("max_jingli", 350);
	set("jingli", 3500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 50);
	set("combat_exp", 3500000);
	set("score", 110000);
	set_skill("literate", 300);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 20);
	
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	add_money("gold",2);
	
	set("chat_chance", 3);
	set("chat_msg", ({
		"����˵��������֮�£�Ī������������֮����Ī��������\n",
		"����˵���������ˣ�С�������ɣ����������δ������֮��\n",
		"����˵������ѧ֮�����������¡���������ֹ�����ơ� \n",
		"����˵����������֪���������ģ�������ң��ι�ƽ���¡�\n",
		}) );
}

void init()
{
	::init();

	add_action("do_learn","learn");
}

int accept_object(object who, object ob)
{
	int learn;
	
	learn=who->query_skill("literate",1);
	learn= learn?learn*10:500;
		
	//��ֹ���
	if(who->query("dushu") + 1 < 1)              
	{
		say(this_object()->name()+"Ц����������ô����˼�����ϴθ���Ǯ��û�����أ���\n");
		return 0;
	}

	//��ֹ��� 
	if(ob->value()/15 + who->query("dushu") < 0)
	{
		say(this_object()->name()+"�ܳ�������˵������ô��Ǯ�ҿɲ�����ѽ����\n");    	
		return 0;
	}
	
	//�Դﵽ300������д�ֵ���Ҹ�����ʾ���������ѧϰ
	if (who->query_skill("literate",1) >= 300)
	{
		say(this_object()->name()+"���˵�ͷ��˵������Ŷ��������ô���ĵ�ѧ�������ǲ��������������ѧʶ����ֻ�ܽ��㵽���ˡ�\n                      ��˵�����쵤�����Ǹ���ѧ��ţ����ɶ�õ��˲�ѽ��������ȥ�Ǵ����¿�������\n");
		return 0;
	}
	
	if( !who->query("dushu") )
	{
		if( ob->value() >= learn )
		{
			say(this_object()->name()+"���˵�ͷ��˵����Ŷ�������������ĵ�ѧ�������ǲ�������ú�Ŭ��\n                      ����������̶���д��(literate)���κ����⡣\n");
			who->set("dushu", ob->value()/15);
			return 1;
		}
		else
		{
			say(this_object()->name()+"˵������ĳ��ⲻ������Ǯ�����û�ȥ�ɡ�\n");
			return 0;
		}
	}
	else if(ob->value())
	{
		if( ob->value() >= learn )
		{
			say(this_object()->name()+"���˵�ͷ��˵����Ŷ�������������ĵ�ѧ�������ǲ�������ú�Ŭ��\n                      �����ض�ǰ;������л�ˡ�\n");
			who->add("dushu", ob->value()/15);
			return 1;
		}
		else
		{
			say(this_object()->name()+"˵������ĳ��ⲻ������Ǯ�����û�ȥ�ɡ�\n");
			return 0;
		}
	}
        return 1;
}

int do_learn(string arg)
{
	string skill, teacher;
	object me,ob,room;
	int learn,times,i;
	int master_skill, my_skill, gin_cost, my_combat_exp,grade;
	
	me=this_player();
	ob=this_object();
	
	if (me->is_busy())
		return notify_fail("��������æ���ء�\n");
	
	if(!arg || arg=="?" || arg=="/?")
		return notify_fail("ָ���ʽ��learn <ĳ��> <����> <����>\tlearn <����> at <����> from <ĳ��>\n");
	
	if ((sscanf(arg, "%s at %d from %s", skill,times,teacher)!=3 ))
	if ((sscanf(arg, "%s %s %d", teacher, skill,times)!=3 ))
		return notify_fail("ָ���ʽ��learn <ĳ��> <����> <����>\tlearn <����> at <����> from <ĳ��>\n");
	
	if (!ob->id(teacher))
		return 0;
	
	if( me->is_fighting() )
		return notify_fail("����ĥǹ������������\n");
	
	if ((int)times>99)
		return notify_fail("һ��ѧ��ô��,С���۵���Ŷ~\n");
	
	//if(me->query("learn_cuowu"))   return notify_fail(HIR"��������������������ʦ��\n"NOR);
	//if ((int)times<1)    me->set("learn_cuowu",1);
	
	if ((int)times<1)
		return notify_fail("��Ҫѧ���Σ�\n");
	
	if( !living(ob) )
		return notify_fail("��....����Ȱ�" + ob->name() + "Ū����˵��\n");

	if (me->query_skill("literate",1) >=300 && me->query("dushu"))
	{
		command("say ��...."+me->name()+"����ѧϰ���ù�������ֻ�ܽ��㵽���ˡ�����Ҷ��Ǯ����ת���������쵤���ˣ���ȥ���Ǽ���ѧϰ�ɡ�\n");
		return 0;
	}

	learn=me->query_skill("literate",1);
	
	if( !me->query("dushu") || me->query("dushu")<times*learn)
	{
		command("say �ף�"+me->name()+"���Ҳ��ǵ��չ������ѧ����....\n");
		return 0;
	}
        if (!learn)     learn=10;
        if (skill!="literate")
                return notify_fail("���������±����ұ���ѧ�ˡ�\n");
        if (! room=find_object(ob->query("startroom")))
                room=load_object(ob->query("startroom"));
        if (room!=environment()){
                command("say �ҳ�������£����һ�ȥ��˵�ɣ�");
                return 1;
        }
        if (ob->query("jing<30"))
{
                 ob->set("env/no_teach",1);
                command("say �ҽ������ˣ���Ҫȥ��Ϣ�ˣ�");
                return 1;
        }
        my_skill = me->query_skill(skill, 1);
        master_skill = ob->query_skill(skill, 1);
        if( my_skill >= master_skill )
                return notify_fail("�������ĳ̶��Ѿ�������ʦ���ˡ�\n");
        gin_cost = 150 / (int)me->query_int() + 1;
        if( !my_skill ) {
                gin_cost *= 2;
                me->set_skill(skill,0);
        }
        printf("����%s����йء�%s�������ʡ�\n", ob->name(), to_chinese(skill));
         if( (int)ob->query("jing") > 20)
        {
                ob->receive_damage("jing", gin_cost/10+1);
        }
        else
        {
                write("����" + ob->name() + "��Ȼ̫���ˣ�û�а취����ʲ�ᡣ\n");
                ob->set("env/no_teach",1);
                call_out("do_sleep",1,ob);
                return 1;
        }
                
        my_combat_exp = (int)me->query("combat_exp");
        if(my_combat_exp < 10000)
                grade = 1;
        else if(my_combat_exp < 80000)
                grade = 3;
        else if(my_combat_exp < 500000)
                grade = 7;
        else
                grade = 13;
        if ( grade < 1 )
                grade = 1;
        if((int)me->query("jing") > times*gin_cost+10 )
        {
                printf("������%s��ָ�����ƺ���Щ�ĵá�\n", ob->name());
                for (i=0;i<times ;i++ )
                {
					me->improve_skill(skill, grade * (10 + random((int)me->query_int() - 9)));
				}        
		}
        else
        {
                write("�����̫���ˣ����ʲôҲû��ѧ����\n");
              return 1;
        }
        me->receive_damage("jing", times*gin_cost );
        me->add("dushu", -times*learn);
        return 1;
}
int do_sleep(object ob)
{
        object room;
        if (!ob)        return  0;
        message("vision",ob->name()+"�����۾����ط�˯��ȥ�ˡ�\n",environment(ob));
        if (!room=find_object("/d/city/shuyuan2"))
                room=load_object("/d/city/shuyuan2");
        ob->move(room);
        command("sleep");
        call_out("do_back",20,ob);
        return 1;
}
int do_back(object ob)
{
        object room;
        if (!ob)        return 0;
        if (!living(ob)){
                remove_call_out("do_back");
                call_out("do_back",10,ob);
        }
        ob->delete("short");
        ob->delete("env");
        if (!room=find_object(ob->query("startroom")))
                room=load_object(ob->query("startroom"));
        ob->move(room);
        message("vision",ob->name()+"���������������˹�����\n",room);
        return 1;
}
int return_home(object home)
{
        if( !environment()
        ||      environment()==home )
                return 1;
        // Are we able to leave?
        if( !living(this_object())
        ||      is_fighting()
        ||      !mapp(environment()->query("exits")) ){ call_out("return_home",10,home); return 1;}
        // Leave for home now.
        message("vision", this_object()->name() + "����ææ���뿪�ˡ�\n",
                environment(), this_object());
        return move(home);
}