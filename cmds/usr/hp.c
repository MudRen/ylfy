
#include <ansi.h>

inherit F_CLEAN_UP;
inherit F_TOMUD;

string status_color(int current, int max);
int potential_lv(int exp);

int main(object me, string arg)
{
	object ob;
	mapping my;
	string level;

	
	seteuid(getuid());
	
	if(!arg)
		ob = me;
	else if (wizardp(me))
	{
		ob = present(arg, environment(me));
		
		if (!ob)
			ob = find_player(arg);
		
		if (!ob)
			ob = find_living(arg);
		
		if (!ob)
			return notify_fail("您要察看谁的状态？\n");
	}
	else
		return notify_fail("只有巫师才可以察看别人的状态。\n");

	if ( me->query("env/myhp_show") && !me->query("xieyi/zmud") )
		tell_object(me, my_hp(ob));
	
	my = ob->query_entire_dbase();
	
	printf(NOR YEL"\n┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"NOR);
	printf(NOR "  "NOR HIY"基本资料——>"NOR  HIW"  中文名："NOR+CYN"["NOR HBBLU"%-12s"NOR CYN"]"NOR HIW"   英文名："NOR+CYN"["NOR HBRED"%-12s"NOR CYN"]"NOR "\n"NOR,ob->name(),capitalize(ob->query("id")));
	printf(NOR YEL"┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"NOR);
    printf(HIR" 〖精神〗%s%6d/%6d %s(%3d%%)"NOR,status_color(my["jing"],my["eff_jing"]),my["jing"],
                my["eff_jing"],status_color(my["eff_jing"],my["max_jing"]),my["eff_jing"]*100/my["max_jing"]);
	printf(HIR"   【精力】%s%6d/%6d (+%3d)\n"NOR,status_color(my["jingli"],my["max_jingli"]),my["jingli"],my["max_jingli"],my["jiajing"]);
    printf(HIR" 〖气血〗%s%6d/%6d %s(%3d%%)"NOR,status_color(my["qi"],my["eff_qi"]),my["qi"],my["eff_qi"],
                status_color(my["eff_qi"],my["max_qi"]),my["eff_qi"]*100/my["max_qi"]);

	printf(HIR"   【内力】%s%6d/%6d (+%3d)\n" NOR,status_color(my["neili"], my["max_neili"]), my["neili"], my["max_neili"],my["jiali"]);
	printf(CYN" 【食物】%s%6d/%6d [%3d%%]"NOR,status_color(my["food"], ob->max_food_capacity()),my["food"], ob->max_food_capacity(),my["food"]*100/ob->max_food_capacity());
	printf(CYN"   【潜能】%s%6d/%6d\n"NOR,HIY,(int)ob->query("potential") - (int)ob->query("learned_points"),ob->query_int()*10);
	printf(CYN" 【饮水】%s%6d/%6d [%3d%%]"NOR,status_color(my["water"], ob->max_water_capacity()),my["water"], ob->max_water_capacity(),my["water"]*100/ob->max_water_capacity());

	//if ( strlen(level = chinese_number(ob->query("xyzx_sys/level"))) > 10 )
		level = sprintf("%d", ob->query("xyzx_sys/level"));

	printf(HIY"   【等级】  "HIW"%-10s"HIY"级"HIW"["HIY"%4s"HIW"]\n"NOR,level,ob->query("xyzx_sys/levup_exp")/(ob->get_levelup_exp()/100)+"%");
	printf(CYN" 【经验】%s%10d / %-10d\n"NOR,HIM,ob->query("xyzx_sys/levup_exp"), ob->get_levelup_exp());
	printf(NOR YEL"┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"NOR);
	
	return 1;
}
string status_color(int current, int max)
{
        int percent;
        if( max>0 ) percent = current * 100 / max;
        else percent = 100;
        if( percent > 100 ) return HIC;
        if( percent >= 90 ) return HIG;
        if( percent >= 60 ) return HIY;
        if( percent >= 30 ) return YEL;
        if( percent >= 10 ) return HIR;
        return RED;
}

int potential_lv(int exp)
{
	int grade;
	
	grade = 100 + exp / 500;
	
	return grade;
}

int help(object me)
{
        write(@HELP
指令格式 : hp
           hp <对象名称>                   (巫师专用)
 
这个指令可以显示你(你)或指定对象(含怪物)的精, 气, 神数值。
 
see also : score
HELP
    );
    return 1;
}

