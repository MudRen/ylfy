// damo-ling.c ��Ħ��
inherit ITEM;
void create()
{
        set_name("��Ħ��", ({"damo ling", "letter", "ling"}));
        set_weight(500);
    if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ�������������ƣ��ɷ���ǩ����ƾ�˿ɵ���������ʦ����ս��\n");
                set("material", "steel");
            set("no_sell",1);
        }
}
int query_autoload() { return 1; }