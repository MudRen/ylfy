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
	set("unit","��");
	set("color", HIB);  //HIB
	set("buy_sell",1);
	set("owner_id",1);
	set("xyzx_save_item", 1);
	set("no_sell",1);
	set("zhubao_save",1);
	set("long",HIB"һ�鷢����������ı�ʯ����˵��Ů洲���ʯ�����,Ҳ��֪��ʲôʱ�����뷲��ġ�\n"NOR);
    }
    setup();
}


