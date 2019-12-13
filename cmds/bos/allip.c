#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me)
{
    int i,j,found;
    string ip;
    object* usrs = users();
    mixed* keys;
    int nUser = sizeof(usrs);
    mapping ips = ([]);
    for(i=0;i<nUser;i++)
    {
	keys = keys(ips);
	found=0;
	ip = query_ip_number(usrs[i]);
	for(j=0;j<sizeof(keys);j++)
	{
	    if(ip == keys[j])
		found=1;
	}
	if(found)
	    ips[ip] += "    "+usrs[i]->query("name")+"("+usrs[i]->query("id")+")";
	else
	    ips+=([ip : "    "+usrs[i]->query("name")+"("+usrs[i]->query("id")+")"]);
    }
    i = 0;
    keys = keys(ips);
    for(j=0;j<sizeof(keys);j++)
    {
	write(HIG+keys[j]+":\n"NOR);
	write(HIW+ips[keys[j]]+"\n"NOR);
	i++;
    }
    printf(HIW"\n�ܹ�%d��ID���ߣ�����%d��ip��\n"NOR,nUser,i);
    return 1;
}

int help(object me)
{
    write(@HELP
����������г���ǰ���ߵ�����ip�Լ�ÿ��ip�ϵ���ҡ�
HELP);
    return 1;
}

