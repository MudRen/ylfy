// mu.c

inherit NPC;

void create()
{
        set_name("ľ����", ({ "mu wanqing","mu" }) );
        set("gender", "Ů��" );
        set("age", 17);
        set("str", 26);
        set("cor", 24);
        set("cps", 21);
        set("per", 28);
        set("int", 27);
	set("long",
	"һ�����������ף����������ͣ��绨����ѩ��\n"
	"����ȥ����������������ת��ֻ�ǳ�ʱ����Ļ\n"
	"��֮�ʣ���ɫ�԰ף�û���Ѫɫ����Ƭ������\n"
	"�촽��Ҳ��Ѫɫ������\n");

        set("attitude", "friendly");

	        set("inquiry", ([
                "����" : "�θ���أ������Ķ���˵�꣬ľ����������ֳ�һ˿���Ρ�",
                "����" : "��������Ѿͷ���ߣ�",
                "ľ����" : "�Ҿ���ľ���塣",
]));

        set("max_neili", 200);
        set("neili", 200);
        set("force_factor", 50);

        set("combat_exp", 550000);

        set_skill("unarmed", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("sword", 100);
        set_skill("force", 100);
        set_skill("yiyang-zhi",100);	
       map_skill("unarmed", "yiyang-zhi");	
       map_skill("parry", "yiyang-zhi");	

        setup();

        carry_object("/d/wanjiegu/obj/pink-dress")->wear();
        carry_object("/d/wanjiegu/obj/shoes")->wear();
}

int accept_object(object who, object ob) 
{
	if (ob->name() == "���黨") {
	   message_vision("$N�ó�һ����黨��ľ����\n",who);
	   call_out("do_give", 1, who );
	   return 1;
	}
	return 0;
}

void do_give(object me)
{
       object ob;	
        message_vision("ľ���彫���黨������ȥ�����еġ������Ϻ�ɢ����ҩ�Խ���ˣ�\n",me);
        command("say ̫лл�ˣ������Ҫ�뿪���Ƿ�֮�أ���...��ű�ˮ����������������.....������ڣ�");	
        message_vision("ľ����ȡ��һ����������һ�ף���Ӱ���һ����˳�ȥ��\n",me);
        message_vision("ֻ������Ų�������Զȥ��������׷�˹�ȥ��\n", me);
        ob=new("/d/shaolin/obj/bszhu");
        ob->move("/d/wanjiegu/stone_room");
        me->add("combat_exp",random(60)+ 20 );
        me->add("potential",random(30) + 20);

        destruct( this_object() );
}

