//make bye stey
#include <ansi.h>

inherit "/inherit/item/baoshi";
inherit F_SAVE;

void create(int i)
{
    setname();
    set_weight(500);
    if( clonep() )
	set_default_object(__FILE__);
    else {
	set("value", 2000000);
	//               set("is_monitored", 1);
	set("unit","颗");
	set("color", HIB);  //HIB
	set("buy_sell",1);
	set("owner_id",1);
	set("xyzx_save_item", 1);
	set("no_sell",1);
	set("zhubao_save",1);
	set("long",HIB"一块发着闪闪发光的宝石，传说是女娲补天石的碎块,也不知道什么时候落入凡间的。\n"NOR);
    }
    setup();
}


