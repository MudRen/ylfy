// monster.c

#include <race/monster.h>
void setup_monster(object ob)
{
	mapping my;
	my = ob->query_entire_dbase();
	my["unit"] = "ֻ";
	
	if( undefinedp(my["gender"]) ) my["gender"] = "����";
	if( undefinedp(my["age"]) ) my["age"] = random(80) + 5;
	if( undefinedp(my["str"]) ) my["str"] = random(41) + 10;
	if( undefinedp(my["int"]) ) my["int"] = random(41) + 10;
	if( undefinedp(my["per"]) ) my["per"] = random(11) + 10;
	if( undefinedp(my["con"]) ) my["con"] = random(41) + 10;
	if( undefinedp(my["dex"]) ) my["dex"] = random(41) + 10;

	//��������
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
	// ������
	if ( !ob->query("xysys_map_xy/x") )
		ob->set("xysys_map_xy/x",random(6) + 1);

	// ������
	if ( !ob->query("xysys_map_xy/y") )
		ob->set("xysys_map_xy/y",random(6) + 1);
	//--------------------------------------------------------------------------
#endif

	if( undefinedp(my["max_jing"]) ) {
		if( my["age"] <= 3 ) my["max_jing"] = 50;
		else if( my["age"] <= 10 ) my["max_jing"] = 50 + (my["age"] - 3) * 30;
		else if( my["age"] <= 60 ) my["max_jing"] = 260 + (my["age"] - 10) * 5;
		else my["max_jing"] = my["max_jing"] = 510 + (my["age"] - 60);
	}
	if( undefinedp(my["max_qi"]) ) {
		if( my["age"] <= 10 ) my["max_qi"] = 100;
		else if( my["age"] <= 30 ) my["max_qi"] = 100 + (my["age"] - 10) * 30;
		else my["max_qi"] = my["max_qi"] = 700 + (my["age"] - 30) * 10;
	}
	//	NOTE: monster has no initial limbs defined, you must define it yourself.
	//	ob->init_limbs(LIMBS);
	if( !ob->query_weight() ) ob->set_weight(BASE_WEIGHT + (my["str"] - 10)* 2000);
		ob->set("water",ob->max_water_capacity());
		ob->set("food",ob->max_food_capacity());
}
