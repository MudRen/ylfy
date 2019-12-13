// �ϳɲ��ϣ���ϡ֮ʯ

inherit ITEM;
inherit F_SAVE;

nosave mapping stone_name = ([
	"�ջ�" : "rihui",
	"�»�" : "yuehua",
	"����" : "bingpo",
	"����" : "leiming",
	"����" : "ziyun",
	"��Х" : "fengxiao",
	"��ڤ" : "heiming",
	"����" : "jushen",
	"����" : "qingxin",
	"�ӽ�" : "canjin",
	"��ӡ" : "qingxin",
	"����" : "butian",
	"����" : "qingxin",
	"����" : "huntu",
	"��ˮ" : "yunshui",
	"����" : "fuhuo",
	"˸��" : "shuoguang",
	"Ļ��" : "mutian",
	"���" : "zhendi",
	]);

nosave mapping stone_color = ([
	"�ջ�" : HIR,
	"�»�" : CYN,
	"����" : HIW,
	"����" : HIB,
	"����" : HIM,
	"��Х" : HIW,
	"��ڤ" : WHT,
	"����" : MAG,
	"����" : HIW,
	"�ӽ�" : HIY,
	"��ӡ" : YEL,
	"����" : HIC,
	"����" : GRN,
	"����" : YEL,
	"��ˮ" : GRN,
	"����" : HIY,
	"˸��" : HIW,
	"Ļ��" : HIC,
	"���" : YEL,
	]);

nosave string *stone_level_name = ({
	"��ϸ���",
	"�ڴֲڵ�",
	"�۱�׼��",
	"�ܾ��µ�",
	"��������",
	"�޳����",
	"����ʥ��",
	"���񻯵�",
	"�����̵�",
	"�����޵�",
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

	set_name(color+stone_level_name[lvl]+name+"֮ʯ"NOR, ({stone_level_id[lvl]+" "+stone_name[name]+" stone"}));
	set("long", "һ��������������ʯͷ���ƺ���ĳ����Ʒ�ĺϳɲ��ϡ���������ϸ΢�İ��ۿ����������Խ������(zuhe).\n");
	set_weight(15);
	set("stone_level", lvl+1);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
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

	if ( !arg ) return notify_fail("��Ҫ���ʲô��\n");
	if( !objectp(ob = present(arg, me)) ) return notify_fail("�����ϲ�û������������\n");
	if ( !(lvl = ob->query("stone_level")) ) return notify_fail("�����������ܽ�����ϡ�\n");
	if ( lvl >= sizeof(stone_level_name) ) return notify_fail("�������������ټ�������ˡ�\n");
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
	if ( !objectp(ob2) ) return notify_fail("�����ϱ���������һ���Ĳſ�����ϡ�\n");
	if ( !objectp(ob3) ) return notify_fail("�����ϱ���������һ���Ĳſ�����ϡ�\n");
	old_name = ob->query("name");
	name = replace_string(old_name, stone_level_name[lvl-1], stone_level_name[lvl]);
	id = ob->query("id");
	id = replace_string(id, stone_level_id[lvl-1], stone_level_id[lvl]);
	set_name(name, ({ id }));
	ob->set("stone_level", lvl+1);
	destruct(ob2);
	destruct(ob3);
	message_vision("$N"WHT"������"+old_name+WHT"��ϳ���һ��"+name+"\n"NOR, me);
	return 1;
}