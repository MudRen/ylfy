
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
if (!wizardp(me))		
return notify_fail(YEL"ֻ����ʦ���ܲ�ѯ��Ա������\n"NOR);	
ob = filter_array(children(USER_OB), (: $1->query("xy_huiyuan") && !wizardp($1) :));	
list = sort_array(ob, (: top_list :));
msg =  "\n"+HIW"     ��"HIY"Ϧ������"HIC" ��Ա��ѯ�б� \n"+HIW;                      	
msg += "    ������������������������������������������������������������\n";      	
msg += "    ��      ��        Ա     ��    ʱ    ��   ��  ��      ��  ��\n";      
msg += "    �ĩ���������������������������������������������������������\n"NOR;  	
for (i = 0 ;i < sizeof(list) ; i++) {                   	
if(list[i]->query("xy_huiyuan")=="2006��1��21��" || list[i]->query("xy_huiyuan")=="2005��12��31��" || list[i]->query("xy_huiyuan")=="2005��12��19��" || list[i]->query("xy_huiyuan")=="2005��10��25��" || list[i]->query("xy_huiyuan")=="2005��10��15��" || list[i]->query("xy_huiyuan")=="2005��10��10��" || list[i]->query("xy_huiyuan")=="2005��10��13��")       	
{	
partyzhiwei="   һ    ��   ";	
msg +=HIG;      	
}
else  if(list[i]->query("xy_huiyuan")=="2005��9��10��")       	
{
partyzhiwei="   ʮһ ��   ";   	
msg +=GRN;              	
}
else  if(list[i]->query("xy_huiyuan")=="2005��8��10��")       	
{
partyzhiwei="   ʮ    ��   ";   	
msg +=GRN;              	
}
else  if(list[i]->query("xy_huiyuan")=="2005��7��10��")       	
{
partyzhiwei="   ��    ��   ";   	
msg +=GRN;              	
}
else  if(list[i]->query("xy_huiyuan")=="2005��6��10��")       	
{
partyzhiwei="   ��    ��   ";   	
msg +=GRN;              	
}
else  if(list[i]->query("xy_huiyuan")=="2005��5��13��" || list[i]->query("xy_huiyuan")=="2005��5��10��" || list[i]->query("xy_huiyuan")=="2005��5��11��")       	
{
partyzhiwei="   ��    ��   ";   	
msg +=GRN;              	
}
else  if(list[i]->query("xy_huiyuan")=="2005��10��19��" || list[i]->query("xy_huiyuan")=="2005��10��18��" || list[i]->query("xy_huiyuan")=="2005��10��11��" || 
	list[i]->query("xy_huiyuan")=="2005��8��12��" || list[i]->query("xy_huiyuan")=="2005��8��2��" || list[i]->query("xy_huiyuan")=="2005��8��26��" || 
	list[i]->query("xy_huiyuan")=="2005��7��15��" || list[i]->query("xy_huiyuan")=="2005��7��13��" || list[i]->query("xy_huiyuan")=="2005��6��30��" || list[i]->query("xy_huiyuan")=="2005��6��28��" || list[i]->query("xy_huiyuan")=="2005��6��25��" || list[i]->query("xy_huiyuan")=="2005��6��18��" || list[i]->query("xy_huiyuan")=="2005��6��16��" || list[i]->query("xy_huiyuan")=="2005��6��13��" || list[i]->query("xy_huiyuan")=="2005��5��29��" || list[i]->query("xy_huiyuan")=="2005��5��21��" || list[i]->query("xy_huiyuan")=="2005��5��16��" || list[i]->query("xy_huiyuan")=="2005��5��14��" || list[i]->query("xy_huiyuan")=="2005��5��12��" || list[i]->query("xy_huiyuan")=="2005��4��30��" || list[i]->query("xy_huiyuan")=="2005��4��13��" || list[i]->query("xy_huiyuan")=="2005��4��12��" || list[i]->query("xy_huiyuan")=="2005��4��10��" || list[i]->query("xy_huiyuan")=="2005��4��11��")       	
{
partyzhiwei="   ��    ��   ";   	
msg +=YEL;              	
}
else  if(list[i]->query("xy_huiyuan")=="2005��4��4��" || list[i]->query("xy_huiyuan")=="2005��3��10��")       	
{
partyzhiwei="   ��    ��   ";   	
msg +=HIW;              	
}
else  if(list[i]->query("xy_huiyuan")=="2005��2��10��")       	
{
partyzhiwei="   ��    ��   ";   	
msg +=HIW;              	
}
else  if(list[i]->query("xy_huiyuan")=="2005��2��25��" || list[i]->query("xy_huiyuan")=="2005��2��7��" || list[i]->query("xy_huiyuan")=="2005��1��18��" || list[i]->query("xy_huiyuan")=="2005��1��14��" || list[i]->query("xy_huiyuan")=="2005��1��13��" || list[i]->query("xy_huiyuan")=="2005��1��10��" || list[i]->query("xy_huiyuan")=="2005��1��11��")       	
{
partyzhiwei="   ��    ��   ";   	
msg +=HIW;              	
}
else  if(list[i]->query("xy_huiyuan")=="2004��12��10��")       	
{
partyzhiwei="   ��    ��   ";   	
msg +=HIW;              	
}
else	
{ 	
partyzhiwei="   һ    ��   ";	
msg +=HIW;	
}	
msg += sprintf("    ��%-22s    %-10s %-15s��\n"NOR,list[i]->query("name")+"("+                        	
capitalize(list[i]->query("id"))+")",partyzhiwei,list[i]->query("xy_huiyuan")             	
);    	
}	
msg += HIW+"    ������������������������������������������������������������\n";          	
msg += sprintf(HIY"     Ŀǰ��Ϸ�й��� "HIG"%s"HIY" λ��Ա���ߡ�\n"NOR,chinese_number(i));
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
score = ob->query("xy_huiyuan");              	
return score;	
}	
int party_listener(object ppl, string str)	
{	
if( !environment(ppl)) return 0;	
if(ppl->query("xy_huiyuan")==str ) return 1;		
else return 0;	
}
int help(object me)	
{	
write(@HELP	
ָ���ʽ : huiyuan 	
�����ָ����Բ�ѯ��Ϸ�еĻ�Ա������  	
HELP	
);	
return 1;	
}	
