#include <armor.h>
inherit BOOTS;

/*  ������
HEAD    ͷ����ͷ��
NECK    ��Ȧ��Χ��
ARMOR   ����
SURCOAT ����
WAIST   ����
WRISTS  ����
SHIELD  ��
FINGER  ָ��
HANDS   ����
BOOTS   Ь��
PANTS   ����
*/

void create()
{
        set_name("Ь��", ({ "my boots","boots" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","һ˫�ò�˿���ɵ�Ь�ӣ��ֹ���ϸ�������������ϲ÷�߳������ա�\n");
                set("unit", "˫");
                set("material", "cloth");
                set("armor_prop/armor", 30);
                set("make",1);
                set("no_get",1);
//                set("no_drop",1);
                set("no_put",1);
        }
        setup();
        
}
int query_autoload()
{
        return query("name");
}
void autoload(string param)
{
        if (!param || !stringp(param))
        return;
        set("name",param);
}
void owner_is_killed() { destruct(this_object()); }

