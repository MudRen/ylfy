// clone.c
#include "/doc/help.h"
inherit F_CLEAN_UP;
int main(object me, string file)
{
	object obj;
	string err,str, msg, file_temp;	
	
	seteuid( geteuid(me) );
	
	if (!file) file = me->query("cwf");
	if (!file) return notify_fail("你要复制什麽物件？\n");
	
	file = resolve_path(me->query("cwd"), file);
	file_temp = resolve_path(me->query("cwd"), file);
	file_temp = "/binaries" + file_temp;
	
	if( sscanf(file, "%*s.c") != 1 ) file += ".c";
	if( sscanf(file_temp, "%*s.b") != 1 ) file_temp += ".b";
	
	me->set("cwf", file);
	
	if( (file_size(file)<0 && file_size(file_temp)<0) 
		|| !(int)SECURITY_D->valid_read(file,me))
		return notify_fail("没有这个档案(" + file + ")。\n");
	if( !find_object(file) ) 
	{
		err = catch(call_other(file, "???"));
		if (err) 
		{
			write("载入失败：" + err + "\n");
			return 1;
		}
	}
	
	err = catch(obj = new(file));
	
	if (err) 
	{
		write("复制失败：" + err + "\n");
		return 1;
	}

	obj->set("is_wiz_level", wiz_level(me));

	//--------------------------------------------------
	if ( wiz_level(me) < 9 )
	{
		if ( me->query_encumbrance() + obj->weight() > me->query_max_encumbrance() 
			|| me->query_encumbrance() + obj->weight() < 0 
			|| me->query_encumbrance() + obj->weight() < me->query_encumbrance() 
			|| me->query_encumbrance() + obj->weight() < obj->weight()
			|| sizeof(all_inventory(me)) > 45 )
		{
			destruct(obj);
			return notify_fail("复制失败：你身上已无法放下更多的东西。\n");
		}
	}
	//---------------------------------------------------

	if( !stringp(msg = me->query("env/msg_clone")) ) 
		msg = "只见$N伸手凌空一指，变出了$n。\n";
	
	str = me->query("name") + "(" + me->query("id") + ")复制了" + obj->query("name") + "(" + obj->query("id") + ")    " + ctime(time())+ "  。\n";	
	write_file("/log/cmds/clone/"+geteuid(me), str);  	
	
	if( !obj->is_character() && obj->move(me) ) 
	{
		write(obj->query("name") + "复制成功，放在你的物品栏。\n");
        message_vision(msg + "\n", me, obj);
		return 1;
	}
	if( obj->move(environment(me)) ) 
	{
		write(obj->query("name") + "复制成功，放在这个房间。\n");
        message_vision(msg + "\n", me, obj);
		return 1;
	}
	
	destruct(obj);
	return notify_fail("无法复制不能移动的物件(" + file + ")。\n");
}

int help(object me)
{
  write(@HELP
指令格式 : clone <档名>
利用此指令可复制任何能移动之物件(含怪物)。
HELP
    );
    return 1;
}
