// gangdao.c
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name("锈刀", ({ "xiu blade","blade" }));
        set_weight(7000);
                set("flag",2);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "一柄生锈了的短刀，隐隐透出一股冰冷的杀气。\n");
                set("value", 5);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回刀鞘。\n");
        }
       init_blade(600,2);
        setup();
}

int move(mixed dest)
{
        if(! userp(dest))       return ::move(dest);
        if( ::move(dest)==0)    return 0;
         message("rumor",HIG"【江湖传奇】"+ "据说玄天魔刀被"+
        dest->query("name")+"拿到手了！\n"NOR,users());
        return 1;
}

