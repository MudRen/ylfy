// ----/cmds/usr/allowip.c ----
// allowip.c

#include <ansi.h> 
inherit F_CLEAN_UP;
 
int help();
 
varargs void allow_ip_list(string *allow_ip,string name)
{
    int i;
    if (!name)
        name="��";
    if (allow_ip && sizeof(allow_ip)){
        write("\n"+name+"���趨�ĵ�¼��ַ��Χ�У�\n");
        for (i=0;i<sizeof(allow_ip);i++)
                    printf("\t%s\n", allow_ip[i]);
    }else{
        write(YEL+"���棺"+name+"Ŀǰû���趨�κε�¼��ַ��"+name+"���ʺſ��Դ��κεط����ߣ�\n"+NOR);
     if (name=="��")
        help();
    }
}

int vaild_enter(string line,string *allow_ip)
{
    int i;
    string *ip;
    
    if (!sizeof(allow_ip) || !line)  return 1;
    ip=({ line });
    for (i = 0; i < sizeof(allow_ip); i++)
        if (sizeof(regexp(ip, allow_ip[i])) == 1)
            return 1;
    return 0;
}

int main(object me, string arg)
{
    string *allow_ip,line;
    int i;
    string tmp1,tmp2,tmp3,tmp4,term="-s";
    object link_ob;
    
    if (!me || me!=this_player(1))  return 0;
    
    link_ob=me->query_temp("link_ob");
 
    seteuid(ROOT_UID);
 
    allow_ip=link_ob->query("allow_ip");
    if( !arg || arg=="" ) {
        allow_ip_list(allow_ip);
        return 1;
    }
    if (wizardp(me)){
        if (sscanf(arg,"%s %s",term,tmp1)==2){
            link_ob=FINGER_D->acquire_login_ob(tmp1);
            if (link_ob){
                switch(term){
                    case "-p" :
                        allow_ip_list(link_ob->query("allow_ip"),link_ob->query("name"));
                        return 1;
                    case "-d" :
                        link_ob->delete("allow_ip");
                        write(link_ob->query("name")+"�ĵ�¼��ַ�����ѱ�ɾ����\n");
                        link_ob->save();
                        return 1;
                }
            }
        }
    }

    sscanf(arg, "%s %s", term, arg);
    switch(term){
        case "-?":
             if (!vaild_enter(arg,allow_ip)){
                write(arg+" ���������趨�ĵ�¼��ַ�ڡ�\n");
             }else{
                write(arg+" ����������¼��\n");
             }
                return 1;
        case "-d":
            if (!allow_ip || !sizeof(allow_ip))
                return notify_fail(YEL+"\n���棺��Ŀǰû���趨�κε�¼��ַ������ʺſ��Դ��κεط����ߣ�\n"+NOR);
            if (member_array(arg,allow_ip)==-1)    return notify_fail("�㲢û���趨"+arg+"\n");
            allow_ip -= ({ arg });
                line=query_ip_number(me);
            if (!vaild_enter(line,allow_ip)){
                write("���棺��Ŀǰ��IP��ַ "+line+" ���������趨�ĵ�¼��ַ�ڡ�\n���������ã�\n");
                return 1;
            }
            break;
        case "-s" :
            allow_ip=explode(arg,"|");
            allow_ip -= ({""});
            write("�趨��¼��ַ��");
            for (i=0;i<sizeof(allow_ip);i++){
                if (sscanf(allow_ip[i],"%s.%s.%s.%s",tmp1,tmp2,tmp3,tmp4)==4){
                    if (tmp1=="*")
                        allow_ip -= ({ allow_ip[i] });
                    else
                        write(" "+allow_ip[i]);
              }else  return help();
            }
            line=query_ip_number(me);
            if (!vaild_enter(line,allow_ip)){
                   write(YEL+"\n���棺��Ŀǰ��IP��ַ "+line+" ���������趨�ĵ�¼��ַ�ڡ�\n���������ã�\n"+NOR);
                    return 1;
            }else{
                break;
            }
            return 1;
       default:
            return help();
    }
    write("\nOK!\n");
	
	if ( link_ob=me->query_temp("link_ob") )
		link_ob->set("allow_ip",allow_ip);
	
	link_ob->save();
    return 1;
}
 
int help()
{
        write(@TEXT
ָ���ʽ��allowip [-?] [-d] [IP��ַ��Χ]
 
�趨�Լ��ĵ�¼IP��ַ����
      allowip 202.96.138.138

Ҳ���趨һ��IP��ַ��Χ����
      allowip 202.96.138.*

Ҳ��ͬʱ�趨�����ַ��Χ(���������)���м���"|"��������
      allowip 202.96.138.138|202.98.100.*|172.21.*.*

��ʹ����֪��������룬Ҳ���ܴ�����ip��ַ��¼��

��������:

-?  : ��֤ĳ��IP��ַ�Ƿ��ܵ�¼
-d  : ɾ��ĳ����¼��ַ

TEXT
        );
        return 1;
}
