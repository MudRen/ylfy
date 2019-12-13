
// mudlist.c Yuj@SJ 1999-6-2

#include <ansi.h>
#include <net/daemons.h>
#include <net/macros.h>

inherit F_CLEAN_UP;
inherit F_DBASE;

int main(object me, string arg)
{
        mapping mud_list;
        mixed *muds;
        string output;
        int loop, size, count=0, total;

        if( !find_object(DNS_MASTER) )
                return notify_fail("��·���鲢û�б����롣\n");

		if ( !DNS_MASTER->query_doing_end() )
			return notify_fail("�����վ��ͬ�������С���������\n");

        //      Obtain mapping containing mud data
        mud_list = (mapping)DNS_MASTER->query_muds();

        if(!mud_list)
                return notify_fail( MUD_NAME + "Ŀǰ��û�и���·������ Mud ȡ����ϵ��\n");

        //      Get list of all mud names within name server
        muds = keys( mud_list ) - ({ "DEFAULT" });

        //      Place mudlist into alphabetical format
        muds = sort_array(muds, 1);

        //      If mudname provided, search server's database for a match
        //      and display its cooresponding address
        if( arg ) arg = upper_case(arg);
        if(arg && arg != "ALL") {
                arg = htonn(arg);
                if(!mapp( mud_list[arg] )) {
                        write(MUD_NAME + "��û�к���� Mud ȡ����ϵ��\n");
                        return 1;
                }
                if( wizardp(me) && !me->query("env/debug") )
                        printf("�й� %s ����Ѷ��\n%O\n", arg, mud_list[arg]);
                else
                        printf("\n�й� %s ����Ѷ��\n"
                                "������������������������������������\n"
                                "�������ƣ�  %s\n"
                                "���ԣ�      %s\n"
                                "�汾��      %s\n"
                                "MudOS��     %s\n"
                                "Mudlib��    %s\n"
                                "������      %s\n"
                                "�˿ڣ�      %s\n"
                                "״̬��      %s\n"
                                "������ң�  %s\n"
                                "����ʱ�䣺  %s\n"
                                "������������������������������������\n\n",
                                mud_list[arg]["NAME"],
                                undefinedp(mud_list[arg]["MUDNAME"])?
                                "����":mud_list[arg]["MUDNAME"],
                                undefinedp(mud_list[arg]["ENCODING"])?
                                "����":(mud_list[arg]["ENCODING"]=="GB"?"���庺��":"���庺��"),
                                undefinedp(mud_list[arg]["VERSION"])?
                                "����":mud_list[arg]["VERSION"],
                                undefinedp(mud_list[arg]["DRIVER"])?
                                "����":mud_list[arg]["DRIVER"],
                                undefinedp(mud_list[arg]["MUDLIB"])?
                                "����":mud_list[arg]["MUDLIB"],
                                mud_list[arg]["HOSTADDRESS"],
                                mud_list[arg]["PORT"],
                                mud_list[arg]["_dns_no_contact"]<1?
                                "����":"�Ͽ�",
                                undefinedp(mud_list[arg]["USERS"])?
                                "����":mud_list[arg]["USERS"],
                                undefinedp(mud_list[arg]["TIME"])?
                                "����":mud_list[arg]["TIME"],
                                );
                return 1;
        }

        output = "������������������������������������������������������������������\n"+
BBLU+HIW" ��������              ��������λַ    �˿� ����ʱ��          ����\n"NOR+
"������������������������������������������������������������������\n";
        //      Loop through mud list and store one by one
        for(loop = 0, size = sizeof(muds); loop<size; loop++) {
                if( !arg && mud_list[muds[loop]]["VERSION"] != MUDLIB_VERSION )
                        continue;
                if( arg ) {
                        if( arg!="ALL" && mud_list[muds[loop]]["MUDLIB"] != MUDLIB_NAME )
                                continue;
                }
                if( mud_list[muds[loop]]["_dns_no_contact"] > 0 ) {
                        if( !me || !wizardp(me) || (wizardp(me) && me->query("env/debug")) )
                                continue;
                }

		if( htonn(upper_case(muds[loop])) == htonn(upper_case(INTERMUD_MUD_NAME)) )
			output +=  BRED+HIY;
			output +=  sprintf(HIW"%-22s %-15s %4s ", 
				(undefinedp(mud_list[muds[loop]]["MUDNAME"])?"":mud_list[muds[loop]]["MUDNAME"]) +
				"(" + upper_case(muds[loop]) + ")",
				mud_list[muds[loop]]["HOSTADDRESS"],
				mud_list[muds[loop]]["PORT"]);
		if (mud_list[muds[loop]]["TIME"] != query(muds[loop])) {
			set(muds[loop], mud_list[muds[loop]]["TIME"]);
			set(muds[loop]+".Time", time());
		}
		if (time() > query(muds[loop]+".Time") + 2100) output += "<ʧȥ��ϵ>";
		else {
			string tmp = "";
			int d, h, m, s;

			total = atoi(mud_list[muds[loop]]["TIME"]);
			d = total / 86400;
			if (d) tmp += d + "��";
			h = (total % 86400) / 3600;
			if (h) tmp += h + "Сʱ";
			m = (total % 3600) / 60;
			if (m) tmp += m + "��";
			s = total % 60;
			if (s) tmp += s + "��";
			output += sprintf("%-16s", tmp);
			if(!undefinedp(mud_list[muds[loop]]["USERS"])) {
				output+=sprintf(" %4s", mud_list[muds[loop]]["USERS"] );
				count += atoi(mud_list[muds[loop]]["USERS"]);
			} else    output+=" ---";
		}

                output += NOR"\n";
        }
	//      Display dumped mudlist output through user's more pager
	output+="������������������������������������������������������������������\n";
	output += HIW"��"HIR"Ϧ������"HIW"��"NOR"����" +HIG+ chinese_number(count) + NOR"λ��������С�\n";
        write( output );

	return 1;
}

int help()
{
	write("\nָ���ʽ��mudlist            �г������е�"MUD_NAME"վ�㡣\n"
		"          mudlist <MudName>  �г�ָ�� Mud ����Ϣ��\n"
		"          mudlist all        �г�Ŀǰ���������е� Mud��\n\n"
        );
        return 1;
}
