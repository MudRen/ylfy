// partyinfo.c  ��ѯ����
// lisa 2004.1.13 1.00

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me)
{
	int i;
	string *parties;
	string partyowner,partyname,party,time;
	string arg=HIW
		"\n                     Ϧ������֮������ӡ ����б�\n" + 
		"         ����������������������������������������������������     \n" + 
		"             ����                          ��������\n" + 
		"         ����������������������������������������������������     \n";
	
	if( me!=this_player(1) )
		return 0;
	
	parties = explode(read_file("/log/cmds/party"), "\n");
	
	for(i=0; i<sizeof(parties); i++)
	{
		if( parties[i][0]=='#' || sscanf(parties[i], "%s on %s", party, time)!=2 )
			continue;
		
		if( sscanf(party, "%s �������� %s", partyowner, partyname)!=2 )
			continue;
		
		arg=sprintf("%s             %-27s %8s \n",arg,partyowner,partyname );
	}
	write(arg);
	
	return 1;
}
