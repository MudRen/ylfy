// snoop.c
#include <ansi.h>
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
	object ob;
	if( !arg ) {
		if( objectp(ob = query_snooping(me)) )
			write("���������ڼ���" + ob->query("name") + "���յ���ѶϢ��\n");
		return 1;
        } else if( arg=="None" ) {
		if( objectp(ob = query_snooping(me))
&&      wiz_level(ob) >= wiz_level(me))	
			tell_object(ob, HIW + me->name(1) + "ֹͣ���������յ���ѶϢ��\n" NOR);
		snoop(me);
		write("Ok.\n");
		return 1;
	}
	ob = find_player(arg);
	if(!ob) ob = find_living(arg);
	if(!ob || !me->visible(ob)) return notify_fail("û������ˡ�\n");
	if( wizhood(me) != "(boss)"
&&      wiz_level(me) <= wiz_level(ob))	
		return notify_fail("��û�м���" + ob->name() + "������ѶϢ��Ȩ����\n");
    if( me==ob ) return notify_fail("���� snoop None �����������ע����None\n");
		
	snoop(me, ob);
      if (ob->query_temp("big5"))
        me->set_temp("snoop-big5",1);
      else
        me->delete_temp("snoop-big5");
	write("�����ڿ�ʼ����" + ob->name(1) + "���յ���ѶϢ��\n");
    if(userp(ob)&&!me->query("env/no_snoop")) log_file("SNOOP_PLAYER",
		sprintf("%s(%s) snoops %s on %s.\n", me->name(1), geteuid(me), ob->name(1),
			ctime(time()) ) );
if( wizardp(ob) && wizhood(me) != "(boss)") 
		tell_object(ob, HIW + me->name(1) + "��ʼ���������յ���ѶϢ��\n" + NOR);
	return 1;
}
int help()
{
	write(@TEXT
ָ���ʽ��snoop <ĳ��>|none
��������ʹ������������ѶϢ��snoop None ��ȡ��������(ע��:�Ǵ�д��N)
TEXT
	);
	return 1;
}
