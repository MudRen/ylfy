// ˷ѩ��װ������

#include <armor.h>
#include <ansi.h>
#define ITEM_LEVEL 1

inherit NECK;
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
	set_name(HIB"˷ѩ����"NOR, ({ "shuoxue xianglian","xianglian", "neck" }) );
	set("long", "����һ�����������ı�ʯ���������ڴ�˵�е�˷ѩ��װ�е�һ����\n");
	set_weight(300 + (random(max) * 100) + (random(ITEM_LEVEL) * 100));
	set("value", 5000000 + (random(max + ITEM_LEVEL) * 1000000));
	set("armor_prop/level", ITEM_LEVEL);	
	set("material", "gem");
	set("xyzx_item/pinji", 1);
	set("owner_id",1);
	set("max_level", 30);
	set("xyzx_save_item", 1);
	set("xyzx_sys/bind_type", 0);
	set("unit", "��");
	set("icon", "10077");
 //---------------------------------------------------------------
              //��װ����
    set("suit",HIB"˷ѩ��װ"NOR);  //��װ����
    set("suit_lvl", 1);             //��װ�ȼ�
    set("suit_count",10);           //��װ��������
              //��װ������
    set("suit_mod/armor","˷ѩ����");
    set("suit_mod/boots","˷ѩ��ѥ");
    set("suit_mod/pants","˷ѩ����");
    set("suit_mod/hand","˷ѩ����");
    set("suit_mod/head","˷ѩͷ��");
    set("suit_mod/neck","˷ѩ����");
    set("suit_mod/cloth","˷ѩ����");
    set("suit_mod/ring","˷ѩ��ָ");
    set("suit_mod/shield","˷ѩ����");
    set("suit_mod/surcoat","˷ѩ����");
    set("suit_mod/waist","˷ѩ����");
	set("suit_mod/wrists","˷ѩ����");
	//��װȫ�������츳Ч��  
    set("suit_eff/dexerity", 20000);      
    set("suit_eff/intelligence", 20000);  
    set("suit_eff/constitution", 60000);    
    set("suit_eff/strength", 20000);   
    //��װȫ�����Ӽ���Ч��     
    set("suit_eff_skill/huagong-dafa", 1000);
    set("suit_eff_skill/beiming-shengong", 1000);
	set("suit_eff_skill/xixing-dafa", 1000);
	
 //---------------------------------------------------------------
	setup(1);
}
