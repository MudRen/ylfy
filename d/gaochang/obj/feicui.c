inherit ITEM;
void create()
{
    set_name(HIG "���" NOR, ({ "feicui" }) );
    set("unit", "��");
    set("value",1000000);
    set("long","����һ�麱������䣬����ֵ����Ǯ��\n");
    set_weight(100);
}
int query_autoload() { return 1; }