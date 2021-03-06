//宝石存取系统 

#include <dbase.h>
#include <ansi.h>

string *b_names = ({
  "红",
  "蓝",
  "绿",
  "青",
  "黄",
  "紫",
  "橙",
  "玛瑙", 
  "翡翠", 
  "沉玉", 
  "水晶", 
  "金沙", 
  "猫眼", 
  "钻石", 
  "神之玛瑙",
  "神之翡翠",
  "神之沉玉",
  "神之水晶",
  "神之金沙",
  "神之猫眼",
  "神之钻石",
  "旭日",
  "天空",
  "森林",
  "海洋",
  "火焰",
  "晚霞",
  "沙漠",
  "正之光",
  "慈之光",
  "地之光",
  "海之光",
  "火之光",
  "佛之光",
  "爱之光",
});

string *names = ({
  "hong",
  "blue",
  "green",
  "qing",
  "huang",
  "zi",
  "cheng",
  "manao",
  "feicui",
  "chengyu",
  "shuijing",
  "jinsha",
  "maoyan",
  "zuanshi",
  "god manao",
  "god feicui",
  "god chengyu",
  "god shuijing",
  "god jinsha",
  "god maoyan",
  "god zuanshi",
  "sun",
  "sky",
  "forest",
  "sea",
  "fire",
  "sunshine",
  "sand",
  "justice light",
  "mercy light",
  "earth light",
  "sea light",
  "fire light",
  "gods light",
  "love light",
});

//存储珠宝
int do_cun(string arg)
{
	string isbind;
	object ob;
	string name;

	isbind = "";
	
	if (!living(this_object()))
		return 0;
	
	if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("你要存放什么珠宝？\n");		

	if ((sscanf(arg, "%s baoshi",name) != 1 ))
		return notify_fail("你要存放什么珠宝？\n");

	if (!ob->query("zhubao_save"))
		return notify_fail("你要存放什么珠宝？\n");

	if( ob->query("bind_master_level") )
	{
		isbind = "_bind";
        //return notify_fail("绑定的物品不能存放。\n");
	}
	
	if ( this_player()->query("baoshi_size"+isbind) >= 300 )
		return notify_fail(this_object()->query("name")+"说道：客官，您存放在本店的宝石数量已抵达上限。\n");
	
	message_vision("$N把身上的" + ob->query("name") + "拿出来存进了珠宝店。\n", this_player());

	if (!this_player()->query("baoshi_size"+isbind))
		this_player()->set("baoshi_size"+isbind, 1);
	else
		this_player()->add("baoshi_size"+isbind,1);

	if (!this_player()->query("baoshi_save"+isbind+"/" + name))
		this_player()->set("baoshi_save"+isbind+"/" + name,1);
	else
		this_player()->add("baoshi_save"+isbind+"/" + name,1);

    destruct(ob);
    return 1;
}

//取珠宝
int do_qu(string arg)
{
	object ob;
	string name, isbind;
	int bind;

	isbind = "";
	
	if (!living(this_object()))
		return 0;
	
	if( !arg )
		return notify_fail("你要取出什么珠宝？\n");

	if ( sscanf(arg, "%s,%d", arg, bind) == 2  )
	{
		if ( bind ) 
			isbind = "_bind";
	}

	if ( sscanf(arg, "%s baoshi",name) != 1 )
		return notify_fail("你要取出什么珠宝？\n");

	if (!this_player()->query("baoshi_size"+isbind) 
		|| !this_player()->query("baoshi_save"+isbind) 
		|| this_player()->query("baoshi_size"+isbind) < 1)
		return notify_fail("你要取出什么珠宝？\n");
	
	if (!this_player()->query("baoshi_save"+isbind+"/" + name) 
		|| this_player()->query("baoshi_save"+isbind+"/" + name) < 1)
		return notify_fail(this_object()->query("name")+"说道：客官在本店真的存有这种珠宝吧？\n");

	if (this_player()->query("baoshi_size"+isbind) < 1)
		this_player()->delete("baoshi_size"+isbind);
	else
		this_player()->add("baoshi_size"+isbind,-1);

	if (this_player()->query("baoshi_save"+isbind+"/" + name) < 1)
		this_player()->delete("baoshi_save"+isbind+"/" + name);
	else
		this_player()->add("baoshi_save"+isbind+"/" + name,-1);

	ob = new("/quest/baoshi/baoshis/"+name);

	if ( bind )
		ob->set("bind_master_level/"+this_player()->query("id"), 2);

	if (sizeof(all_inventory(this_player()))>50)
	{
		tell_object(this_player(), this_object()->query("name")+"说道：客官，你的行囊似乎装不下东西了吧？\n");
		destruct(ob);
		return 1;
	}

	if ((int)this_player()->query_encumbrance() + ob->weight() > (int)this_player()->query_max_encumbrance())
	{
		tell_object(this_object()->query("name")+"说道：客官，你的负重过大了哦，真的现在就要取吗？\n");
		destruct(ob);
		return 1;
	}
	
	if (ob->move(this_player()))
		message_vision("$N从珠宝店取出" + ob->query("name") + "放进了行囊。\n", this_player());
	
	return 1;
}


