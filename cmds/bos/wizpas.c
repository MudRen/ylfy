//wizpas
//�ϴ�д�ļ�Ȼ���ˣ�һ��ָ���Ȼд�����飬���� 

#include <login.h>;
inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	object ob,link_ob;
	string id,wizpas;
	if(!arg||sscanf(arg,"%s %s",id,wizpas)!=2)
		return notify_fail("�÷�:wizpas ID ��ʦ��½Ч���룡\n");
	ob=find_player(id);
	if(!ob)
	{
        ob = new(LOGIN_OB);
        ob->set("id",id);
        if( !ob->restore() )
        	return notify_fail("û�������ҡ�\n");
        else
		{                                    
           ob->set("wizpasswd",crypt(wizpas,0));
           tell_object(me, "������ʦ" + ob->query("name") + "("+ob->query("id")
                + ")�ĵ�½Ч����Ϊ��"+wizpas+"��\n");
           log_file( "/cmds/loginpas", sprintf("%s %s(%s)����%s(%s)����ʦ��½Ч����\n",
                ctime(time()), me->query("name"), me->query("id"),
                ob->query("name"), ob->query("id")));
           ob->save();
           destruct(ob);
           return 1;
		}
	}
	link_ob=ob->query_temp("link_ob");
	if(link_ob)
	{
		link_ob->set("wizpasswd",crypt(wizpas,0));
		link_ob->save();
		tell_object(me, "������ʦ" + ob->query("name") + "("+ob->query("id")
			+ "�ĵ�½Ч����Ϊ��"+wizpas+"��\n");
		return 1;
	}
	else
		return notify_fail("�����޷������޸ġ�\n");
	return 1;
}


int help(object me)
{
        write(@HELP
ָ���ʽ : wizpas ID ��ʦ��½Ч����

���ָ��������á��޸���ʦ�ĵ�½Ч���롣

HELP
    );
    return 1;
}