// ban.c
// Created by Xiang@XKX

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	string site;
     BAN_D->load_sites();
	if (!arg)
    write(BAN_D->list_sites());
	else if (sscanf(arg, "+ %s", site) == 1) {
		
			BAN_D->add_site(site);
		}
	else if (sscanf(arg, "- %s", site) == 1)
		BAN_D->remove_site(site);
	else write("ָ���ʽ��ban [+|- site]\n");

	return 1;
	
}

int help(object me)
{
	write(@HELP
ָ���ʽ��ban [+|- site]

����������������ֹ�������⵷�ҡ�
HELP
	);
	return 1;
}