//查询宝石
int do_chaxun(string arg)
{
	string isbind;
	string str;
	object me,obj;
	int i, num;
	
	if (!living(this_object()))
		return 0;

	isbind = "";
	
	me=this_player();
	
	if (arg)
	{
		if( wizardp(me))
		{
			obj = find_player(arg);
			
			if( !obj )
				obj = find_living(arg);
			
			if( !obj )
				obj = present(arg, environment(me));
        }
		else
			return 0;
    }
    
	if (!objectp(obj))
		obj=me;
    
	if ( (!obj->query("baoshi_size") 
			|| !obj->query("baoshi_save") 
			|| obj->query("baoshi_size") < 1) 
		&& (!obj->query("baoshi_size_bind") 
			|| !obj->query("baoshi_save_bind") 
			|| obj->query("baoshi_size_bind") < 1))
		return notify_fail(this_object()->query("name")+sprintf("说道：%s并未在本店存放过任何珠宝。\n",obj==me?"你":obj->short(1)));
	
	str = "\n"+((obj==me)?"你":obj->query("name"))+"在本店共存放了 "HIW+obj->query("baoshi_size")+NOR" 颗不绑定宝石("HIY"存放数量上限300"NOR")\n"
		+ "及 "HIW+obj->query("baoshi_size_bind")+NOR" 颗绑定宝石("HIY"存放数量上限300"NOR")：\n\n"NOR;
	
	for ( num=0; num<2; num++ )
	{
		if ( num == 0 )
		{
			isbind = "";
			if ( !obj->query("baoshi_size"+isbind) 
				|| !obj->query("baoshi_save"+isbind) 
				|| obj->query("baoshi_size"+isbind) < 1 )
				continue;
			str += "不绑定的宝石有：\n";
		} else {
			isbind = "_bind";
			if ( !obj->query("baoshi_size"+isbind) 
				|| !obj->query("baoshi_save"+isbind) 
				|| obj->query("baoshi_size"+isbind) < 1 )
				continue;
			str += "\n绑定的宝石有：\n";
		}
		for ( i=0; i < sizeof(names); i++ )
		{
			if (obj->query("baoshi_save"+isbind+"/"+names[i]) 
				&& obj->query("baoshi_save"+isbind+"/"+names[i]) > 0)
			{
				if (i == 0 || i%7 == 0)
				str+=sprintf("%-40s ：%s \n",HIR+b_names[i]+"宝石"NOR+"("+names[i]+" baoshi)",obj->query("baoshi_save"+isbind+"/"+names[i])+" 颗");
				if (i == 1 || i%7 == 1)
				str+=sprintf("%-40s ：%s \n",HIB+b_names[i]+"宝石"NOR+"("+names[i]+" baoshi)",obj->query("baoshi_save"+isbind+"/"+names[i])+" 颗");
				if (i == 2 || i%7 == 2)
				str+=sprintf("%-40s ：%s \n",HIG+b_names[i]+"宝石"NOR+"("+names[i]+" baoshi)",obj->query("baoshi_save"+isbind+"/"+names[i])+" 颗");
				if (i == 3 || i%7 == 3)
				str+=sprintf("%-40s ：%s \n",HIC+b_names[i]+"宝石"NOR+"("+names[i]+" baoshi)",obj->query("baoshi_save"+isbind+"/"+names[i])+" 颗");
				if (i == 4 || i%7 == 4)
				str+=sprintf("%-40s ：%s \n",HIY+b_names[i]+"宝石"NOR+"("+names[i]+" baoshi)",obj->query("baoshi_save"+isbind+"/"+names[i])+" 颗");
				if (i == 5 || i%7 == 5)
				str+=sprintf("%-40s ：%s \n",HIM+b_names[i]+"宝石"NOR+"("+names[i]+" baoshi)",obj->query("baoshi_save"+isbind+"/"+names[i])+" 颗");
				if (i == 6 || i%7 == 6)
				str+=sprintf("%-40s ：%s \n",YEL+b_names[i]+"宝石"NOR+"("+names[i]+" baoshi)",obj->query("baoshi_save"+isbind+"/"+names[i])+" 颗");
			}
		}
	}
	write(str);
	return 1;
}