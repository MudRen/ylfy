// news_cloth.c   //angelus

#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name(HIG "�¶�����" NOR, ({"new cloth"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��suimeng�ر�Ϊ���˶������·�������������һЩ������\n");
                set("material", "cloth");     //����
                set("armor_prop/armor", 1000);  //����
                set("armor_prop/warm", 2);   //��ů
                set("value", 1000);   //��ֵ
				set("no_sell",1);
       //---------------------------------------------------------------
              //��װ����
                set("suit",HIG"�¶���װ"NOR);  //��װ����
                set("suit_lvl",1);             //��װ�ȼ�
                set("suit_count",3);           //��װ��������
              //��װ������
                set("suit_mod/cloth","�¶�����");
                set("suit_mod/boots","�¶���ѥ");
                set("suit_mod/pants","�¶�����");
             //���Ӱ˴�����
                set("suit_eff/strength",3000);      //����
                set("suit_eff/constitution",3000);      // ��� 
                set("suit_eff/intelligence",3000);      //����  
				set("suit_eff/dexerity",3000); 
                set("suit_eff/armor",10000);      //    һ��
                //set("suit_eff/composure",1);      //����
                //set("suit_eff/personality",1);      // ��� 
                //set("suit_eff/constitution",1);      //����  
                //set("suit_eff/karma",1);      //    һ��
              //��װȫ�����Ӽ���Ч��     
               // set("suit_eff_skill/literate",1000);   
               // set("suit_eff_skill/unarmed",1000);
				//set("suit_eff_skill/parry",1000);
			  // set("suit_eff_skill/dodge",1000);
       //---------------------------------------------------------------
        }
        setup();
}

/*int wear()
{
	int i;
	i = this_object()->query("armor_prop/level");
	if (::wear())
	{
		this_player()->add("max_qi", 30000);
		this_player()->add("max_jing", 10000);
		return 1;
	}
	else
		return 0;
}
int unequip()
{
	int i;
	i = this_object()->query("armor_prop/level");
	if (::unequip())
	{
		this_player()->add("max_qi", -30000);
		this_player()->add("max_jing", -10000);
        if( this_player()->query("eff_qi") > this_player()->query("max_qi") )
		this_player()->set("eff_qi", this_player()->query("max_qi") );
	if( this_player()->query("qi") > this_player()->query("max_qi") )
		this_player()->set("qi", this_player()->query("max_qi") );

	if( this_player()->query("eff_jing") > this_player()->query("max_jing") )
		this_player()->set("eff_jing", this_player()->query("max_jing") );
	if( this_player()->query("jing") > this_player()->query("max_jing") )
		this_player()->set("jing", this_player()->query("max_jing") );
		return 1;
	}
	else
		return 0;
}
*/
int query_autoload()
{
        return 1;
}
