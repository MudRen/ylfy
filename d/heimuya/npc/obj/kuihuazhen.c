	// kuihuazhen.c
#include <weapon.h>
inherit THROWING;
void create()
{
        set_name("葵花针", ({ "kuihuazhen" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",     "葵花针是一种专门打制的暗器，外形极薄，杀伤力强.\n");
                set("unit", "把");
                set("base_unit", "把");
                set("base_weight", 1);
                set("base_value", 1);
        }
        set_amount(200);
        init_throwing(20,2);
        setup();
}
int query_autoload() { return 1; }