#include <room.h>
#include <ansi.h>

inherit ROOM;

/*nosave mapping name_list = ([
	"��"   : "long",
	"��"   : "cai",
	"��"   : "ju",
	"��"   : "lian",
	"ʢ"   : "sheng",
	"��"   : "yi",
	"��"   : "man",
	"ɳ"   : "sha",
	"��"   : "dong",
	"��"   : "leng",
	"��"   : "jie",
	"ȴ"   : "que",
	"��"   : "ai",
	"��"   : "qiao",
	"��"   : "guang",
	"��"   : "xiang",
	"��"   : "chou",
	"��"   : "che",
	"��"   : "lai",
	"ɽ"   : "shan",
	"��"   : "zhou",
	"��"   : "yan",
	"��"   : "yuan",
	"Ҷ"   : "ye",
	"��"   : "ji",
	"��"   : "shu",
	"׿"   : "zhuo",
	"��"   : "hong",
	"��"   : "neng",
	"��"   : "mi",
	"��"   : "li",
	"��"   : "chen",
	"Ф"   : "xiao",
	"��"   : "peng",
	"��"   : "shang",
	"��"   : "guan",
	"��"   : "bu",
	"��"   : "nie",
	"��"   : "ling",
	"��"   : "hu",
	"ŷ"   : "ou",
	"��"   : "yang",
	"Ľ"   : "mu",
	"��"   : "zhu",
	"ţ"   : "niu",
	"��"   : "gou",
	"˾"   : "si",
	"��"   : "ma",
	"ȫ"   : "quan",
	"��"   : "ju",
	"��"   : "cao",
	"��"   : "gong",
	"��"   : "gong",
	"��"   : "hu",
	"��"   : "men",
	"��"   : "sun",
	"��"   : "liu",
	"��"   : "zhang",
	"��"   : "zhao",
	"κ"   : "wei",
	"��"   : "wang",
	"��"   : "huang",
	"��"   : "wu",
	"֣"   : "zheng",
	"��"   : "guo",
	"��"   : "li",
	"��"   : "tang",
	"Ī"   : "mo",
	"��"   : "tian",
	"��"   : "yue",
	"��"   : "qin",
	"��"   : "ning",
	"��"   : "song",
	"��"   : "yu",
	"��"   : "yu",
	"��"   : "luo",
	"Ϳ"   : "tu",
	"��"   : "feng",
	"��"   : "feng",
	"��"   : "wen",
	"��"   : "wan",
	"Ǯ"   : "qian",
	"��"   : "hou",
	"��"   : "ge",
	"ұ"   : "zhi",
	"��"   : "kong",
	"��"   : "yu",
	"��"   : "shu",
	"��"   : "yang",
	"��"   : "wen",
	"��"   : "zheng",
	"��"   : "guan",
	"��" : "feng",
	"��" : "feng",
	"��" : "feng",
	"��" : "feng",
	"��" : "feng",
	"��" : "feng",
	"��" : "feng",
	"��" : "li",
	"��" : "wa",
	"��" : "wo",
	"��" : "wan",
	"��" : "mian",
	"ǩ" : "qian",
	"Ǩ" : "qian",
	"��" : "guang",
	"��" : "ting",
	"ǥ" : "qian",
	"��" : "qian",
	"ɢ" : "san",
	"��" : "shan",
	"��" : "shang",
	"ɣ" : "sang",
	"��" : "kuan",
	"��" : "kuang",
	"��" : "mai",
	"��" : "man",
	"å" : "mang",
	"��" : "jian",
	"��" : "jiang",
	"ճ" : "zhan",
	"��" : "zhang",
	"��" : "zan",
	"��" : "zhang",
	"��" : "mi",
	"�" : "mie",
	"��" : "mian",
	"��" : "fa",
	"��" : "fan",
	"��" : "fang",
	"��" : "ca",
	"��" : "cha",
	"��" : "can",
	"��" : "cang",
	"��" : "chan",
	"��" : "chang",
	"��" : "yu",
	"��" : "yun",
	"ԭ" : "yuan",
	"��" : "nu",
	"��" : "niu",
	"ī" : "mo",
	"ٰ" : "mou",
	"Ĺ" : "mu",
	"��" : "la",
	"��" : "lan",
	"��" : "lang",
	"��" : "na",
	"��" : "nan",
	"��" : "nang",
	"��" : "mian",
	"��" : "ji",
	"��" : "jin",
	"��" : "jing",
	"��" : "qu",
	"��" : "qun",
	"��" : "fu",
	"��" : "ga",
	"��" : "gan",
	"��" : "gang",
	"��" : "da",
	"��" : "dan",
	"��" : "dang",
	"��" : "ku",
	"��" : "wu",
	"Ϸ" : "xi",
	"Ͽ" : "xia",
	"ͻ" : "tu",
	"��" : "tun",
	"��" : "ruan",
	"��" : "hong",
	"��" : "fei",
	"��" : "gui",
	"��" : "wu",
	"��" : "hua",
	"��" : "gai",
	"��" : "fu",
	"��" : "he",
	"˹" : "si",
	"��" : "yu",
	"��" : "su",
	"��" : "chang",
	"��" : "shu",
	"��" : "er",
	"��" : "po",
	"��" : "fan",
	"ؿ" : "mie",
	"��" : "xing",
	"��" : "meng",
	"��" : "hua",
	"��" : "cheng",
	"��" : "hui",
	"��" : "wang",
	"��" : "hai",
	"��" : "qi",
	"ǿ" : "qiang",
	"��" : "zhong",
	]);

int do_answer(string arg)
{
	object me;
	string name, id, *msg, msg1, msg2;
	int max, type;

	me = this_player();
	name = me->query_temp("miwu_in_name");
	id = me->query_temp("miwu_in_id");

	if ( !objectp(me) || !playerp(me) ) return 0;

	msg = keys(name_list);
	max = sizeof(msg);
	msg1 = msg[random(max)];
	msg2 = msg[random(max)];
	type = 12+random(3)*2;

	if ( !arg ) 
	{
		name = TEXT2PIC_D->Display(name, type, msg1, msg2, HBYEL, BBLU);
		return notify_fail("��ش�("HIG"answer"NOR")�������־�\n"HIY+name+NOR"\n��Ӧ��ƴ���ǣ�����\n");
	}
	if ( arg != id ) 
	{
		name = TEXT2PIC_D->Display(name, type, msg1, msg2, HBYEL, BBLU);
		return notify_fail("�𰸴��������»ش�("HIG"answer"NOR")�����־�\n"HIY+name+NOR"\n�Ķ�Ӧƴ����\n");
	}

	me->set_temp("grant_in_miwu", 1);
	tell_object(me, HIG"��ϲ�㣡�ش���ȷ����ɹ���ȡ����ε�����ɭ�ֽ���Ȩ��\n"NOR);
	return 1;
}*/

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
   ����һ����᫵�ɽ·�����ܶ���ï�ܵĹ�ľ�ԣ�ʱ��ʱ����
