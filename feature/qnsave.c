//潜能银行

#define MAX_CUN_QIANNENG 50000000

#include <dbase.h>
#include <ansi.h>

//保存潜能
int cun_qn(string arg)
{
	object ob;
	int temp_qn, my_qn, qn;

	ob = this_player();
	my_qn = ob->query("potential");

	if ( ob->query("temp_svqn") )
		temp_qn = ob->query("temp_svqn");
	else temp_qn = 0;

	if ( !ob || !living(this_object()) )
		return 0;

	if( !arg )
        return notify_fail("你要保存多少点潜能。\n");

	if ( sscanf(arg, "%d", qn) != 1 )
		return notify_fail("你要保存多少点潜能。\n");

	if ( !qn )
		return notify_fail("你要保存多少点潜能。\n");

	if ( qn < 1 || qn > MAX_CUN_QIANNENG )
		 return notify_fail("你每次只能存"HIY" 1～5000万 "NOR"点潜能。\n");

	if ( qn > my_qn )
		return notify_fail("你没有那么多潜能。\n");

	if ( qn + temp_qn > MAX_CUN_QIANNENG )
		return notify_fail("你已存有 "HIY + temp_qn + NOR" 点潜能，还能存 "HIG + (MAX_CUN_QIANNENG - temp_qn) + NOR"点潜能。\n");

	ob->add("potential",-qn);
	ob->add("temp_svqn",qn);
	
	if ( temp_qn > MAX_CUN_QIANNENG)
		ob->set("temp_svqn",MAX_CUN_QIANNENG);

	ob->save();
	tell_object(ob, "你存进了 " + qn + " 点潜能，你一共在潜能银行存有 " + (temp_qn+qn) + " 点潜能。\n");
	return 1;
}

//取出潜能
int qu_qn(string arg)
{
	object ob;
	int temp_qn, qn;

	ob = this_player();

	if ( ob->query("temp_svqn") )
		temp_qn = ob->query("temp_svqn");
	else temp_qn = 0;

	if ( !ob || !living(this_object()) )
		return 0;

	if( !arg )
        return notify_fail("你要取出多少点潜能。\n");
	
	if ( sscanf(arg, "%d", qn) != 1 )
		return notify_fail("你要取出多少点潜能。\n");

	if ( !qn )
		 return notify_fail("你要取出多少点潜能。\n");

	if ( qn < 1 || qn > MAX_CUN_QIANNENG )
		return notify_fail("你每次只能取出"HIY" 1～500万 "NOR"点潜能。\n");

	if ( qn > temp_qn )
		return notify_fail("你的潜能银行里没有那么多潜能。\n");

	ob->add("temp_svqn",-qn);
	ob->add("potential", qn, 1);
	tell_object(ob, "你从潜能银行取出了 " + qn + " 点潜能，你在潜能银行还有 " + (temp_qn-qn) + " 点潜能。\n");
	ob->save();
	return 1;
}

//查询存有的潜能
int cha_qn(string arg)
{
	object *who, ob;
	int temp_qn, i;
	string temp;

	ob = this_player();

	if ( ob->query("temp_svqn") )
		temp_qn = ob->query("temp_svqn");
	else temp_qn = 0;

	if ( !ob || !living(this_object()) )
		return 0;
	
	tell_object(ob, this_object()->name(1)+"在你耳边悄悄告诉你：你已经存有 " + temp_qn + " 点潜能啦。\n");

	if ( wizardp(ob) )
	{
		temp = HIY"在线玩家潜能银行状况查询:\n" + 
			HIC"玩家名(ID)                    存有潜能\n";
		who = users();
		for (i=0; i<sizeof(who); i++)
		{
			temp += sprintf(HIW"%-30s"HIY"%-9d\n"NOR, who[i]->name(1)+"("+who[i]->query("id")+")",who[i]->query("temp_svqn"));
		}
		ob->start_more(temp);
	}

	return 1;
}