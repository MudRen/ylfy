
#include <ansi.h>  	
#include <net/dns.h>
#include <mudlib.h>
#include <liebiao.h>
#define ENGLISH_MUD_NAME INTERMUD_MUD_NAME

inherit F_CLEAN_UP;

void create();
nosave int busy = 0;

void create()
{
	seteuid(getuid());
}

mixed main(object me, string arg, int remote)
{
	string str, name, *option;
	object *list;
	int i, j, ppl_cnt, wiz_cnt;
	int opt_long, opt_id, opt_wiz;
	string strMsg;

	if ( !remote && !me )
		return;
	
	if ( !remote && time() - busy < 5 && !wizardp(me) )
		return notify_fail("ϵͳæ�����Ժ�...\n");
	
	wiz_cnt = 0;
	ppl_cnt = 0;
	
	if ( remote && sizeof(arg) < 2 )
		arg="";
	
	if( arg )
	{
		option = explode(arg, " ");
		i = sizeof(option);
		while( i-- )
		{
			switch(option[i])
			{
				case "-l":  strMsg="-l";
							opt_long = 1;
							break;
				case "-i":  strMsg="-i";
							opt_id = 1;
							break;
				case "-w":  strMsg="-w";
							opt_wiz = 1;
							break;
				default:
					
					return notify_fail("ָ���ʽ��who [-l|-i|-w]\n");
			}
		}
	
	}
	{
		str = sprintf(HIW"�� %s"HIW"("HIY"%s"HIW")��\n"NOR,CHINESE_MUD_NAME,ENGLISH_MUD_NAME);
		str += HIW"������������������������������������������������������������������������������������\n"NOR;
		// ��Ȩ���ɵ���������
		list = sort_array(children(USER_OB),"sort_user",this_object());
		
		// ������ߵ�����
		if ( opt_id )
			list = sort_array(children(USER_OB), "sort_user2", this_object());
		
		if( opt_long || opt_wiz )
		{
			j = sizeof(list);
			while( j-- )
			{
				if( !environment(list[j]) ) continue;
				if(me && !me->visible(list[j]) ) continue;
				if(!me && (int)list[j]->query("env/invisibility") > 0 ) continue;
				if( opt_wiz && !wizardp(list[j])) continue;

				str = sprintf("%s%s%s\n", str, RANK_D->query_rank(list[j]), list[j]->short(1));
				
				ppl_cnt ++;
				wiz_cnt ++;
			}
		}
		else
		{
			j = sizeof(list);
			while( j-- )
			{
				if( !environment(list[j]) ) continue;
				if( me && !me->visible(list[j]) ) continue;
				if(!me && (int)list[j]->query("env/invisibility")>0 ) continue;
				
				name = sprintf("%s(%s)",list[j]->query("name"),list[j]->query("id"));

				if ( list[j]->query("gender") == "Ů��" )
					name = "MM" + name + "XX";
				else
					name = "XX" + name + "XX";

				if ( list[j]->query_temp("netdead") )
					name = " #" + name;
				else if ( interactive(list[j]) && query_idle(list[j]) > 300 )
					name = " *" + name;
				else if ( list[j]->query("lixian/biguan") )
					name = " @" + name;
				else
					name = "  " + name;

				if ( interactive(list[j]) && query_idle(list[j]) > 300 )
				{
					if ( !remote && wizardp(me) )
						name = sprintf("%sGG%dXXX", name, (int)query_idle(list[j])/60);
				}

				str = sprintf("%s%-27s%s", str, name, ppl_cnt%3==2?"\n":"");
				ppl_cnt++;
			}
			
			if( ppl_cnt % 3 )
				str += "\n";
		}

		str = replace_string(str, "MM", HIM);
		str = replace_string(str, "GG", HIG" [");
		str = replace_string(str, "XXX", "��]"NOR);
		str = replace_string(str, "XX", NOR);
		str = replace_string(str, " #", HIR" #"NOR);
		str = replace_string(str, " *", HIG" *"NOR);
		str = replace_string(str, " @", HIY" @"NOR);
		
		str += HIW"������������������������������������������������������������������������������������\n"NOR;
		
		if (opt_wiz)
			str = sprintf(HIY"%s"HIW"����"HIG"%s"HIW"λ��ʦ�����У�ϵͳ������%s\n"NOR, str, chinese_number(wiz_cnt),query_load_average() + "��");
		else
			str = sprintf(HIY"%s"HIW"����"HIG"%s"HIW"λʹ���������У�ϵͳ������%s\n"NOR, str, chinese_number(ppl_cnt),query_load_average() + "��");

		if ( !opt_long && !opt_wiz )
			str += HIM"��ɫ "HIW"��ʾŮ�ԡ�"HIR"# "HIW"��ʾ�����С�"HIG"* "HIW"��ʾ�����С�"HIY"@ "HIW"��ʾ���������С�\n"NOR;
		
		if( remote )
			return str;
		
		busy = time();
		
		/* if (sizeof(str) < __LARGEST_PRINTABLE_STRING__ )
			write(str);
		else */
			me->start_more(str);
		
		return 1;
	}
}

// ��Ȩ���ɵ͵�������
int sort_user(object ob1, object ob2)
{
	return (int)SECURITY_D->get_wiz_level(ob2) - (int)SECURITY_D->get_wiz_level(ob1);
}

// ������ߵ�����
int sort_user2(object ob1, object ob2)
{
	return (int)ob1->query("combat_exp") - (int)ob2->query("combat_exp");
}

int help(object me)
{
	write(@HELP
ָ���ʽ : who [@<MudName>] [-l|-i|-w]
���ָ������г����������ϻ������е� Mud ����Ҽ���ȼ���
@<MudName> [-l|-i|-w] ����who @The.Master.Of.Hero -w
-l ѡ���г��ϳ���ѶϢ��
-i ֻ�г���ҵ�Ӣ�Ĵ��š�
-w ֻ�г��������е���ʦ��
���ָ� finger
HELP);

	return 1;
}
