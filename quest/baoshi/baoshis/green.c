//make bye stey
#include <ansi.h>
inherit "/inherit/item/baoshi";

void create(int i)
{
	set_name(HIG"�̱�ʯ"NOR,({"green baoshi","baoshi"}));
	set_weight(500);
	set("b_lvl",3);
	set("reward_lvl",3);
	set("baoshi","��");
	
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("value", 2000000);
		set("unit","��");
		set("color", HIB);  //HIB
		set("buy_sell",1);
		//set("owner_id",1);
		set("zhubao_save",1);
		set("no_sell",1);
		set("long",HIB"һ�鷢����������ı�ʯ����˵��Ů洲���ʯ�����,Ҳ��֪��ʲôʱ�����뷲��ġ�\n"NOR);
	}
	setup();
}

