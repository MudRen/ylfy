// huoshi.c
inherit ITEM;

void create()
{
        set_name("��ʯ", ({"fire stone", "stone"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
"���ǿ�����ȡ���ʯͷ��\n");
                set("material", "stone");
        }
}
int query_autoload() { return 1; }