// seneschal.c
// adams: 1998/06/20
inherit NPC;

void create()
{
        set_name("Ů�ܼ�", ({ "seneschal", "sen" }) );
        set("gender", "Ů��" );
	set("age", 22);
	set("long",
                "��λŮ�ܼ���Ц�����æ��������ʱ�ô��ŵ��Եļ��̡�\n");
        set("combat_exp", 1000);
	set("attitude", "friendly");
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
                        say( "Ů�ܼ�Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "�������ȱ��裬�������ְɡ�\n");
			break;
		case 1:
                        say( "Ů�ܼ�ժ�����Լ����۾���˵������λ" + RANK_D->query_respect(ob)
				+ "����������\n");
			break;
	}
}

