// �����װ���·�

#include <armor.h>
#include <ansi.h>
#define ITEM_LEVEL 1

inherit CLOTH;
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
		set("armor_prop/"+item[i], ITEM_LEVEL * 100);  // ���ó�������
	}
	set_name(HIR"��糤��"NOR, ({ "qinfeng yi","yi", "cloth" }) );
	set("long", "����һ�������ǳ���ϸ�ķ�װ�����ڴ�˵�е������װ�е�һ����\n");
	set_weight(300 + (random(max) * 100) + (random(ITEM_LEVEL) * 100));
	set("value", 5000000 + (random(max + ITEM_LEVEL) * 1000000));
	set("armor_prop/level", ITEM_LEVEL);	
	set("material", "cloth");
	set("owner_id",1);
	set("xyzx_save_item", 1);
	set("xyzx_sys/bind_type", 0);
	set("xyzx_item/pinji", 1);
	set("unit", "��");
	set("icon", "10071");
 //---------------------------------------------------------------
              //��װ����
    set("suit",HIR"�����װ"NOR);  //��װ����
    set("suit_lvl", 1);             //��װ�ȼ�
    set("suit_count",10);           //��װ��������
              //��װ������
    set("suit_mod/armor","�������");
    set("suit_mod/boots","��糤ѥ");
    set("suit_mod/pants","��糤��");
    set("suit_mod/hand","��绤��");
    set("suit_mod/head","���ͷ��");
    set("suit_mod/neck","�������");
    set("suit_mod/cloth","��糤��");
    set("suit_mod/ring","����ָ");
    set("suit_mod/shield","������");
    set("suit_mod/surcoat","�������");
    set("suit_mod/waist","�������");
	set("suit_mod/wrists","��绤��");
	//��װȫ�������츳Ч��  
    set("suit_eff/dexerity", 20000); 
    set("suit_eff/intelligence", 60000);  
    set("suit_eff/constitution", 60000);  
    set("suit_eff/strength", 20000); 
    //��װȫ�����Ӽ���Ч��     
    set("suit_eff_skill/literate", 3000);  
	set("suit_eff_skill/dodge", 5000);
	set("suit_eff_skill/parry", 5000);
	set("suit_eff_skill/force", 5000);
                
 //---------------------------------------------------------------
	setup(1);
}
