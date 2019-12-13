// smith.c

inherit NPC;
inherit F_DEALER;

int do_xiuli(string arg);

void create()
{
	set_name("����", ({ "tie jiang", "smith" }));
	set("title", "�������ϰ�");
	set("shen_type", 1);
	set("gender", "����" );
	set("age", 33);
	set("long", "����������ǯ��סһ����ȵ�����Ž�¯�С�\n");
	set("combat_exp", 400);
	set("attitude", "friendly");
	set("inquiry", ([
		"����" : "��Ҫ����(xiuli)ʲô������",
		]));
	set("vendor_goods",({
		"/clone/weapon/changjian",
		"/d/city2/obj/tudao",
		"/clone/weapon/duanjian",
		"/clone/weapon/dagger",
		"/clone/weapon/staff",
		"/clone/weapon/club",
		"/clone/weapon/gangdao",
		"/clone/weapon/gangaxe",
		"/clone/weapon/feidao",
		"/clone/weapon/changbian",
		"/clone/weapon/feihuangshi",
		"/clone/weapon/tielianzi",
		}));
	
	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
	add_action("do_xiuli", "xiuli");
	add_action("do_xiuli", "����");
}

int accept_object(object who, object ob)
{
	int item_value;

	if ( !objectp(who->query_temp("item_obj")) 
		|| (item_value=who->query_temp("item_value"))<1)
	{
		tell_object(who, "����Ц���е�˵�����ðɣ������ȿ����������װ����Ҫ���ٷ��á�\n");
		tell_object(who, "����룺xiuli װ��Ӣ����\n");
		return 0;
	}
	if ( ob->query("money_id") && ob->value() >= item_value*100000 ) //ԭ��Ϊ10000
	{
		tell_object(who, "����Ц���е�˵�����ðɣ������ھͰ�������\n");
		tell_object(who, "����룺xiuli װ��Ӣ����\n");
		who->set_temp("item_xiuli",1);
		return 1;
	}

	tell_object(who, "������ֱһЦ��˵������ô��Ǯ�������ɱ�ѽ���������Ҫ"+item_value+"���ƽ�\n");
    return 0;
}

int do_xiuli(string arg)
{
	object me, item, old_item;
	mapping item_sx;
	string name;
	int item_value;

	me = this_player();

	if ( !me )
		return 0;
	if ( !arg )
		return notify_fail("����˵������Ҫ����ʲô��\n");
	if ( !objectp(item = present(arg, me)) )
		return notify_fail("����˵����������û������װ����\n");
	if ( !mapp(item_sx=item->query("backold_weapon_prop")) )
		return notify_fail("����˵����������������Ҫ����\n");
	if ( !sizeof(item_sx) )
		return notify_fail("����˵����������������Ҫ����\n");
	if ( !sscanf(item->query("name"), "�ϵ���%s", name) )
		return notify_fail("����˵����������������Ҫ����\n");

	item_value = item->query("item_old_value") * (item_sx["level"]+1);
	item_value /= 100000;//ԭ��Ϊ10000
	if ( item_value < 1 ) item_value = 1;

	if ( !me->query_temp("item_xiuli") )
	{
		me->set_temp("item_obj", item);
		me->set_temp("item_value", item_value);
		return notify_fail("����˵�����������װ����Ҫ"+item_value+"���ƽ�\n");
	}
	if ( !objectp(old_item=me->query_temp("item_obj")) || old_item != item )
		return notify_fail("����˵������ղŽ����Ĳ������װ��������ѡ�\n"+
			"����˵����������Ҫ�������װ����Ҫ"+item_value+"���ƽ�\n");

	// �ָ�װ������ֵ
	// --------------------------------------------------------------
	// �ָ�����
	while( sscanf(item->query("name"), "�ϵ���%s", name) )
		item->set("name", name);
	// �ָ�����
	item->set("weapon_prop", item->query("backold_weapon_prop"));
	item->delete("backold_weapon_prop");
	// �ָ���ֵ
	if ( item->query("item_old_value") )
	{
		item->set("value", item->query("item_old_value"));
		//item->delete("item_old_value");
	}
	// ������ɣ�������׼�¼
	me->delete_temp("item_xiuli");
	me->delete_temp("item_obj");
	me->delete_temp("item_value");
	tell_object(me, "����Ц���е�˵�����͹٣����ˣ��Ѿ��޺��ˣ��������װ������ӭ�´���������\n");
	return 1;
	// ---------------------------------------------------------------
}