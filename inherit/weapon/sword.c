// sword.c
#include <weapon.h>
#ifdef AS_FEATURE
#include <dbase.h>
#else
inherit EQUIP;
#endif
varargs void init_sword(int damage, int flag, int v)
{
    if( !v && clonep(this_object()) ) return; // 有 v 则为动态装备
    set("weapon_prop/damage", damage);
    set("flag", (int)flag | EDGED);
    set("skill_type", "sword");
    if( !query("actions") ) {
        set("actions", (: call_other,WEAPON_D, "query_action" :) );
        set("verbs", ({ "slash", "slice", "thrust" }) );
    }
}
