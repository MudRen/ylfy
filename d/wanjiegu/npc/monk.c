// monk.c

inherit NPC;
int savemu();

void create()
{
        set_name("��ü��ɮ", ({ "monk" }) );
        set("gender", "����" );
        set("age", 52);
        set("str", 24);
        set("cor", 23);
        set("cps", 23);
        set("per", 23);
        set("int", 23);
	set("long",
	"һ���������ơ�üë���Ƶ���ɮ����������һ��\n"
	"�����С����ľ�㣬���־���һ���������ľ��\n"
	"���ľ�㴸��\n");

        set("attitude", "friendly");

	set("inquiry", ([
		"����" : (: savemu :),
		"��ľ����" : (: savemu :),
		"help" : (: savemu :),
	]) );

        set("max_neili", 1000);
        set("neili", 1000);
        set("force_factor", 60);

        set("combat_exp", 2000000);

        set_skill("unarmed", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("hammer", 100);
        set_skill("force", 100);
set_skill("yiyang-zhi",100);	
set_skill("hunyuan-yiqi", 120);     	


map_skill("unarmed", "yiyang-zhi");	


        setup();

        carry_object("/d/wanjiegu/obj/cloth")->wear();
        carry_object("/d/wanjiegu/obj/bu-shoes")->wear();
        carry_object("/d/wanjiegu/obj/muyu")->wield();
}

int savemu()
{
	object obj;

	if(obj = present("duan yanqing", environment(this_object()) ) ) {
	    command("say �ðɣ����ý�ҩ��ľ���������ס�����졣\n");
	    this_object()->kill_ob(obj);
	    obj->kill_ob(this_object() );
	} else 
	    command("say ľ���������棬���ý�ҩ������\n");
	return 1;
}

