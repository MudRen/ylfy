//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5
//by lilong�޸�2002.01.12

#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
        set_name(HIG"��"HIY"��"HIM"��"NOR, ({"qixing sword", "sword"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		  set("icon", "10018");
                set("long", "һ�Ѵ������ǵĽ����������ǳ��Ļ�����\n");
                set("value", 10000);
                set("material", "crimsonsteel");
                set("wield_msg",
"$N��ৡ���һ�����һ��$n�������У�\n");
                set("unwield_msg",
"$N�����е�$n�������䣬���¶��һ˿Ц�⣮\n");

        }
        init_sword(200);
        set("is_monitored",1);
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{           
       int pro;
	int dam;
	pro = (int) victim->query_temp("apply/armor_vs_fire");
	dam = (int) me->query("force");
	if(dam > pro)
	{
       victim->receive_wound("jing",20); 
	return HIG"��"+HIY"��"+HIM"��"+HIW"���һ���ŵ�"+NOR"$n"+HIW"����ʧ�롣\n" NOR;
	}
           

}
