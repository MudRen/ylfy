#include <armor.h>
inherit NECK;

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
*/

void create()
{
        set_name("Χ��", ({ "my scarf","scarf" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","һ���ò�˿֯�ɵ�Χ���ֹ���ϸ�������������ϲ÷�߳������ա�\n");
                set("unit", "��");
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

