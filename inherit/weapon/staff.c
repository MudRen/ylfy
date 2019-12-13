// staff.c
#include <weapon.h>
#ifdef AS_FEATURE
#include <dbase.h>
#else
inherit EQUIP;
#endif
varargs void init_staff(int damage, int flag, int v)
{
    if( !v && clonep(this_object()) ) return; // �� v ��Ϊ��̬װ��
    set("weapon_prop/damage", damage);
    set("flag", (int)flag | LONG );
    set("skill_type", "staff");
    if( !query("actions") ) {
        set("actions", (:call_other, WEAPON_D, "query_action" :) );
        set("verbs", ({ "bash", "crush", "slam" }) );
    }
}