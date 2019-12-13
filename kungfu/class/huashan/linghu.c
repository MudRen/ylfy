// linghu.c �����

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("�����", ({ "ling huchong", "ling", "huchong" }));
	set("nickname", "��ʦ��");
	set("long", 
"�����Ľ��ݣ�����Ũü���ۣ������Ѱ�������ͬ���������ϴ�\n"
"�ǻ�ɽ������һ���еĶ�����֡�\n");
	set("gender", "����");
	set("age", 28);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
	
	set("qi", 2800000);
	set("max_qi", 2800000);
	set("jing", 1600000);
	set("max_jing", 1600000);
	set("neili", 24000000);
	set("max_neili", 7000000);
	set("jiali", 16000);
    set("xyzx_sys/level", 1500);
	set("combat_exp", 800000);
	set("score", 100000);

    set_skill("yijing-force",2000);
	set_skill("blade", 2300);
	set_skill("feiyan-huixiang", 2120);	
	set_skill("unarmed",2125);
	set_skill("force", 2150);
	set_skill("zixia-shengong", 2130);
	set_skill("dodge", 2180);
	set_skill("parry", 2140);
	set_skill("sword", 2190);
    set_skill("huashan-jianfa", 2190);	
    set_skill("dugu-jiujian",3160);	
	set_skill("literate", 1380);

	map_skill("force", "zixia-shengong");
	map_skill("unarmed", "huashan-zhangfa");
	map_skill("dodge", "feiyan-huixiang");
    map_skill("parry", "dugu-jiujian");	
    map_skill("sword", "dugu-jiujian");	

	create_family("��ɽ��", 14, "����");

	set("inquiry", ([
		
		"������" : "�����Ѿ��ܾ�û�м��������˼��ˡ���������\n",
		"��ӯӯ" : "������������Ϣ��,˵��,�Լ������鼤��,�����۾����ģ�\n",
	    		   	]));
	setup();	 	
	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/heimuya/npc/obj/card2")->wear();
}


void init()

{
	object ob;
	ob = this_player();	
	::init();
	if( interactive(ob) && !is_fighting() )
	       {
			remove_call_out("greeting");
			call_out("greeting", 1, ob);
		}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	say("���ղ��ܼ���ӯӯ��!" + RANK_D->query_respect(ob)
	  +"�������������Ϣ?\n");
}

int accept_object(object who, object ob)
{
	object obn;

	if( !who || environment(who) != environment() ) return 0;
	if ( !objectp(ob) ) return 0;
	if ( !present(ob, who) ) return notify_fail("��û�����������\n");

	if (  (string)ob->query("id") != "qing xin")
		    return notify_fail("����岻��Ҫ���������\n");
       say( "�����˫��������ӯӯ���ţ���������, ���׻�����������ȥ����ӯӯ,
�������Ҿ�ȥ����!\n" );
	obn = new("/d/heimuya/npc/obj/card2");
    obn->set_amount(1);
	obn->move(who);
    destruct(obn);
    set_temp("card2",0);
    return 1;
}




void attempt_apprentice(object ob)
{
	int student_num;
	string temp, line;
	mapping myfam;

	temp = read_file("/kungfu/class/huashan/FENG", 1, 1);
	student_num = atoi(temp);

	line = "���������ڹ���" + temp + "��ͽ�ܡ�\n";
	write(line);

	if ((int)ob->query("shen") < 0) {
		command("say �һ�ɽ�����������������ɣ��Ե���Ҫ���ϡ�");
		command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
			"�Ƿ����ò�����");
		return;
	}

	if ((int)ob->query_int() < 25) {
		command("say ���ҿ�" + RANK_D->query_respect(ob) + "�������ƺ����ʺ�ѧ�һ�ɽ���书��");
		return;
	}

	command("say �ðɣ��Ҿ��������ˡ�");
	command("recruit " + ob->query("id"));
	if((string)ob->query("class") != "swordsman")
		ob->set("class", "swordsman");

	        myfam = (mapping)ob->query("family");
 		if( (myfam["master_id"] == "feng qingyang") || (myfam["master_name"] == "������"))
		{
			temp = read_file("/kungfu/class/huashan/FENG", 1, 1);
			student_num = atoi(temp);
			if(student_num == 1)
				temp = "0";
			else if(student_num == 2)
				temp = "1";
			else if(student_num == 3)
				temp = "2";
			write_file("/kungfu/class/huashan/FENG", temp, 1);
			line = "���������ڹ���" + temp + "��ͽ�ܡ�\n";
			write(line);
		}
   return;
}
