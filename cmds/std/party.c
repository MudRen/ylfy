// bh.c

#include <ansi.h>;
inherit F_CLEAN_UP;

int main(object me, string arg)
{
object *ob;
if (!me->query("party/id"))	
return notify_fail(YEL"�㻹û�м����κΰ��ɣ�\n"NOR);
if(!arg) arg = ". . .";
ob=filter_array( users() , "party_listener", this_object(), (me->query("party/id") || wizardp(me)) );           	
message("party", HIW"��"+me->query("party/name")+"��"+me->query("name")+"("+me->query("id")+")"+HIW"��"+ arg + "\n"NOR,ob);         	
return 1;
}
int party_listener(object ppl, string str)
{
if( !environment(ppl)) return 0;
if(wizardp(ppl) || ppl->query("party/id")==str ) return 1;	
else return 0;
}
int help(object me)
{
write(@HELP
ָ���ʽ : party <ѶϢ>	
���ָ�����㽫 <ѶϢ> ���ͳ�ȥ, �������ڰ����е��˶�
��������Ļ�.
see also : tune
HELP
);
return 1;
}
