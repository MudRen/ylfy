
inherit NPC;
inherit F_DEALER;
void create()
{
	set_name("���ƹ�", ({ "hu zhanggui", "hu" }));
	set("title", "�ӻ����ϰ�");
	set("shen_type", 1);
	set("gender", "����");
	set("age", 45);
	set("long",
		"�𿴺��ƹ�����������ģ������������þ����ء�\n"+
		"���ⱱ�����ܻ����������������ôҲ���м��ֱ��¡�\n");
	set_skill("unarmed", 60);
	set_skill("parry", 60);
	set_skill("dodge", 60);
	set_temp("apply/damage", 25);
	set("combat_exp", 50000);
	set("attitude", "friendly");
	set("vendor_goods", ({
		       "/d/city2/obj/diaopi",
                "/d/city/obj/sleepbag",
		       "/d/city/obj/beixin",
                "/d/quanzhou/obj/xiuhua",
                "/clone/cloth/flower_shoe",
                "/clone/cloth/pink_cloth",
  	}));
	
	setup();
	carry_object("/clone/cloth/cloth")->wear();
}
void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
