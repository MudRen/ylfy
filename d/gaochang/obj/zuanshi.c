inherit ITEM;
void create()
{
    set_name(HIW "��ʯ" NOR, ({ "zuanshi" }) );
    set("unit", "��");
    set("value",1000000);
    set("long","����һ�ź�������ʯ����ĸָ��ô�󣬿���ֵ����Ǯ��\n");
    set_weight(100);
}
int query_autoload() { return 1; }