
inherit ITEM;
#include <ansi.h>
void owner_is_killed() { destruct(this_object()); }   

void create()
{
        set_name(HIR"龙筋"NOR, ({"long jin","longjin","jin","dragon"}));
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long",HIR"一根从上古神兽青龙身上取出的筋，似柔实刚，异常的坚韧。它晶莹剔透，触手尚温，隐然泛出红光。\n它似乎是制造兵器的绝好材料。\n\n"NOR);
                set("no_sell", 1);
                //set("no_drop", "这么珍贵的上古神物，你可不能随意丢弃！\n");
                set("rate", 4); //设置材料等级
                set("rigidity",300+random(50)); //设置材料硬度，也即武器硬度
                set("can_make", "all");
                set("not_make", ({ "棍","棒", "刀", "剑","令","锤", "斧","护甲","头盔" }));
                set("material_attrib", "bamboo");
                set("power_point", 300+random(50)); //做成后的jiali大小
              }
}
