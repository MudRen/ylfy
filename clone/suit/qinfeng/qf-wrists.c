// �ط���װ������

#include <armor.h>
#include <ansi.h>
#define ITEM_LEVEL 1

inherit WRISTS;
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
	set_name(HIR"�ط绤��"NOR, ({ "qinfeng huwan","huwan", "wrists" }) );
	set("long", "����һ�������쳣ϸ�£��������÷����ԵĻ������ڴ�˵�е��ط���װ�е�һ����\n");
	set_weight(300 + (random(max) * 100) + (random(ITEM_LEVEL) * 100));
	set("value", 5000000 + (random(max + ITEM_LEVEL) * 1000000));
	set("armor_prop/level", ITEM_LEVEL);	
	set("material", "gem");
	set("owner_id",1);
	set("xyzx_save_item", 1);
	set("xyzx_sys/bind_type", 0);
	set("xyzx_item/pinji", 1);
	set("unit", "��");
	set("icon", "10082");
 //---------------------------------------------------------------
              //��װ����
    set("suit",HIR"�ط���װ"NOR);  //��װ����
    set("suit_lvl", 1);             //��װ�ȼ�
    set("suit_count",10);           //��װ��������
              //��װ������
    set("suit_mod/armor","�ط�����");
    set("suit_mod/boots","�ط糤ѥ");
    set("suit_mod/pants","�ط糤��");
    set("suit_mod/hand","�ط绤��");
    set("suit_mod/head","�ط�ͷ��");
    set("suit_mod/neck","�ط�����");
    set("suit_mod/cloth","�ط糤��");
    set("suit_mod/ring","�ط��ָ");
    set("suit_mod/shield","�ط����");
    set("suit_mod/surcoat","�ط�����");
    set("suit_mod/waist","�ط�����");
	set("suit_mod/wrists","�ط绤��");
	//��װȫ�������츳Ч��  
    set("suit_eff/dexerity", 60000); 
    set("suit_eff/intelligence", 60000);  
    set("suit_eff/constitution", 60000);  
    set("suit_eff/strength", 60000); 
	set("suit_eff/armor", 60000);
    set("suit_eff/damage", 10000); 
    //��װȫ�����Ӽ���Ч��     
    /*set("suit_eff_skill/huagong-dafa", 100);  
	set("suit_eff_skill/beiming-shengong", 100);
	set("suit_eff_skill/xixing-dafa", 100);*/              
 //---------------------------------------------------------------
	setup(1);
}
