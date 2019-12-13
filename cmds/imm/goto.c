// goto.c
inherit F_CLEAN_UP;
object find_player(string target)
{
	int i;
	object *str;
	str=users();
	for (i=0;i<sizeof(str);i++)
		if (str[i]->query("id")==target)
			return str[i];
	return 0;
}
int main(object me, string arg)
{
	int goto_inventory = 0;
	object obj;
	string msg;

	if( !arg ) return notify_fail("��Ҫȥ���\n");
	if( sscanf(arg, "-i %s", arg) ) goto_inventory = 1;
	if( !arg ) return notify_fail("��Ҫȥ���\n");
	obj = find_player(arg);
	if(!obj) obj = find_living(arg);
	if(!obj || !me->visible(obj)) {
		arg = resolve_path(me->query("cwd"), arg);
		if( !sscanf(arg, "%*s.c") ) arg += ".c";
		if( !(obj = find_object(arg)) ) {
			if( file_size(arg)>=0 ){
				obj=load_object(arg);
				return me->move(obj);
			}
			return notify_fail("û�������ҡ������ط���\n");
		}
	}
if(!goto_inventory && environment(obj))	
obj = environment(obj);	
if( !obj ) return notify_fail("������û�л������� goto��\n");	
if (me->query("env/invisibility")){	
me->move(obj);	
return 1;	
	}
if( stringp(msg = me->query("env/msg_mout")) )	
{if (msg!="") message_vision(msg+"\n", me);}	
else {
message_vision(HIC "ֻ��$N����һָ����պ�Ȼ����һ����ɫ�ʺ磬$N��̤�ʺ�ƮȻ��ȥ��\n" NOR, me);	

me->move(obj);
  }
if( stringp(msg = me->query("env/msg_min")) )	
{if (msg!="") message_vision(msg+"\n", me);}	
	else
message_vision(HIC "���к�Ȼ����һ����ɫ�ʺ磬$N����Ӱ���Ųʺ�ƮȻ������\n" NOR, me);	
	return 1;
}
int help(object me)
{
write(@HELP
ָ���ʽ : goto [-i] <Ŀ��>
 
���ָ��Ὣ�㴫�͵�ָ����Ŀ��. Ŀ�������һ��living �򷿼�
�ĵ���. ���Ŀ����living , ��ᱻ�Ƶ����Ǹ���ͬ���Ļ���.
����м��� -i ������Ŀ���� living, ����ᱻ�Ƶ��� living ��
�� inventory ��.
 
HELP
    );
    return 1;
}
