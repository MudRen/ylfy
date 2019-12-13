#ifndef __TOMUD__C__
#define __TOMUD__C__

#include <liebiao.h>

varargs string my_hp(object me, object ob)
{
	string msg;
	mapping my, tmp_data;

	if ( !objectp(me) ) return HP("");
	my = me->query_entire_dbase();
	msg = "maxjing="+my["max_jing"]+";";
	msg += "effjing="+my["jing"]+";";
	msg += "eff_jing="+my["eff_jing"]+";";
	msg += "maxqi="+my["max_qi"]+";";
	msg += "effqi="+my["qi"]+";";
	msg += "eff_qi="+my["eff_qi"]+";";
	msg += "maxjingli="+(my["max_jingli"])+";";
	msg += "effjingli="+my["jingli"]+";";
	msg += "maxneili="+(my["max_neili"])+";";
	msg += "effneili="+my["neili"]+";";
	msg += "maxfood="+me->max_food_capacity()+";";
	msg += "efffood="+my["food"]+";";
	msg += "maxwater="+me->max_water_capacity()+";";
	msg += "effwater="+my["water"]+";";
	
	tmp_data = me->query_entire_temp_dbase();
	if ( !objectp(ob) )
	{
		if ( me->is_fighting() && stringp(tmp_data["������"]) )
		{
			msg += "yourmj="+tmp_data["yourmj"]+";";
			msg += "yourej="+tmp_data["yourej"]+";";
			msg += "your_ej="+tmp_data["your_ej"]+";";
			msg += "yourmq="+tmp_data["yourmq"]+";";
			msg += "youreq="+tmp_data["youreq"]+";";
			msg += "your_eq="+tmp_data["your_eq"]+";";
			msg += "������="+tmp_data["������"]+";";
		}
		return HP(msg);
	}

	my = ob->query_entire_dbase();
	msg += "yourmj="+my["max_jing"]+";";
	tmp_data["yourmj"]=my["max_jing"];
	msg += "yourej="+my["jing"]+";";
	tmp_data["yourej"]=my["jing"];
	msg += "your_ej="+my["eff_jing"]+";";
	tmp_data["your_ej"]=my["eff_jing"];
	msg += "yourmq="+my["max_qi"]+";";
	tmp_data["yourmq"]=my["max_qi"];
	msg += "youreq="+my["qi"]+";";
	tmp_data["youreq"]=my["qi"];
	msg += "your_eq="+my["eff_qi"]+";";
	tmp_data["your_eq"]=my["eff_qi"];
	msg += "������="+filter_color(ob->query("name"))+";";
	tmp_data["������"]=filter_color(ob->query("name"));

	return HP(msg);
}

#endif
