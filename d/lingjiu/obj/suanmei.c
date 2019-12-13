// suanmei.c 酸梅汤
inherit ITEM;
inherit F_LIQUID;
void create()
{
        set_name("雕花小碗", ({ "hua wang","wang" }));
        set_weight(1000);
        if( clonep() )
          set_default_object(__FILE__);
        else {
        set("long",
            "这是一个花雕小碗。\n");
        set("unit", "个");
        set("value", 20);
        set("max_liquid", 10);
        }
        set("liquid", ([
            "name" : "酸梅汤",
            "remaining" : 8,
            "type" : "water"
        ]) );
        set("liquid_type", "water");
        setup();
}
int query_autoload() { return 1; }