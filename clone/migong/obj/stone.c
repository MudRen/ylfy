// 合成材料：珍稀之石

inherit ITEM;
inherit F_SAVE;

nosave mapping stone_name = ([
	"日辉" : "rihui",
	"月华" : "yuehua",
	"冰魄" : "bingpo",
	"雷鸣" : "leiming",
	"紫云" : "ziyun",
	"风啸" : "fengxiao",
	"黑冥" : "heiming",
	"聚神" : "jushen",
	"清心" : "qingxin",
	"灿金" : "canjin",
	"封印" : "qingxin",
	"补天" : "butian",
	"青郁" : "qingxin",
	"混土" : "huntu",
	"蕴水" : "yunshui",
	"覆火" : "fuhuo",
	"烁光" : "shuoguang",
	"幕天" : "mutian",
	"镇地" : "zhendi",
	]);

nosave mapping stone_color = ([
	"日辉" : HIR,
	"月华" : CYN,
	"冰魄" : HIW,
	"雷鸣" : HIB,
	"紫云" : HIM,
	"风啸" : HIW,
	"黑冥" : WHT,
	"聚神" : MAG,
	"清心" : HIW,
	"灿金" : HIY,
	"封印" : YEL,
	"补天" : HIC,
	"青郁" : GRN,
	"混土" : YEL,
	"蕴水" : GRN,
	"覆火" : HIY,
	"烁光" : HIW,
	"幕天" : HIC,
	"镇地" : YEL,
	]);

nosave string *stone_level_name = ({
	"①细碎的",
	"②粗糙的",
	"③标准的",
	"④精致的",
	"⑤完美的",
	"⑥出奇的",
	"⑦入圣的",
	"⑧神化的",
	"⑨仙蕴的",
	"⑩天罗的",
	});

nosave string *stone_level_id = ({
	"xisui",
	"cucao",
	"biaozhun",
	"jingzhi",
	"wanmei",
	"chuqi",
	"rusheng",
	"shenhua",
	"xianyun",
	"tianluo",
	});

void create()
{
	string *names, name;
	string color;
	int flag, lvl;

	names = keys(stone_name);
	flag = random(sizeof(names));
	name = names[flag];
	lvl = random(sizeof(stone_level_id));
	if ( random(100) < 80 ) lvl /= 2;
	color = stone_color[name];

	set_name(color+stone_level_name[lvl]+name+"之石"NOR, ({stone_level_id[lvl]+" "+stone_name[name]+" stone"}));
	set("long", "一颗有着奇异光泽的石头，似乎是某种物品的合成材料。表面有着细微的凹槽看起来还可以进行组合(zuhe).\n");
	set_weight(15);
	set("stone_level", lvl+1);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "颗");
		set("value", 1);
		set("owner_id",1);
		set("xyzx_save_item", 1);
	}

	setup();
}

void init()
{
    if ( environment() == this_player() )
		add_action("do_hecheng", "zuhe");
}

int do_hecheng(string arg)
{
	object me, ob, ob2, ob3, *inv;
	string name, old_name, id;
	int i, lvl;

	me = this_player();

	if ( !arg ) return notify_fail("你要组合什么？\n");
	if( !objectp(ob = present(arg, me)) ) return notify_fail("你身上并没有这样东西。\n");
	if ( !(lvl = ob->query("stone_level")) ) return notify_fail("这样东西不能进行组合。\n");
	if ( lvl >= sizeof(stone_level_name) ) return notify_fail("这样东西不能再继续组合了。\n");
	inv = all_inventory(me);
	for ( i = 0; i < sizeof(inv); i++ )
	{
		if ( inv[i] == ob ) continue;
		if ( !inv[i]->query("stone_level") ) continue;
		if ( inv[i]->query("id") != ob->query("id") ) continue;
		if ( inv[i]->query("stone_level") != lvl ) continue;
		if ( !objectp(ob2) )
		{
			ob2 = inv[i];
			continue;
		}
		if ( objectp(ob3) ) break;
		ob3 = inv[i];
	}
	if ( !objectp(ob2) ) return notify_fail("你身上必须有三颗一样的才可以组合。\n");
	if ( !objectp(ob3) ) return notify_fail("你身上必须有三颗一样的才可以组合。\n");
	old_name = ob->query("name");
	name = replace_string(old_name, stone_level_name[lvl-1], stone_level_name[lvl]);
	id = ob->query("id");
	id = replace_string(id, stone_level_id[lvl-1], stone_level_id[lvl]);
	set_name(name, ({ id }));
	ob->set("stone_level", lvl+1);
	destruct(ob2);
	destruct(ob3);
	message_vision("$N"WHT"用三颗"+old_name+WHT"组合成了一颗"+name+"\n"NOR, me);
	return 1;
}