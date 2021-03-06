// wear.c

#include <ansi.h>
inherit F_CLEAN_UP;
int do_wear(object me, object ob);
int main(object me, string arg)
{
	object ob, *inv;
	int i, count;
	if( !arg ) return notify_fail("你要穿戴什么？\n");
	if ( me->query_condition("no_equip") )		
              return notify_fail("你双手酸麻，暂时不能抓握穿戴装备。\n");
	if(arg=="all") {
		inv = all_inventory(me);
		for(count=0, i=0; i<sizeof(inv); i++) {
			if( inv[i]->query("equipped") ) continue;
			if((int)me->query("str") < (int)inv[i]->query("wear_str")) continue;
			if((int)me->query("con") < (int)inv[i]->query("wear_con")) continue;
			if(do_wear(me, inv[i]) ) count ++;
		}
		write("Ok.\n");
		return 1;
	}
	if( !objectp(ob = present(arg, me)) )
		return notify_fail("你身上没有这样东西。\n");
	if( ob->query("equipped") )
		return notify_fail("你已经装备着了。\n");
	if (userp(me) && me->query("con") < ob->query("wear_con"))
		return notify_fail("你想装备"+ob->name()+"，怎奈身体不够强壮，只好作罢。\n");
	if (userp(me) && me->query("str") < ob->query("wear_str"))
		return notify_fail("你想装备"+ob->name()+"，怎奈力量不够，只好作罢。\n");
	return do_wear(me, ob);
}
int do_wear(object me, object ob)
{
	string str;
if(ob->query("bonze_only") && (string)me->query("class") !="bonze") return notify_fail("阁下莫非是想抢和尚的饭碗？\n");	
	if( ob->query("female_only")
	&&      (string)me->query("gender") =="男性")
                return notify_fail("这是女人的衣饰，你一个大男人也想穿，羞也不羞？\n");
	if( ob->wear() ) {
		if( !stringp(str = ob->query("wear_msg")) )
			switch( ob->query("armor_type") ) {
				case "cloth":
				case "armor":
				case "boots":
				case "pants":
				case "surcoat":
				case "waist":
					str = YEL "$N穿上一" + ob->query("unit") + "$n。\n" NOR;
					break;
				case "head":
				case "neck":
				case "wrists":
				case "finger":
				case "hands":
					str = YEL "$N戴上一" + ob->query("unit") + "$n。\n" NOR;
					break;
				case "shield":
					str = YEL "$N拿起一" + ob->query("unit") + "$n。\n" NOR;
					break;
				default:
					str = YEL "$N装备$n。\n" NOR;
			}
		message_vision(str, me, ob);
		return 1;
	} else
		return 0;
}
int help(object me)
{
	write(@HELP
指令格式：wear <装备名称>
 
这个指令让你装备某件防具。
 
HELP
    );
    return 1;
}
