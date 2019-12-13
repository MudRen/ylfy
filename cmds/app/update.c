// update.c
#include "/doc/help.h"
inherit F_CLEAN_UP;

int update_player(object me);

int main(object me, string file)
{
	int i;
	object obj, *inv;
	string err;
	mixed *call_info;

	seteuid( geteuid(me) );
	
	if (!file)
		file = me->query("cwf");
	
	if (!file)
		return notify_fail("��Ҫ���±���ʲ�ᵵ����\n");
	
	if( file == "me" )
		return update_player(me);
	
	if( file == "here")
		file=base_name(environment(me));
	
	else
		{
		if( (obj = present(file, environment(me))) && interactive(obj) )
			return update_player(obj);
		
		if( (obj = present(file, environment(me))))
			file=base_name(obj);
		else
			file = resolve_path(me->query("cwd"), file);
		}
	
	if( !sscanf(file, "%*s.c") )
		file += ".c";
	
	if( file_size(file)==-1)
		return notify_fail("û�����������\n");
	
	if (!SECURITY_D->valid_write(file,me,"update"))
		return notify_fail("�㲻���������ĳ�Ա�����ܸ��£�\n");
	
	me->set("cwf", file);
	
	if (obj = find_object(file))
	{
		if ( base_name(obj)==SECURITY_D )
		{
			if ( SECURITY_D->get_status(me)=="(boss)")
				seteuid( ROOT_UID );
			else
				return notify_fail("�㲻�����±������������\n");
		}

		if (sizeof(call_info = filter_array(call_out_info(), (: $1[0]==$2 :), obj)))
		{
			write("Ŀ����������� "HIY"call_out"NOR" δ��ɣ�\n"HIW);
			foreach (mixed *item in call_info)
				write(sprintf("%-40s %d\n", item[1], item[2]));
			return 1;
		}
		
		if( file_name(obj)==VOID_OB )
			return notify_fail("�㲻���� VOID_OB �����±��� VOID_OB��\n");
		
		inv = all_inventory(obj);
		i = sizeof(inv);
		while(i--)
			
		if( userp(inv[i]) )
			inv[i]->move(VOID_OB, 1);
		else
			inv[i] = 0;
		
		// ɾ���ɵĶ������ļ�
		err = "/binaries"+file[0..<3]+".b";
		write("ɾ���������ļ� "HIY+err+NOR" ...");
		if( file_size(err) < 0 )
			write(HIW"�����ڡ�\n"NOR);
		else 
			if(rm(err))
			write(HIG"�ɹ���\n"NOR);
		else
			write(HIR"ʧ�ܡ�\n"NOR);
		
		destruct(obj);
	}
	
	if (obj)
		return notify_fail("�޷�����ɳ�ʽ�롣\n");
	
	write("���±��� "HIG + file + NOR"��");
	err = catch( call_other(file, "???") );
	
	if (err)
		printf( HIW"��������\n%s\n"NOR, err );
	else
		{
		write("�ɹ���\n"NOR);
		
		if( (i=sizeof(inv)) && (obj = find_object(file)))
		{
			while(i--)
			
			if( inv[i] && userp(inv[i]) )
				inv[i]->move(obj, 1);
			}
        }
	return 1;
}

int update_player(object me)
{
	object env, link_ob, obj;
	env = environment(me);
	
	// First, create the new body.
	link_ob = me->query_temp("link_ob");
	obj = LOGIN_D->make_body(link_ob);
	
	if (!obj)
		return 0;
	
	// Save the data and exec the player to his/her link object.
	me->save();
	exec(link_ob, me);
	destruct(me);
	
	// Restore new body and exec to it via enter_world in LOGIN_D
	obj->restore();
	LOGIN_D->enter_world(link_ob, obj, 1);
	write(HIG"���������ϡ�\n\n"NOR);
	obj->move(env);
	obj->write_prompt();
	return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : update <����|object|here|me|�����>
 
���ָ����Ը��µ���, �����µ������������������. ��Ŀ��Ϊ
'here' ��������ڻ���. ��Ŀ��Ϊ 'me' ������Լ�������. ��Ŀ
��Ϊ�����ɸ���������.
 
HELP
    );
    return 1;
}
 
