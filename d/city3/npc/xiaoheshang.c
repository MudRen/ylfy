// Npc: /chengdu/npc/xiaoheshang.c
// Date: oooc 1998/06/26

inherit NPC;


void create()
{
        set_name("С����", ({
                "xiao heshang",
                "xiao",
                "heshang",
	}));
	set("long",
                "����λ����ĺ���,�����ϵ�����,�����϶���λ�õ���ɮ��\n"
	);


	set("gender", "����");
	set("attitude", "peaceful");
	set("class", "bonze");

        set("age", 14);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
        set("max_qi", 100);
        set("max_jing", 100);
	set("neili", 100);
	set("max_neili", 100);
        set("combat_exp", 1000);
        set("score", 50);

        set_skill("force", 8);
        set_skill("dodge", 8);
        set_skill("unarmed", 8);
        set_skill("parry", 8);

	setup();

}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
            say( "С����˫�ֺ�ʲ˵������λʩ������������?\n");
			break;
		case 1:
            say( "С�����������Լ��Ĺ�ͷ��˵������λ" + RANK_D->query_respect(ob)
				+ "����������\n");
			break;
	}
}

