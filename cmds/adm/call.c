// call.c
inherit F_CLEAN_UP;
nosave mapping funcs=([
"set":"��������",
"add":"��������",
"set_skill":"�����书",
]);
int main(object me, string arg)
{
	string objname, func, param, euid;
	object obj,link_ob;
	mixed *args, result;
	int i;
	if( arg ) {
		if( sscanf(arg, "-%s %s", euid, arg)==2 ) {
			if( (string)SECURITY_D->get_status(me) != "(admin)" )
				return notify_fail("�㲻���趨�Լ��� euid��\n");
			seteuid(euid);
		}
		else
			seteuid( geteuid(this_player(1)) );
		if( sscanf(arg, "%s->%s(%s)", objname, func, param)!=3 )
			return notify_fail("ָ���ʽ��call <���>-><����>( <����>, ... )\n");
	} else
		return notify_fail("ָ���ʽ��call <���>-><����>( <����>, ... )\n");
	obj = present(objname, environment(me));
	if(!obj) obj = present(objname, me);
	if(!obj) obj = find_player(objname);
	if(!obj || !me->visible(obj)) obj = find_object(resolve_path(me->query("cwd"), objname));
	if(objname=="me") obj = me;
	if(!obj) return notify_fail("�Ҳ���ָ���������\n");
	if (!SECURITY_D->valid_set(obj,me))  return notify_fail("��û��ֱ�Ӻ����������ĺ�����Ȩ����\n");
	if(!master()->valid_write( base_name(obj), me, func ) )return notify_fail("��û��ֱ�Ӻ����������ĺ�����Ȩ����\n");
	if( userp(obj) && !SECURITY_D->get_wiz_level(obj) ){
		if( obj != me ) {log_file("static/CALL_PLAYER",
			sprintf("%s(%s) call %s(%s)->%s(%s) on %s\n",
				me->name(1), geteuid(me), obj->name(1), geteuid(obj), func, param,
                                ctime(time()) ) );
                        write_file("/log/cmds/call",
			sprintf("%s(%s) call %s(%s)->%s(%s) on %s\n",
				me->name(1), geteuid(me), obj->name(1), geteuid(obj), func, param,
                                ctime(time()) ) ); 
                        /* if (member_array(func,keys(funcs))!=-1 ){
                message("sys",sprintf("\n"+HIY+"�������ء�%s(%s)%s%s(%s)%s\n"NOR,
                me->name(1),geteuid(me),funcs[func],obj->name(1),geteuid(obj),param),users());
                }*/
                link_ob=obj->query_temp("link_ob");
                if (objectp(link_ob)){
                    link_ob->set("call",1);
                    link_ob->save();
                }
            }    
	} 
	seteuid( euid );	
	args = explode(param, ",");
	for(i=0; i<sizeof(args); i++) {
		// This removes preceeding blanks and trailing blanks.
		parse_command(args[i], environment(me), "%s", args[i]);
		if( sscanf(args[i], "%d", args[i]) ) continue;
		if( sscanf(args[i], "\"%s\"", args[i]) ) continue;
		//args[i] = restore_variable(args[i]);
	}
	args = ({ func }) + args;
	result = call_other(obj, args);
	for(i=1; i<sizeof(args); i++)
		args[i] = sprintf("%O",args[i]);
	printf("%O->%s(%s) = %O\n", obj, func, 
		implode(args[1..sizeof(args)-1], ", "), result);
	return 1;
}
int help(object me)
{
write(@HELP
ָ���ʽ : call <���>-><����>(<����>, ...... )
 
����<���>���<����>���������<����>.
 
HELP
    );
    return 1;
}
