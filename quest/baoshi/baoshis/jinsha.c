//make bye stey
#include <ansi.h>
inherit "/inherit/item/baoshi";

void create(int i)
{
	set_name(HIY"金沙宝石"NOR,({"jinsha baoshi","baoshi"}));
	set_weight(500);
	set("b_lvl",12);
	set("reward_lvl",5);
	set("baoshi","金沙");
	set("is_monitored",1);
	
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("value", 2000000);
		set("unit","颗");
		set("color", HIB);  //HIB
		set("buy_sell",1);
		//set("owner_id",1);
		set("no_sell",1);
		set("zhubao_save",1);
		set("long",HIB"一块发着闪闪发光的宝石，传说是女娲补天石的碎块,也不知道什么时候落入凡间的。\n"NOR);
	}
	setup();
}
