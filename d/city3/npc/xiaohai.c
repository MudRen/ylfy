// xiao-hai.c

inherit NPC;

void create()
{
        set_name("С��",({ "xiao hai", "hai" }) );
        set("gender", "����" );
        set("age", 11);
        set("long", "С������ʲô�ÿ��ġ�\n");
//	set("shen_type", 1);
        set("combat_exp", 50);
        set("shen", 50);
	set("str", 11);
	set("dex", 11);
	set("con", 11);
	set("int", 11);
        set("attitude", "heroism");
        setup();
	carry_object("clone/cloth/cloth")->wear();
}

