
#include <ansi.h>	
#include <mudlib.h>	
inherit F_CLEAN_UP;        	
int top_list(object ob1,object ob2);	
int get_score(object ob);	
int main(object me, string arg)	
{	
object *list,*ob;           	
int i;	
string msg,partyzhiwei;     	
if (!me->query("party/id"))		
return notify_fail(YEL"����δ�����κΰ��ɣ�\n"NOR);	
ob=filter_array( users() , "party_listener", this_object(), me->query("party/id") );           		
list = sort_array(ob, (: top_list :));	
msg =  "\n"+HIW"     ��"+me->query("party/name")+"�����߳�Ա�б�"NOR" \n"+HIW;                      	
msg += "    ����������������������������������������������������������\n";      	
msg += "    ��      ��        Ա     ��    ְ    λ   ��  �� �� ��  ��\n";      
msg += "    �ĩ�������������������������������������������������������\n";  	
for (i = 0 ;i < sizeof(list) ; i++) {                   	
if(list[i]->query("party/zhu"))       	
{	
partyzhiwei="   ��    ��   ";	
msg +=HIC;      	
}	
else  if(list[i]->query("party/zhanglao"))       	
{
partyzhiwei="   ��    ��   ";   	
msg +=HIR;              	
}
else	
{ 	
partyzhiwei="   ��    ��   ";	
msg +=HIW;	
}	
msg += sprintf("    ��%-22s    %-10s              ��\n"NOR,list[i]->query("name")+"("+                        	
capitalize(list[i]->query("id"))+")",partyzhiwei,             	
);    	
}	
msg += HIW+"    ����������������������������������������������������������\n";          	
msg += sprintf(HIY"     Ŀǰ���ڹ���%sλ��Ա���ߡ�\n"NOR,chinese_number(i));
write(msg);	
return 1;	
}	
int top_list(object ob1, object ob2)	
{	
int score1,score2;	
score1 = get_score(ob1);	
score2 = get_score(ob2);	
return 1;                       	
}	
int get_score(object ob)	
{	
int score;       	
score = ob->query("party/id");              	
return score;	
}	
int party_listener(object ppl, string str)	
{	
if( !environment(ppl)) return 0;	
if(ppl->query("party/id")==str ) return 1;		
else return 0;	
}
int help(object me)	
{	
write(@HELP	
ָ���ʽ : partylist 	
�����ָ����Բ�ѯ�������߳�Ա��  	
HELP	
);	
return 1;	
}	
