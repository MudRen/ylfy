//bye enter

inherit ITEM;
void create()
{
        set_name( "手帕", ({ "shou pa"}));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long","这是一张绣花手帕。\n");
              }
}
int query_autoload() { return 1; }