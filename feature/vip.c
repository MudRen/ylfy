
#include <ansi.h>
inherit F_DBASE;

void del_vip(object ob, string vip)
{
	int now_year,now_moon,now_day,vip_year,vip_moon,vip_day;

	if ( !sscanf(CHINESE_D->chinese_time(5,ctime(time())), "%d��%d��%d��", now_year, now_moon, now_day) 
		|| !sscanf(vip, "%d��%d��%d��", vip_year, vip_moon, vip_day) )
		return;

	if (vip_year < now_year)
	{
		ob->delete("xy_huiyuan");
		ob->delete("xyhy_type");
	}
	else
	{
		if (vip_year == now_year && vip_moon < now_moon)
		{
			ob->delete("xy_huiyuan");
			ob->delete("xyhy_type");
		}
		else
		{
			if (vip_year == now_year && vip_moon == now_moon && vip_day <= now_day)
			{
				ob->delete("xy_huiyuan");
				ob->delete("xyhy_type");
			}
		}
	}
}