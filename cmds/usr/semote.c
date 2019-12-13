// semote.c
//#include "/doc/help.h"

inherit F_CLEAN_UP;
string replace_str(object me,string str)
{
        str = replace_string(str, "$N", me->name(1));
        str = replace_string(str, "$P", "��");
        str = replace_string(str, "$S", RANK_D->query_self(me));
        str = replace_string(str, "$s", RANK_D->query_self_rude(me));
        str = replace_string(str, "$C", "������");
        str = replace_string(str, "$c", "���");
        str = replace_string(str, "$R", "׳ʿ");
        str = replace_string(str, "$r", "����");
        str = replace_string(str, "$n", "ĳ��");
        str = replace_string(str, "$p", "��");
        return str;
}
string replace_str1(object me,string str)
{
        str = replace_string(str, "$N", me->name(1));
        str = replace_string(str, "$P", "��");
        str = replace_string(str, "$S", RANK_D->query_self(me));
        str = replace_string(str, "$s", RANK_D->query_self_rude(me));
        str = replace_string(str, "$C", "������");
        str = replace_string(str, "$c", "���");
        str = replace_string(str, "$R", "׳ʿ");
        str = replace_string(str, "$r", "����");
        str = replace_string(str, "$n", "ĳ��");
        str = replace_string(str, "$p", "��");
        return str;
}
void more(string cmd,string emote_str, int line)
{
        mapping emote;
        string *e,str;
        object me;
        int i;
        me=this_player();
        e = sort_array(EMOTE_D->query_all_emote(), 1);
        switch(cmd) {
        case "b":
        write(ESC+"[2A"+ESC+"[200D"+ESC+"[K");
        line = line - 30;
        if(line<0) line=0;
                for(i=line+15;line<sizeof(e) && line<i; line++){
                emote = EMOTE_D->query_emote(e[line]);
                if (stringp(str=emote[emote_str])){
                        str=replace_str(me,str);
                        write(RED+e[line]+NOR+"\n"+str);
                }
                }
                break;
                case "q":       write("������\n");
                        return;
        default:
                write(ESC+"[2A"+ESC+"[200D"+ESC+"[K");
                for(i=line+15;line<sizeof(e) && line<i; line++){
                emote = EMOTE_D->query_emote(e[line]);
                if (stringp(str=emote[emote_str])){
                        str=replace_str(me,str);
                        write(RED+e[line]+NOR+"\n"+str);
                }
                }
                if( line>=sizeof(e) ){  write("������\n"); return;}
                break;
        }
        printf(YEL"== δ����� " NOR BOLD "%d%%"NOR YEL " == (q �뿪��b ǰһҳ ����������һҳ)\n"NOR,
                (line*100/sizeof(e)) );
        input_to("more", emote_str, line);
}
int main(object me, string arg)
{
        mapping emote;
        string *e,str,emote_str;
        int i;
        e = sort_array(EMOTE_D->query_all_emote(), 1);
        if (!arg){
                str = NOR"                       "+BRED+HIY"[Ϧ������]"HIG" ���鶯���ܻ�\n\n"NOR;
	       	str += "��������������������������������������������������������������������������\n";
                for(i=0; i<sizeof(e); i++)
                        str += sprintf("%-15s%s", e[i], (i%5==4)?"\n": "");
	                me->start_more(str);
                write("\n");
                return 1;
        }
        switch(arg){
                case "1":emote_str="myself";break;
                case "2":emote_str="others";break;
                case "3":emote_str="myself_self";break;
                case "4":emote_str="others_self";break;
                case "5":emote_str="myself_target";break;
                case "6":emote_str="target";break;
                case "7":emote_str="others_target";break;
                default:
                        emote = EMOTE_D->query_emote(arg);
                        if (!sizeof(emote))     return 
notify_fail("û�����emote��\n");
                        if (stringp(str=emote["myself"]))
                                printf("��ָ������ʹ����� emote 
ʱ�����Լ�������ѶϢ:\n"+BOLD+replace_str(me,str)+"\n"+NOR);
                        if (stringp(str=emote["others"]))
                                printf("��ָ������ʹ����� emote 
ʱ�������˿�����ѶϢ:\n"+BOLD+replace_str1(me,str)+"\n"+NOR);
                        if (stringp(str=emote["myself_self"]))
                                printf("���Լ�ʹ����� emote 
ʱ���Լ�������ѶϢ:\n"+BOLD+replace_str(me,str)+"\n"+NOR);
                        if (stringp(str=emote["others_self"]))
                                printf("���Լ�ʹ����� emote 
ʱ�������˿�����ѶϢ:\n"+BOLD+replace_str1(me,str)+"\n"+NOR);
                        if (stringp(str=emote["myself_target"]))
                                printf("�Ա���ʹ����� emote 
ʱ���Լ�������ѶϢ:\n"+BOLD+replace_str(me,str)+"\n"+NOR);
                        if (stringp(str=emote["target"]))
                                printf("�Ա���ʹ����� emote 
ʱ��ʹ�ö��󿴵���ѶϢ:\n"+BOLD+replace_str1(me,str)+"\n"+NOR);
                        if (stringp(str=emote["others_target"]))
                                printf("�Ա���ʹ����� emote 
ʱ�������Լ���ʹ�ö����⣬�����˿�����ѶϢ:\n"+BOLD+replace_str
(me,str)+"\n"+NOR);
                return 1;
        }
        more("",emote_str,0);
        return 1;
}
int help(object me)
{
  write(@HELP
ָ���ʽ : semote <����> || <emote>
���ָ������г�Ŀǰ����ʹ�õ�emote��emote����ϸ������
����:
1:�г���ָ������ʹ����� emote ʱ�����Լ�������ѶϢ;
2:�г���ָ������ʹ����� emote ʱ�������˿�����ѶϢ;
3:�г����Լ�ʹ����� emote ʱ���Լ�������ѶϢ;
4:�г����Լ�ʹ����� emote ʱ�������˿�����ѶϢ;
5:�г��Ա���ʹ����� emote ʱ���Լ�������ѶϢ;
6:�г��Ա���ʹ����� emote ʱ��ʹ�ö��󿴵���ѶϢ;
7:�г��Ա���ʹ����� emote 
ʱ�������Լ���ʹ�ö����⣬�����˿�����ѶϢ��
HELP
    );
    return 1;
}

