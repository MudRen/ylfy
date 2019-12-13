// wangerniang.c ������

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("������", ({ "wang erniang", "wang", "erniang" }) );
	set("gender", "Ů��" );
	set("age", 53);
	set("long",
		"��������50�����ˣ�����������ϣ������ȴ档\n��˵�������Ϲ�������岻���ġ�\n");
	set("combat_exp", 7000);
	set("attitude", "friendly");
	set("rank_info/respect", "������");
	set("vendor_goods", ({
		       "/clone/food/jiudai",
                "/d/city/obj/jiaohuaji",
	}));
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	add_money("silver",20);
}

void init()
{	
	object ob; 
	mapping myfam; 

	ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() ) {
		if ( (myfam = ob->query("family")) 
		&& myfam["family_name"] == "ؤ��" 
		&& ob->query_skill("begging",1) > 10 )
		{
			remove_call_out("saying");
			call_out("saying", 0, ob);
		}
		else
		{ 
			remove_call_out("greeting");
			call_out("greeting", 1, ob);
		}
	}

	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			say( "������Ц�����˵������λ" + RANK_D->query_respect(ob)
				+ "������ҪЩʲô��\n");
			break;
		case 1:
			say( "������Ц�����ؿ����㣬˵������λ" + RANK_D->query_respect(ob)
				+ "����������\n");
			break;
	}
}

void saying(object ob)
{
        if (!ob || environment(ob) != environment()) return;

	say("\n�������ݺݵ����������������������ĺ��¡�\n\n");
	remove_call_out("kicking");
	call_out("kicking", 1, ob);
	
}

void kicking(object ob)
{
        if (!ob || environment(ob) != environment()) return;

        ob->move("/d/city3/xiaojie3");
	message("vision","ֻ����ƹ����һ����" +  ob->query("name") +
                "���˴������һ�����˳������Ǳ���״���ӿ��ˡ�\n", environment(ob), ob);
}
