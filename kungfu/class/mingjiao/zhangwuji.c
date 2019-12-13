//zhangwuji.c

#include <ansi.h>

inherit F_MASTER;
inherit F_UNIQUE;
inherit NPC;

void greeting(object ob);
void create()
{
    seteuid(getuid());
	set_name("���޼�", ({ "zhang wuji", "zhang", "wuji" }));
	set("long", "���̽������޼ɣ�ͳ������ʮ����ڣ��������ƣ�߳��ǧ�\n"
               +"�������񹦡�����Ǭ����Ų�ơ��������£��ǽ����в�������\n"
               +"����Ӣ�ۡ�\n");
    set("title","���̽���");
	set("gender", "����");
    set("age", 20);
	set("shen_type",1);
    set("attitude", "friendly");

    set("str", 30);
    set("int", 30);
    set("con", 30);
    set("dex", 30);

    set("qi", 330050);
    set("max_qi", 330050);
    set("jing", 30050);
    set("max_jing", 30050);
    set("neili", 5000000);
    set("max_neili", 1000000);
    set("jiali", 22200);
    set("xyzx_sys/level", 1000);//2015.9��������������޼ɵ��õ���d/mingjiao/npc���
    set("combat_exp", 29000000);
    set("score", 455000);
    
    set_skill("force", 3750);
    set_skill("unarmed", 3740);
    set_skill("dodge", 3700);
    set_skill("parry", 3755);
//  set_skill("hand",370)
    set_skill("sword",3700);
    set_skill("blade", 3700);
    set_skill("jiuyang-shengong", 1600);
    set_skill("qiankundanuoyi", 1650);
    set_skill("qishang-quan", 1700);
    set_skill("wuxue-shenfa", 1550);
    set_skill("taiji-quan",1600);
    set_skill("taiji-jian",1630);
    set_skill("literate",3380);

	map_skill("force", "jiuyang-shengong");
    map_skill("dodge", "qiankundanuoyi");
    map_skill("dodge", "wuxue-shenfa");
    map_skill("unarmed", "taiji-quan");
	map_skill("sword","taiji-jian");
    map_skill("parry","qiankun-danuoyi");

    create_family("����",34, "����");

		set("chat_chance",3000);
       set("chat_msg",({
         "���޼ɷ�Ȼ˵�������ɷ��Թ�Ϊ��, ����ɳ��, ��Ԫ��ҵδ��, ͬ������Ŭ��!��\n",
        "���޼ɵ����ҽ��ֵ�����: ��������, ���˼�Ϊ��, ��������, ������ħ!��\n",
//            "���޼ɵ����ҽ��ֵ�����: ��������, ���˼�Ϊ��, ��������, ������ħ!��\n",
            (: random_move :)
             }));

//        set("inquiry",(
//       "����" : "�������ڱ�д֮�У�����Ժ�\n",
//    "��ëʨ��" :
//    "лѷ" :
//             ]))
		setup();
		carry_object("/d/mingjiao/obj/yitianjian")->wield();
//    	carry_object("/d/mingjiao/obj/jiaozhumingpao")->wear();
		add_money("gold",70);
}

void init()
{
	object ob;

	::init();

	if( interactive(ob=this_player()) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting",1,ob);
	}
}

void greeting(object ob)
{
	if(!ob || environment(ob)!=environment()) return;
	if((int)ob->query("shen")<-50000)
	{
//      command("say
		command("wield yitian jian");
		command("hit"+(string)ob->query("id"));
		command("unwield uitian jian");
	}
	else if((int)ob->query("shen")<-5000)
	{
		command("say ħ����������ѧ������������Ȱ���������������سɷ�.");
	}
	else if((int)ob->query("shen")<-100)
	{
		command("say ��λ���ѣ����н��������е����������߽�аħ���.");
	}
	else if((int)ob->query("shen")>=0)
	{
		command("say �������������ߣ�Ȱ����ӱ���.");
	}
	else if((int)ob->query("shen")>10000)
	{
		command("say �������ϣ����޼�һ�񣬴������ձ�Ϊ�����̳�.");
	}
	return;
}



void attempt_apprentice(object ob)
{
	if((int)ob->query("int")<30)
	{
		command("say �������̫���ˣ����ʺ�ѧϰ�ҵĹ���");
		return 0;
	}
	if((string)ob->query("gender")!="����")
	{
		command("say ���������㣬ϰ�ҹ���ֽ��߻���ħ��");
		return 0;
	}
	if((int)ob->query("shen") <= 15000)
	{
		command("say ��Ӧ������Щ����������£��������ġ�");
		return 0;
	}
	command("say �ã��Ҿ���������λ���ֵ�");
	command("say �ٽ����£�");
	return;
}

int accept_fight(object ob)
{
    if(((int)ob->query("combat_exp")<30000)&&((int)ob->query("shen")>0))
    {
        message_vision("�������������ǿ���ݣ��㲻���ҵĶ��֣���ȥ�ɡ�\n",ob);
        return 0;
    }
    message_vision("���޼�һ����˵������λ"+RANK_D->query_respect(ob)+
	"����������ˡ�\n", ob);
    return 1;
}


