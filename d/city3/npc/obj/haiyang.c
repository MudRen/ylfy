// bye enter

#include <ansi.h>

#include <armor.h>

inherit NECK;

void create()
{
        set_name(HIC "����֮��" NOR, ({ "haiyang necklace", "necklace" }));
        set("weight", 400);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����л������֮������Ż����Ѫ֮������˵���Ը�������˴������ˡ�\n");
                set("unit", "��");
                set("value", 500000);
                set("wear_msg",HIC "$N���������еĺ���֮�ģ�����֣�صؽ������ڲ����ϣ�����Ȼ����һ����͵�ε��ɫ��\n "NOR );
                set("remove_msg",  "$N������֮�ĴӲ�����ȡ��������\n");
                set("material", "gold");
set("armor_prop/karma", 3);
                set("armor_prop/armor", 500);
        }
        setup();
}   
int query_autoload() { return 1; }
