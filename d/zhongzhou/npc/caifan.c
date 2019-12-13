inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("�˷���", ({ "cai fan", "cai", "fan" }) );
	set("gender", "����" );
	set("age", 32);
	set("long",
		"һ����ʵ�ͽ���ũ����Щ���ʵ��߲ˡ�\n");
	set("shen_type", 1);
	set("combat_exp", 10000);
       set("str", 10);
       set("dex", 10);
       set("con", 10);
       set("int", 10);
	set("attitude", "peaceful");
       set_skill("dodge",20);
       set_skill("unarmed",20);
       set("chat_chance", 10);
       set("chat_msg", ({
                "�˷��ӽе��������ʵ��ܲ�ߺ��\n",
                "�˷��ӽе��������ʵĺ��ܲ�ߺ��\n",
                "�˷��ӽе��������ʵİײ�ߺ��\n",
                "�˷��ӽе��������ʵĴ��ߺ��\n",
                "�˷��ӽе��������ʵ�����ߺ��\n",
        }) );       

	set("vendor_goods", ({
		"d/zhongzhou/obj/luobo",
		"d/zhongzhou/obj/huluobo",
		"d/zhongzhou/obj/baicai",
		"d/zhongzhou/obj/dacong",
		"d/zhongzhou/obj/tudou",
	}) );

	setup();
       carry_object("/clone/cloth/cloth")->wear();
	add_money("coin", 80);
}
void init()
{
        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}
