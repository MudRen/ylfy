// gan.c

inherit NPC;

void create()
{
        set_name("�ʱ���", ({ "gan baobao","gan","baobao" }) );
        set("gender", "Ů��" );
//	set("title","�����ϰ�");
        set("age", 35);
        set("str", 16);
        set("cor", 24);
        set("cps", 11);
        set("per", 27);
        set("int", 27);
	set("long",
	"�ʱ�����ɫ���㣬����ƸУ�����ʱ����\n"
	"�������й�һ�η����ѻ�����������δ��\n"
	"�������ذ�ͷ����������ȥ�󣬸ʱ�����\n"
	"�����У����μ޸������Ϊ�ޡ�\n");

        set("attitude", "friendly");

        set("max_neili", 200);
        set("neili", 200);
        set("force_factor", 10);

        set("combat_exp", 35000);

        set_skill("unarmed", 60);
        set_skill("parry", 40);
        set_skill("dodge", 50);
        set_skill("sword", 30);
        set_skill("force", 50);
set_skill("yiyang-zhi",40);	

map_skill("unarmed", "yiyang-zhi");	
map_skill("parry", "yiyang-zhi");	

        setup();

        carry_object("/d/wanjiegu/obj/red-dress")->wear();
        carry_object("/d/wanjiegu/obj/shoes")->wear();
}


