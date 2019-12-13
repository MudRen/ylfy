
#include <ansi.h>
inherit F_CLEAN_UP;
string *mission; 
string remove_ansi(string str)
{
        int i;
        string *color = ({ BLK, RED, GRN, YEL, BLU, MAG, CYN, WHT,
                        HIR, HIG, HIY, HIB, HIM, HIC, HIW,
                        HBRED, HBGRN, HBYEL, HBBLU, HBMAG, HBCYN, HBWHT,
                        BBLK, BRED, BYEL, BBLU, BMAG, BCYN,
                        NOR, BOLD });
        if( !str || !stringp(str) ) return 0;
        i = sizeof(color);
        while( i-- ) {
                str = replace_string(str, color[i], "");
        }
        return str;
}
int level(mixed, mixed);
string get_mission( string );
int main(object me, string arg)
{
        int i;
        string *list, hood="", str, msg, scr, att, showtime;
      int bos_n, adm_n, arc_n, ang_n, wiz_n, app_n, gen_n, imm_n, j, k, time, day, hour, min;
        object login;
       mission = explode(read_file("/adm/etc/renwu"), "\n");
        list = sort_array(SECURITY_D->query_wizlist(), (: level :));
        for(i=0; i<sizeof(list); i++) {
                switch (wizhood(list[i])) { 
                        case "(boss)"           :bos_n++;break;
                        case "(admin)"          :adm_n++;break;
                        case "(arch)"           :arc_n++;break;
                        case "(angel)"          :ang_n++;break;
                        case "(wizard)"         :wiz_n++;break;
                        case "(apprentice)"     :app_n++;break;
                        case "(genie)"          :gen_n++;break;
                        case "(immortal)"       :imm_n++;break;
                }
        }
        str = HIR"��"+HIY+""+MUD_NAME+""HIR"��"HIG"��ʦ�б�\n"NOR;
        str +=YEL"���������������ש������������ש����ש����������ש�����������������\n"NOR;
        str +=YEL"��  "HIW"��ʦ�ȼ�"NOR+YEL"  ��   "HIW"��ʦID  "NOR+YEL" ��"HIW"״̬"NOR+YEL"�� "HIW"Ŀǰ����"NOR+YEL" ��"HIW"  �� �� ʱ ��  "NOR+YEL" ��\n"NOR;
        str +=YEL"�ǩ������������ߩ������������ߩ����ߩ����������ߩ�����������������\n"NOR;
        for(i=0; i<sizeof(list); i++) {
                if (hood != wizhood(list[i])) {
                        hood = wizhood(list[i]);
                        switch (hood) { 
                                case "(boss)"           :msg =HIY"     ������ "NOR;k=bos_n;break;
                                case "(admin)"          :msg =HIW"     ��  �� "NOR;k=adm_n;break;
                                case "(arch)"           :msg =HIM"     ��  �� "NOR;k=arc_n;break;
                                case "(angel)"          :msg =HIM"     ��  �� "NOR;k=ang_n;break;
                                case "(wizard)"         :msg =HIY"     ����ʦ "NOR;k=wiz_n;break;
                                case "(apprentice)"     :msg =HIC"     ��  ʹ "NOR;k=app_n;break;
                                case "(genie)"          :msg =HIM"     ɢ  �� "NOR;k=gen_n;break;
                                case "(immortal)"       :msg =HIB"     ��  �� "NOR;k=imm_n;break;
                        }
                        j=1;
                } else {
                        msg="";
                        j++;
                }
                if ( k == 1) scr=HIR"������"NOR;
                else scr=HIR"���ש�"NOR;

                if ( k!=j && k!=1 && j!=1 ) scr=HIR"  �ǩ�"NOR;
                if ( k==j && k!=1 && j!=1 )     scr=HIR"  ����"NOR;
                   login = new(LOGIN_OB);
                if(objectp(login = find_player(list[i])) && me->visible(login)) {
                        att=HIG"����"NOR;
                        //time = time() - (stat(sprintf("%slogin%s%s%s", DATA_DIR,"/"+list[i][0..0]+"/",list[i],__SAVE_EXTENSION__),-1)[1]);
						time = 0;
                } else {
                        att=HIR"����";
                        //time = time() - (stat(sprintf("%slogin%s%s%s", DATA_DIR,"/"+list[i][0..0]+"/",list[i],__SAVE_EXTENSION__),-1)[1]);
						time = 0;
                }
                
                time /= 60;
                min = time%60;
                time /= 60;
                hour = time%24;
                time /= 24;
                day = time;

                showtime=sprintf("%s%s%s",day?sprintf("%d��",day):"",
                                        hour?sprintf("%dСʱ",hour):"",
                                        min?sprintf("%d����",min):"С��һ����");

                
                        str += sprintf("%-12s%s "HIY"%-11s"NOR"%s   %s"HIR"   %s",msg, scr, list[i], att, get_mission( list[i] ),showtime);
                       str += "\n"; 
                
                
        }
        str +=YEL"��������������������������������������������������"HIR"Ϧ"HIW"��"HIR"��"YEL"����������\n"NOR;
        me->start_more(str);
        return 1;
}
int level(mixed ob1, mixed ob2)
{
        if (wiz_level(ob1) != wiz_level(ob2))
                return wiz_level(ob2) - wiz_level(ob1);
        return ob1 < ob2?-1:1;
}
string get_mission( string wiz)
{
int i;
string wname,wmin;
for(i=0; i<sizeof(mission); i++) {
if( mission[i][0]=='#' || sscanf(mission[i], "%s %s",wname, wmin)!=2 ) continue;
if(wname==wiz) return wmin;
}
return HIW"����δ��"NOR;       	
}
int help(object me)
{
write(@HELP
ָ���ʽ : wizlist

��; : �г�Ŀǰ���е���ʦ��������ʦ��ǰ����

HELP
     );
     return 1;
}


