// diamond.c

inherit MONEY;

void create()
{
set_name("��ʯ", ({"diamond", "zuanshi", "diamond_money"}));	
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("money_id", "diamond");        	
                set("long", "����������ʯ���˼��˰�����ʯ����������ʯ��\n");
                set("no_drop",1);
                set("no_give",1);
                set("no_put",1);	
                set("unit", "Щ");
                set("base_value", 10000 );     	
                set("base_unit", "����");
                set("base_weight", 5);
        }
        set_amount(1);
}


