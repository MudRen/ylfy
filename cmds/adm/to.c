// to.c
inherit F_CLEAN_UP;
// Don't want this command be cleaned up while typing long string.
int help(object me);
int do_to(object me, string arg, string str)
{
if(!arg || arg=="chat" || arg=="es" || arg=="rumor" || arg=="mud" || arg=="to" || arg=="say")
        if (!wizardp(me))
           return help(me);
        seteuid(getuid());
        if (strlen(str)>900) str=str[0..900];
        if(arg) me->force_me(arg + " " + str);
        else me->force_me(str);
        return 1;
}
int main(object me, string arg)
{
        if (!arg) return help(me);
        me->edit( (: do_to, me, arg :) );
        return 1;
}
int help(object me)
{
write(@HELP
ָ���ʽ : to <ָ��>
����һ������������ϵ�����, <ָ��>ͨ�������ѶϢ��ָ����
say , tell , describe , chat , reple ........�ȡ�
���� : 
 to say
 �����뿪�� '.'��ȡ�������� '~q'��ʹ���ڽ��б༭���� '~e'��
 ����������������������������������������������������������
 ��������С��� : ��ѩ
 ��������С��å : ������
�������Ƽ��ԺԺ�� : ����
���������ɳ������� : ����
 .
�����өĻ�ϵĽ������ :
�Լ���һ�Ծ�֪����
HELP
    );
    return 1;
}

