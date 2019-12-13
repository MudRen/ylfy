// beast.c

#include <race/beast.h>
mapping combat_action =
([
	"hoof": ([
		"action":		"$N用后腿往$n的$l用力一蹬",
		"damage":		100,
		"damage_type":	"瘀伤",
	]),
	"bite": ([
		"action":		"$N扑上来张嘴往$n的$l狠狠地一咬",
		"damage":		20,
		"damage_type":	"咬伤",
	]),
	"claw": ([
		"action":		"$N用爪子往$n的$l一抓",
		"damage_type":	"抓伤",
	]),
	"poke": ([
		"action":		"$N用嘴往$n的$l一啄",
		"damage":		30,
		"damage_type":	"刺伤",
	]),
	"knock": ([
		"action":		"$N用头往$n的$l用力一撞",
		"damage":		100,
		"damage_type":	"瘀伤",
	]),
]);
string *actions;
void create()
{
	actions = keys(combat_action);
}
void setup_beast(object ob)
{
	mapping my;
	my = ob->query_entire_dbase();
	my["unit"] = "只";
	if( undefinedp(my["actions"]) ) {
		if( pointerp(my["verbs"]) )
			ob->set("default_actions", (: call_other, __FILE__, "query_action" :) );
		else
			my["default_actions"] = ([
				"action": "$N攻击$n的%s，%s\n",
			]);
	}
	
	if( undefinedp(my["gender"]) ) my["gender"] = "雄性";
	if( undefinedp(my["age"]) ) my["age"] = random(40) + 5;
	if( undefinedp(my["str"]) ) my["str"] = random(41) + 5;
	if( undefinedp(my["int"]) ) my["int"] = random(11) + 5;
	if( undefinedp(my["per"]) ) my["per"] = random(31) + 5;
	if( undefinedp(my["con"]) ) my["con"] = random(41) + 5;
	if( undefinedp(my["dex"]) ) my["dex"] = random(41) + 5;
	if( undefinedp(my["kar"]) ) my["kar"] = random(21) + 5;

	//新增属性
	//-------------------------------------------------------------------------
	if ( !ob->query("xyzx_sys/level") ) ob->set("xyzx_sys/level",0);
	if ( !playerp(ob) && !ob->query("xyzx_sys/jingzhun") ) ob->set("xyzx_sys/jingzhun",10);
	if ( !playerp(ob) && !ob->query("xyzx_sys/lingxing") ) ob->set("xyzx_sys/lingxing",10);
	if ( !playerp(ob) && !ob->query("xyzx_sys/minjie") ) ob->set("xyzx_sys/minjie",10);
	if ( !playerp(ob) && !ob->query("xyzx_sys/fanying") ) ob->set("xyzx_sys/fanying",10);
    if ( !ob->query("wuxing/mofa") ) ob->set("wuxing/mofa",random(11));
	if ( !ob->query("max_fashufali") )
	{
		ob->set("fashufali",100);
		ob->set("max_fashufali",100);
	}

#ifdef XYZX_SYS_JULI
	//-------------------------------------------------------------------------
	// 横坐标
	if ( !ob->query("xysys_map_xy/x") )
		ob->set("xysys_map_xy/x",random(6) + 1);

	// 横坐标
	if ( !ob->query("xysys_map_xy/y") )
		ob->set("xysys_map_xy/y",random(6) + 1);
	//--------------------------------------------------------------------------
#endif

	if( undefinedp(my["max_jing"]) ) {
		if( my["age"] <= 3 ) my["max_jing"] = 50;
		else if( my["age"] <= 10 ) my["max_jing"] = 50 + (my["age"] - 3) * 20;
		else if( my["age"] <= 30 ) my["max_jing"] = 190 + (my["age"] - 10) * 5;
		else my["max_jing"] = my["max_jing"] = 290 + (my["age"] - 30);
	}
	if( undefinedp(my["max_qi"]) ) {
		if( my["age"] <= 5 ) my["max_qi"] = 50;
		else if( my["age"] <= 20 ) my["max_qi"] = 50 + (my["age"] - 5) * 25;
		else my["max_qi"] = my["max_qi"] = 425 + (my["age"] - 20) * 5;
	}
	//	NOTE: beast has no initial limbs defined, you must define it yourself.
	//	ob->init_limbs(LIMBS);
	if( !ob->query_weight() ) ob->set_weight(BASE_WEIGHT + (my["str"] - 10)* 2000);
		ob->set("water",ob->max_water_capacity());
		ob->set("food",ob->max_food_capacity());
}
mapping query_action(object me)
{
	string *act;
	act = me->query("verbs");
	return combat_action[act[random(sizeof(act))]];
}
