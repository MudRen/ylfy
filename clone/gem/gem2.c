// gems - by xbd

#include <ansi.h>

inherit ITEM;
inherit F_GEMS;
inherit F_SAVE;

void create()
{
	int lev, i;
	string gem;	

	i = random(13);
	if (i < 3) gem = "ruby";
	else if (i < 6) gem = "topaz";
	else if (i < 9) gem = "sapphire";
	/*else if (i < 12) gem = "emerald";
	else if (i < 15) gem = "amethyst";*/
	else if (i < 11) gem = "diamond";
	else gem = "skull";

	i = random(1000);
	if (i < 800) lev = 8;
	/*else if (i < 950) lev = 2;
	else if (i < 990) lev = 3;
	else if (i < 995) lev = 4;
	else if (i < 996) lev = 5;
	else if (i < 997) lev = 6;
	else if (i < 998) lev = 7;
	else lev = 8;*/
	else lev = 8;

	set_name(query_gem_name(gem, lev), ({query_gem_id(gem, lev)}));
	set_weight(100);
	set("long", query_all_effect(gem));
	set("unit", "颗");
	set("no_put",1);
	set("buy_sell",1);
    set("no_sell",1);	
	set("liebiao_gem",1);
	set("no_beg",1);
    set("owner_id",1);
	set("xyzx_save_item", 1);
	set("no_steal",1);
    set("no_clone",1);
    set("no_pawn",1);
	set("value", 100000 * lev * lev * lev);
	set("material", gem);
	set("level", lev);
	setup();
}

void init()
{
	add_action("do_insert", "insert");
	add_action("do_combine", "combine");
}

int do_insert(string arg)
{
	mapping is_bind;
	int index, i, sockets;
	string gem, item_name;
	object ob, me = this_player();

	if (!arg || arg == "")
		return notify_fail("指令格式：insert 宝石 into 物品 at socket 编号\n");
	if (sscanf(arg, "%s into %s at socket %d", gem, item_name, index) != 3)
		return notify_fail("指令格式：insert 宝石 into 物品 at socket 编号\n");
	if (gem != query("id")) return 0;
	if (!objectp(ob = present(item_name, me)))
		return notify_fail("你想把它镶嵌在什么东西上？\n");
	if (index > ob->query("sockets/max"))
		return notify_fail(ob->name() + "上好象并没有这个接孔呀！\n");
	if (ob->query("equipped"))
		return notify_fail(ob->name() + "正装备着呢！\n");
	if (me->query("max_neili") < 1000 || me->query("neili") < 1500)
		return notify_fail("以你现在的内力修为，还无法运功镶嵌宝石！\n");

	// 绑定的别人无法使用
	if ( mapp(is_bind=query("bind_master_level")) 
		&& !is_bind[me->query("id")] )
		return notify_fail("这是别人的私有物品你无法使用。\n");

	//限制嵌宝石每件物品只能有一种类型的宝石，可以不同等级
	sockets = ob->query("sockets/max");
	for (i = 1; i <= sockets; i++)
	{
		if ( strsrch(query("id"),ob->query(sprintf("sockets/socket%d", i))) != -1 && i !=index )
			return notify_fail(ob->name() + "无法同时嵌两个同种类型的宝石，在第" + i + "接孔上已嵌有这种类型的宝石了。\n" + 
			"你可以把第" + i + "接口上嵌有的宝石替换嵌上现在这个宝石。");
	}

	message_vision(HIG"$N暗运内力，一使劲把" + name() + HIG"镶入了" + ob->name() + HIG"中，
刹那间，只觉" + ob->name() + HIG"上泛出一道奇异的光芒，似乎有一股神奇的力量附在其中！\n", me);
	me->add("max_neili", -100);
	me->add("neili", -1000);
	me->start_busy(2);
	ob->set(sprintf("sockets/socket%d", index), query("material"));
	ob->set(sprintf("sockets/socket%d_level", index), query("level"));

	// 绑定的宝石镶嵌装备，那么装备也会被绑定
	if ( mapp(this_object()->query("bind_master_level")) ) {
		ob->set("bind_master_level/"+me->query("id"), 1);
		ob->set("owner_id",1);
		ob->set("xyzx_save_item", 1);
	}

	seteuid(ROOT_UID);
	reload_object(ob);
        seteuid(getuid());
	destruct(this_object());

	return 1;
}

int do_combine(string arg)
{
	string name, mat;
	int i, lvl, flag, bind_flag;
	object *inv, gem, baoshi, me = this_player();

	if ( !arg || arg == "" ) return notify_fail("你想合并什么宝石？\n");
	if ( arg != query("id") ) return 0;
	if ( (lvl=query("level")) >= 8 ) return notify_fail("这个宝石已经是最高等级了！\n");
	if ( me->query("max_neili") < 500000 || me->query("neili") < 800 ) 
		return notify_fail("以你现在的内力修为，还无法运功合并宝石！\n");

	inv = all_inventory(me);
	for ( i = 0; i < sizeof(inv); i++ )
	{
		if ( inv[i] != this_object() && inv[i]->query("id") == query("id") ) 
		{
			if ( !objectp(gem) )
				gem = inv[i];
			else 
			{
				me->add("max_neili", -random(900));
				me->add("neili", -500);
				me->start_busy(1);
				name = name();
				mat = query("material");

				// 绑定的宝石镶嵌装备，那么装备也会被绑定
				bind_flag = 0;
				if ( mapp(this_object()->query("bind_master_level")) 
					|| mapp(gem->query("bind_master_level")) 
					|| mapp(inv[i]->query("bind_master_level")) ) {
					bind_flag = 1;
				}

				if ( random(10) > lvl )
				{
					destruct(gem);
					destruct(inv[i]);
					message_vision(HIG"$N暗运内力劲透宝石，但见" + name + 
						HIG"表面异彩流动，渐渐的$N收回了内力，只觉" + name + HIG"似乎变得更加完美了！\n", me);
					baoshi = new_gem(mat, lvl + 1);
					if ( bind_flag == 1 )
						baoshi->set("bind_master_level/"+me->query("id"), 1);
					baoshi->move(me);
					destruct(this_object());
				}
				else
				{
					flag = random(3);
					message_vision(HIW"$N暗运内力劲透宝石，但听" +  
						HIW"“咔哧”声连连响起，" + 
						chinese_number(flag+1) + "颗" + name + 
						HIW"经不住内劲的催动既被震成了丝丝粉末飘下。\n", me);
					switch ( flag )
					{
						case 2 : destruct(gem);
						case 1 : destruct(inv[i]);
						case 0 : destruct(this_object());
					}
				}
				return 1;
			}
		}
	}
	return notify_fail("你必须有三块同样的宝石才能进行合并！\n");
}