// paper.c
inherit ITEM;
void create()
{
    set_name("��ֽ", ({ "paper"}) );
    set_weight(50);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long", "һ�Ų�ֽ��\n");
    }
}
int query_autoload() { return 1; }