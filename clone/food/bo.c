// ²¨°åÌÇ
#include <weapon.h>
inherit F_FOOD;
inherit SWORD;
void create()
{
        set_name(MAG "²¨ °å ÌÇ" NOR, ({"suger"}));
        set_weight(60);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "Ò»¿é¡°QCÅÆ¡±²¨°åÌÇ¡£ºìÀïÍ¸°×µÄ£¬ÈË¼ûÈË°®Ò®¡£\n");
                set("unit", "¿é");
                set("value", 1000000);
                set("no_sell", 1);
                set("food_remaining", 1);
                set("food_supply", 30);
        init_sword(1,2);
	    }
        setup();
    set("skill_type", "hammer");
    if( !query("actions") ) {
        set("verbs", ({ "bash", "crush", "slam" }) );
        set("actions", (: call_other, WEAPON_D, "query_action" :) );
    }
    }
int finish_eat()
{
        if( !query("weapon_prop") ) return 0;
        set_name("ÌÇ¹÷¹÷", ({ "gun" }) );
        set_weight(150);
        set("long", "Ò»Ö¦ÌÇ¹÷¹÷¡£\n");
    set("skill_type", "sword");
        set("verbs", ({ "slash", "slice", "thrust" }) );
        return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
      this_object()->add("destruct",1);
      if (query("destruct")>1000){
        message_vision("Ö»Ìı°ÉàªÒ»Éù£¬$NÊÖÖĞµÄ"+this_object()->query("name")+"ÒÑ¾­¶Ï³ÉÁ½½Ø¡£\n",me);
        this_object()->unequip();
        this_object()->set("name","¶ÏµôµÄ"+this_object()->query("name"));
        this_object()->set("value",0);
        this_object()->set("weapon_prop",0);
   }


      return 0;
}
int query_autoload() { return 1; }