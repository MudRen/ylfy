// ��̬װ����һЩ������� By Wenwu

#define OUT_SET_SX 50
#include <ansi.h>

inherit F_COLOR;

#include <item_sx.h>

// ��ɫ
nosave string *ansi_arg = ({
	RED, GRN, YEL, BLU, MAG, CYN, WHT, HIR, HIG, HIY, HIB, HIM, HIC, HIW
	});

// ����
nosave mapping name_id_arg = ([
	"ʧ��" : "shishen",
	"����" : "zhiri",
	"߱��" : "shishen",
	"����" : "lianxing",
	"����" : "wushen",
	"����" : "yaoyue",
	"��ħ" : "shimo",
	"��ϼ" : "yuexia",
	"��ħ" : "chumo",
	"���" : "shenfeng",
	"�վ�" : "kongjue",
	"�½�" : "yuejie",
	"����" : "fengxing",
	"���" : "lingfeng",
	"�ɻ�" : "feihua",
	"����" : "zhuyue",
	"Ʈ��" : "piaoxing",
	"����" : "xuanxing",
	"����" : "diewu",
	"�ռ�" : "kongji",
	"Ʈ��" : "piaoyue",
	"���" : "lingfeng",
	"����" : "mengshen",
	"����" : "duanqing",
	"׷��" : "zhuixing",
	"���" : "linghui",
	"��ѩ" : "aoxue",
	"����" : "yinlong",
	"����" : "canyue",
	"����" : "dingfeng",
	"�ƹ�" : "haoguang",
	"����" : "qingyi",
	"����" : "haoguang",
	"����" : "lingxing",
	"����" : "qixing",
	"����" : "duanyue",
	"׷��" : "zhuiyun",
	"����" : "haoqing",
	"����" : "jianxin",
	"����" : "lingyun",
	"����" : "longxing",
	"����" : "suixin",
	"����" : "duanmai",
	"����" : "jueqing",
	"�ƿ�" : "pokong",
	"նħ" : "zhanmo",
	"Ǭ��" : "qiankun",
	"����" : "hongxing",
	"�Ͽ�" : "duankong",
	"��Ӱ" : "lueying",
	"��Ӱ" : "huanying",
	"����" : "lanxing",
	"����" : "gunlong",
	"����" : "changkong",
	"Ʈѩ" : "piaoxue",
	"����" : "fuyu",
	"����" : "fanyun",
	"��ħ" : "xiangmo",
	"��ħ" : "fumo",
	"�ﺮ" : "qiuhan",
	"���" : "dianguang",
	"����" : "leiming",
	"����" : "fenglei",
	"����" : "biri",
	"��ħ" : "huanmo",
	"��ڤ" : "xuming",
	"����" : "youming",
	"����" : "mingshen",
	"����" : "yanyu",
	"����" : "yanxin",
	"����" : "qinglong",
	"��Ӱ" : "fengying",
	"����" : "yanyue",
	"����" : "yanxing",
	"����" : "longshe",
	"����" : "lingshe",
	"���" : "miaokong",
	"����" : "yaoxing",
	"����" : "wangkong",
	"����" : "chenxin",
	"����" : "huanyue",
	"����" : "juechen",
	"����" : "changhen",
	"�۷�" : "chifeng",
	"����" : "tianxing",
	"���" : "tiangang",
	"��ɷ" : "disha",
	"����" : "jiaolong",
	"����" : "longshen",
	"����" : "changkong",
	"����" : "bingxin",
	"�ɹ�" : "shigu",
	"����" : "fengren",
	"����" : "hanguang",
	"����" : "dingxin",
	"����" : "huanwu",
	"����" : "yiri",
	"����" : "xuanwu",
	"�Ŷ�" : "guding",
	"����" : "tianxuan",
	"̫��" : "taiji",
	"��Ԫ" : "hunyuan",
	"���" : "tianfeng",
	"�޼�" : "wuji",
]);

// ȡ��һ�����������
string get_item_name(int pj, int lvl)
{
	string name, *name_arry;
	int get_ansi, get_name1, get_name2;

	name_arry = keys(name_id_arg);
	get_ansi = random(sizeof(ansi_arg));
	get_name1 = random(sizeof(name_arry));

	get_name2 = random(sizeof(name_arry));
	while ( get_name2 == get_name1 )
	{
		get_name2 = random(sizeof(name_arry));
	}

	if ( pj < 15 && lvl < 9 )
		name = ansi_arg[get_ansi] + name_arry[get_name1];
	else
		name = ansi_arg[get_ansi] + name_arry[get_name1] + ansi_arg[get_ansi] + name_arry[get_name2];

	return name;
}

// ȡ�ö�̬��ƷID
string get_item_id(string name, string item_type)
{
	string id, no_ansi_name, get_id;
	int len;

	no_ansi_name = clean_color(name);
	len = strlen(no_ansi_name);
	
	if ( len > 4 )
		get_id = name_id_arg[no_ansi_name[0..3]]+ " " + name_id_arg[no_ansi_name[4..(len-1)]] + " " + item_type;
	else
		get_id = name_id_arg[no_ansi_name[0..3]] + " " + item_type;

	id = replace_string(get_id, "0", "");
	id = replace_string(id, "0 ", "");

	return id;
}

// ����
varargs void get_item_shuxing(string item_type, int pj, int lvl, int flag)
{
	object ob;
	string *weapon, *armor;
	int m, n, out;

	ob = this_object();
	weapon = keys(weapon_shuxing);
	armor = keys(armor_shuxing);
	m = 0;
	n = 0;
	out = 0;

	switch (item_type)
	{
		case "weapon":
			if ( pj > sizeof(weapon) )
				return;
			ob->set("weapon_prop/damage", lvl * 100);
			weapon -= ({ "damage" });
			pj--;
			while ( pj && pj > 0 )
			{
				if ( out > OUT_SET_SX )
					break;
				m = sizeof(weapon);
				if ( !m || m < 1 )
					break;
				n = random(m);
				ob->set("weapon_prop/" + weapon[n], random(100 * lvl));
				weapon -= ({ weapon[n] });
				pj--;
				out++;
			}
			break;

		case "armor":
			if ( pj > sizeof(armor) )
				return;
			ob->set("armor_prop/armor", lvl * 100);
			weapon -= ({ "armor" });
			pj--;
			while ( pj && pj > 0 )
			{
				if ( out > OUT_SET_SX )
					break;
				m = sizeof(armor);
				if ( !m || m < 1 )
					break;
				n = random(m);
				ob->set("armor_prop/" + armor[n], random(100 * lvl));
				weapon -= ({ armor[n] });
				pj--;
				out++;
			}
			break;

		default:log_file( "/SET_item", sprintf("%sװ���������ô���\n", base_name(ob)));
	}

	// Ч����ǿ
	/*tx = random(2);//����������ִ��Ǻ�װ���ĸ��ʣ�����������ж��Ĺ֡�
	name = ob->query("name");
	
	if ( tx < 3 && 4 <= flag )
	{
		ob->set("xyzx_item/pinji", 4);
		ob->set("name", YEL"��" + name);
	}
	else if ( tx < 10 && 3 <= flag )
	{
		ob->set("xyzx_item/pinji", 3);
		ob->set("name", MAG"����" + name);
	}
	else if ( tx < 50 && 2 <= flag )
	{
		ob->set("xyzx_item/pinji", 2);
		ob->set("name", BLU"���" + name);
	}
	else if ( tx < 100 && 1 <= flag )
	{
		ob->set("xyzx_item/pinji", 1);
		ob->set("name", GRN"��" + name);
	}*/
}