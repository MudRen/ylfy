// gold.c

#include <ansi.h>

inherit MONEY;

void create()
{
        set_name(YEL "�ƽ�" NOR , ({"gold", "ingot", "gold_money"}));
        set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "gold");
                set("icon","00010");
		set("long", "�ƳγεĽ��ӣ��˼��˰��Ľ��ӣ����������ӣ�\n");
		 set("unit", "Щ");
		set("base_value", 10000 );
		set("base_unit", "��");
		set("base_weight", 1);//ԭ��80
	}
	set_amount(1);
}

