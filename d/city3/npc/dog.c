// dog.c
// adams: 1998/06/20

inherit NPC;

void create()
{
        set_name("���ﹷ", ({ "dog" }) );
	set("race", "Ұ��");
	set("age", 3);
        set("long", "һֻ�����˰�ë�ĳ��ﹷ��\n");
	
	set("str", 32);
	set("dex", 36);

	set("chat_msg", ({
		(: this_object(), "random_move" :),
                "���ﹷ�ñ�����������Ľš�\n",
                "���ﹷ����Ľű߰��������ģ����ֶ����ԡ�\n",
                "���ﹷ������ҡ��ҡβ�͡�\n",
                "���ﹷ������ץ��ץ�Լ��Ķ��䡣\n" }) );
		
	setup();
}

int accept_object(object who, object ob)
{
	if( ob->id("bone") ) {
		set_leader(who);
		message("vision", name() + "���˵���������������\n", environment());
		return 1;
	}
}
