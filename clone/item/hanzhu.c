//yuzhu.c
inherit ITEM;
#include <ansi.h>
void owner_is_killed() { destruct(this_object()); }   

void create()
{
        set_name(HIG"寒丝羽竹"NOR, ({ "hansi yuzhu","yuzhu","hansi"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long",HIG"这是根柔韧无比的寒丝羽竹，通体晶莹，微微泛着绿光，拿在手中轻若无物，似乎是制造兵器的特殊材料。\n"NOR);
                set("can_make", "all");
                set("not_make", ({"战衣", "护甲","锤", "头盔","铁掌","靴子","斧"}));
                set("no_sell", 1);
                //set("no_drop", "这么珍贵的稀有金属，你可不能随意丢弃！\n");
                set("rate", 5); //设置材料等级
                set("power_point", 0); //做成后的jiali大小
                set("material_attrib", "bamboo");
              }
}