һ��Ұ�޵ĺ������
LONG);
	set("exits", ([
	    "north" :"/d/migong/guanmucong",
		"east" : "/d/automap/0.c",
		"south" : "/d/migong/migong2.c",
		"west" :"d/sdxl/conglin3",
		]));
	set("no_clean_up", 0);
	setup();
}

/*void init()
{
	object me;
	string name, id, temp, *name_all;
	int i, max, name_size;

	me = this_player();
	name_all = keys(name_list);
	name_size = sizeof(name_all);
	name = "";
	id = "";
	max = 2;

	if ( !objectp(me) || !playerp(me) ) return;
	for ( i=0; i<max; i++ )
	{
		temp = name_all[random(name_size)];
		name += temp;
		id += name_list[temp];
	}

	me->set_temp("miwu_in_name", name);
	me->set_temp("miwu_in_id", id);

	add_action("do_answer", "answer");
}

int valid_leave(object me, string dir)
{
	string name, id, *msg, msg1, msg2;
	int max, type;

	name = me->query_temp("miwu_in_name");
	id = me->query_temp("miwu_in_id");

	if ( objectp(me) 
		&& playerp(me) 
		&& !me->query_temp("grant_in_miwu")
		&& dir == "east" )
	{
		msg = keys(name_list);
		max = sizeof(msg);
		msg1 = msg[random(max)];
		msg2 = msg[random(max)];
		type = 12+random(3)*2;
		name = TEXT2PIC_D->Display(name, type, msg1, msg2, HBYEL, BBLU);
		return notify_fail("\n��ش�("HIG"answer"NOR")�������־�\n"HIY+name+NOR"\n�Ķ�Ӧƴ�����Ի�ȡ��������ɭ�ֵ����Ȩ��\n" + 
		"���磺\n"HIY"    һ��������\n"NOR"    ��ô�����룺"HIG"answer yiersansiwu\n"NOR"    ���ɻ������ɭ�ֽ���Ȩ��\n" + 
		HIC"��������־������㲻��ʶ�����֣���ô���������"HIG" fly mw "HIC"ˢ�������־䡣\n\n"NOR);
	}

	me->delete_temp("grant_in_miwu");

	return ::valid_leave(me, dir);
}*/