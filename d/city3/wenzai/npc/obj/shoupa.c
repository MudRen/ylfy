//bye enter

inherit ITEM;
void create()
{
        set_name( "����", ({ "shou pa"}));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ���廨������\n");
              }
}
int query_autoload() { return 1; }