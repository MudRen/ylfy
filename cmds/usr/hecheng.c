// 宝石合成 By Wenwu On 2006.9.23

// 需要文件的存放目录
#define BAOSHIS_DIR "/quest/baoshi/baoshis/"
// 成功率（值越高成功率越高）
#define CHENG_GONG_INT 15

#include <ansi.h>

inherit F_CLEAN_UP;

string *file_name = ({
	"hong",
	"blue",
	"green",
	"qing",
	"huang",
	"zi",
	"cheng",
	"manao",
	"feicui",
	"chengyu",
	"shuijing",
	"jinsha",
	"maoyan",
	"zuanshi",
	"god manao",
	"god feicui",
	"god chengyu",
	"god shuijing",
	"god jinsha",
	"god maoyan",
	"god zuanshi",
	"sun",
	"sky",
	"forest",
	"sea",
	"fire",
	"sunshine",
	"sand",
	"justice light",
	"mercy light",
	"earth light",
	"sea light",
	"fire light",
	"gods light",
	"love light",
});

int main(object me, string arg)
{
	object ob, ob2, ob3, *inv, baoshi;
	string baoshi_name, new_baoshi_name;
	int i, v, bind_flag;

	if ( !arg )
		return notify_fail("你想拿什么东西进行合成？\n");
	if( !objectp(ob = present(arg, me)) )
		return notify_fail("你身上并没有这样东西。\n");
	if ( !ob->query("zhubao_save") )
		return notify_fail("这样东西不能进行合成。\n");
	if ( ob->query("b_lvl") > 28 )
		return notify_fail("这样东西不能再继续合成了。\n");

	inv = all_inventory(me);
	for ( i = 0; i < sizeof(inv); i++ )
	{
		if ( inv[i] == ob )
			continue;
		if ( !inv[i]->query("zhubao_save") )
			continue;
		if ( inv[i]->query("id") != ob->query("id") )
			continue;
		if ( inv[i]->query("b_lvl") != ob->query("b_lvl") )
			continue;

		if ( !objectp(ob2) )
		{
			ob2 = inv[i];
			continue;
		}

		if ( objectp(ob3) )
			break;

		ob3 = inv[i];
	}

	if ( !objectp(ob2) )
		return notify_fail("你身上必须有三件一样的东西才可以合成。\n");
	if ( !objectp(ob3) )
		return notify_fail("你身上必须有三件一样的东西才可以合成。\n");

	v = ob->query("b_lvl") - 1;
	baoshi_name = ob->query("name")+"("+ob->query("id")+")";

	// 绑定的宝石镶嵌装备，那么装备也会被绑定
	bind_flag = 0;
	if ( mapp(ob->query("bind_master_level")) 
		|| mapp(ob2->query("bind_master_level")) 
		|| mapp(ob3->query("bind_master_level")) ) {
		bind_flag = 1;
	}

	destruct(ob);
	destruct(ob2);
	destruct(ob3);

	if ( v < 0 || v > sizeof(file_name) - 1 )
	{
		write("合成失败，你损失了三颗" + baoshi_name + "。\n");
		return 1;
	}

	if ( random(sizeof(file_name)+CHENG_GONG_INT) < v )
	{
		write("合成失败，你损失了三颗" + baoshi_name + "。\n");
		return 1;
	}

	baoshi = new(BAOSHIS_DIR+file_name[v+7]);
	new_baoshi_name = baoshi->query("name")+"("+baoshi->query("id")+")";
	if ( bind_flag == 1 )
		baoshi->set("bind_master_level/"+me->query("id"), 1);
	baoshi->move(me);
	message_vision("$N"WHT"用三颗"+baoshi_name+WHT"成功合成了一颗"+new_baoshi_name+"\n"NOR, me);
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : hecheng 宝石英文名
用途 : 可以把三个同种宝石合成更高级的宝石。
HELP);
return 1;
}

