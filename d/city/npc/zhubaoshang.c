// seller.c
inherit NPC;
inherit "/feature/baoshi.c";

void create()
{
    set_name("��ջ�", ({ "jin juhua", "jin" }) );
    set("gender", "Ů��" );
    set("age", 35);
    set("long",
        "����Ƶ���Ů������˵������������鱦���⣬�ղ��в��ٵĽ����鱦��\n" +
		"��Ϊ�����С�������Ǳ��ý��裬��С�ʹ����������Ҳ����Ư��������ʱ\n" +
		"��֪�Ե������ټҹ��ӣ��㿴����������������Ƿ����̴�,����Ǯ�ϱ�����׷�ÿɽ��ء�\n");
	set("shen_type", 1);
	set("combat_exp", 300);
	set("str", 17);
	set("dex", 20);
	set("con", 17);
	set("int", 22);
    set("attitude", "peaceful");
    setup();
	carry_object("/clone/cloth/cloth")->wear();
	add_money("coin", 100);
}

void init()
{
	if (base_name(environment())!=this_object()->query("startroom"))
		return;
	
	add_action("do_cun", "cun");
	add_action("do_qu", "qu");
	add_action("do_chaxun", "chaxun");
}

void die()
{
	message_vision("\n$N���ˡ�\n", this_object());
	destruct(this_object());
}
