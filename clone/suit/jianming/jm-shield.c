// ������װ������

#include <armor.h>
#include <ansi.h>
#define ITEM_LEVEL 1

inherit SHIELD;
inherit F_ITEM_MAKE;
//#include <item_sx.h>

void create()
{
	string *item;
	int i, max;

	item = keys(armor_shuxing);
	max = sizeof(item);
	for ( i=0; i < max; i++ )
	{
		set("armor_prop/"+item[i], ITEM_LEVEL * 100);   // ���ó�������
	}
	set_name(YEL"��������"NOR, ({ "jianming dun","dun", "shield" }) );
	set("long", "����һ������Լ��õĸ������ܣ����ż�̵ķ������������ڴ�˵�еĽ�����װ�е�һ����\n");
	set_weight(300 + (random(max) * 100) + (random(ITEM_LEVEL) * 100));
	set("value", 5000000 + (random(max + ITEM_LEVEL) * 1000000));
	set("armor_prop/level", ITEM_LEVEL);	
	set("material", "steel");
	set("xyzx_item/pinji", 2);
	set("owner_id",1);
	set("max_level", 30);
	set("xyzx_save_item", 1);
	set("xyzx_sys/bind_type", 0);
	set("unit", "��");
	set("icon", "10079");
 //---------------------------------------------------------------
              //��װ����
    set("suit",YEL"������װ"NOR);  //��װ����
    set("suit_lvl", 3);             //��װ�ȼ�
    set("suit_count",10);           //��װ��������
              //��װ������
    set("suit_mod/armor","��������");
    set("suit_mod/boots","������ѥ");
    set("suit_mod/pants","��������");
    set("suit_mod/hand","��������");
    set("suit_mod/head","����ͷ��");
    set("suit_mod/neck","��������");
    set("suit_mod/cloth","��������");
    set("suit_mod/ring","������ָ");
    set("suit_mod/shield","��������");
    set("suit_mod/surcoat","��������");
    set("suit_mod/waist","��������");
	set("suit_mod/wrists","��������");
		//��װȫ�������츳Ч��  
    set("suit_eff/dexerity", 50000);      
    set("suit_eff/intelligence", 50000);      
    set("suit_eff/constitution", 50000);      
    set("suit_eff/strength", 50000);      
    //��װȫ�����Ӽ���Ч��     
    set("suit_eff_skill/taiji-shengong", 1000);   
                
 //---------------------------------------------------------------
	setup(1);
}

