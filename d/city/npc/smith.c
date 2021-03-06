// smith.c

inherit NPC;
inherit F_DEALER;

int do_xiuli(string arg);

void create()
{
	set_name("铁匠", ({ "tie jiang", "smith" }));
	set("title", "铁匠铺老板");
	set("shen_type", 1);
	set("gender", "男性" );
	set("age", 33);
	set("long", "铁匠正用铁钳夹住一块红热的铁块放进炉中。\n");
	set("combat_exp", 400);
	set("attitude", "friendly");
	set("inquiry", ([
		"修理" : "你要修理(xiuli)什么武器？",
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
	add_action("do_xiuli", "修理");
}

int accept_object(object who, object ob)
{
	int item_value;

	if ( !objectp(who->query_temp("item_obj")) 
		|| (item_value=who->query_temp("item_value"))<1)
	{
		tell_object(who, "铁匠笑眯眯地说到：好吧，让我先看看修理你的装备需要多少费用。\n");
		tell_object(who, "请键入：xiuli 装备英文名\n");
		return 0;
	}
	if ( ob->query("money_id") && ob->value() >= item_value*100000 ) //原来为10000
	{
		tell_object(who, "铁匠笑眯眯地说到：好吧，我现在就帮你修理。\n");
		tell_object(who, "请键入：xiuli 装备英文名\n");
		who->set_temp("item_xiuli",1);
		return 1;
	}

	tell_object(who, "铁匠耿直一笑，说道：这么点钱还不够成本呀，修理费需要"+item_value+"两黄金。\n");
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
		return notify_fail("铁匠说道：你要修理什么？\n");
	if ( !objectp(item = present(arg, me)) )
		return notify_fail("铁匠说道：你身上没有这样装备。\n");
	if ( !mapp(item_sx=item->query("backold_weapon_prop")) )
		return notify_fail("铁匠说道：这样东西不需要修理。\n");
	if ( !sizeof(item_sx) )
		return notify_fail("铁匠说道：这样东西不需要修理。\n");
	if ( !sscanf(item->query("name"), "断掉的%s", name) )
		return notify_fail("铁匠说道：这样东西不需要修理。\n");

	item_value = item->query("item_old_value") * (item_sx["level"]+1);
	item_value /= 100000;//原来为10000
	if ( item_value < 1 ) item_value = 1;

	if ( !me->query_temp("item_xiuli") )
	{
		me->set_temp("item_obj", item);
		me->set_temp("item_value", item_value);
		return notify_fail("铁匠说道：修理这件装备需要"+item_value+"两黄金。\n");
	}
	if ( !objectp(old_item=me->query_temp("item_obj")) || old_item != item )
		return notify_fail("铁匠说道：你刚才交付的不是这件装备的修理费。\n"+
			"铁匠说道：如你想要修理这件装备需要"+item_value+"两黄金。\n");

	// 恢复装备属性值
	// --------------------------------------------------------------
	// 恢复名称
	while( sscanf(item->query("name"), "断掉的%s", name) )
		item->set("name", name);
	// 恢复属性
	item->set("weapon_prop", item->query("backold_weapon_prop"));
	item->delete("backold_weapon_prop");
	// 恢复价值
	if ( item->query("item_old_value") )
	{
		item->set("value", item->query("item_old_value"));
		//item->delete("item_old_value");
	}
	// 修理完成，清除交易记录
	me->delete_temp("item_xiuli");
	me->delete_temp("item_obj");
	me->delete_temp("item_value");
	tell_object(me, "铁匠笑眯眯地说到：客官，好了，已经修好了，这是你的装备。欢迎下次再来！。\n");
	return 1;
	// ---------------------------------------------------------------
}