//xuanjing.c
inherit ITEM;
void create()
{
        set_name(HIY "��������"NOR, ({"zuiyue xuanjing"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ��ǳ������Ĳ��ϣ��̺��ų������������ƺ���������������ıر����ϡ�\n");
                set("value", 10000000);
                set("material", "bamboo");
              }
}
int query_autoload() { return 1; }