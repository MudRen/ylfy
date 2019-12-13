// clone.c
#include "/doc/help.h"
inherit F_CLEAN_UP;
int main(object me, string file)
{
	object obj;
	string err,str, msg, file_temp;	
	
	seteuid( geteuid(me) );
	
	if (!file) file = me->query("cwf");
	if (!file) return notify_fail("��Ҫ����ʲ�������\n");
	
	file = resolve_path(me->query("cwd"), file);
	file_temp = resolve_path(me->query("cwd"), file);
	file_temp = "/binaries" + file_temp;
	
	if( sscanf(file, "%*s.c") != 1 ) file += ".c";
	if( sscanf(file_temp, "%*s.b") != 1 ) file_temp += ".b";
	
	me->set("cwf", file);
	
	if( (file_size(file)<0 && file_size(file_temp)<0) 
		|| !(int)SECURITY_D->valid_read(file,me))
		return notify_fail("û���������(" + file + ")��\n");
	if( !find_object(file) ) 
	{
		err = catch(call_other(file, "???"));
		if (err) 
		{
			write("����ʧ�ܣ�" + err + "\n");
			return 1;
		}
	}
	
	err = catch(obj = new(file));
	
	if (err) 
	{
		write("����ʧ�ܣ�" + err + "\n");
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
			return notify_fail("����ʧ�ܣ����������޷����¸���Ķ�����\n");
		}
	}
	//---------------------------------------------------

	if( !stringp(msg = me->query("env/msg_clone")) ) 
		msg = "ֻ��$N�������һָ�������$n��\n";
	
	str = me->query("name") + "(" + me->query("id") + ")������" + obj->query("name") + "(" + obj->query("id") + ")    " + ctime(time())+ "  ��\n";	
	write_file("/log/cmds/clone/"+geteuid(me), str);  	
	
	if( !obj->is_character() && obj->move(me) ) 
	{
		write(obj->query("name") + "���Ƴɹ������������Ʒ����\n");
        message_vision(msg + "\n", me, obj);
		return 1;
	}
	if( obj->move(environment(me)) ) 
	{
		write(obj->query("name") + "���Ƴɹ�������������䡣\n");
        message_vision(msg + "\n", me, obj);
		return 1;
	}
	
	destruct(obj);
	return notify_fail("�޷����Ʋ����ƶ������(" + file + ")��\n");
}

int help(object me)
{
  write(@HELP
ָ���ʽ : clone <����>
���ô�ָ��ɸ����κ����ƶ�֮���(������)��
HELP
    );
    return 1;
}
