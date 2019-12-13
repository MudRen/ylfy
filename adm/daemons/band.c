// ban.c

#define BANNED_SITES "/adm/etc/banned_sites"
#define WELCOME "/adm/etc/welcome_sites"
#define BANNED_IDS   "/adm/etc/banned_ids"
#define BANNED_NAMES "/adm/etc/banned_names"

void load_sites();
void load_welcome();
void load_banned_names();
void load_banned_ids();

void add_site(string pattern);       // banһ������ӭ��ip
void remove_site(string pattern);    // ���һ��ip
int is_banned(string site);          // �ж��Ƿ�һ��ban��ip(logind.c����)
string list_sites();                   // ��ban��ip�б�
//  welcome���û�����ban��Ӱ��,���ҿ��Կ���������϶��ip
string list_welcome_users();           // welcome users�б�
int is_welcome(string user_id);      // �ж��Ƿ�һ��welcome���û�(logind.c����)
void add_welcome_user(string user_id); // ����һ��welcome �û�(id)
void remove_welcome_user(string user_id); // ɾ��һ��welcome �û�(id)
void open_club_line(object user);    // ��welcome�û��Լ������ɵ�ַ
int is_netclub(string netline);      // �ж��Ƿ�һ�������ߵ��û�(logind.c����)
void remove_netclub(string netline);  // ��ȥһ��������

string *Sites;
string *Netclubs;
string *Welcomes;
string *Banned_IDs;              //  ban id ��
string *Banned_Names;            //  ban ��������

void create()
{
    seteuid(getuid());
    Netclubs = ({"61.128.193.47",});
    load_sites();
    load_welcome();
}
string *query_sites() { return Sites; }
string *query_welcomes() { return Welcomes; }
string *query_banned_ids() { return Banned_IDs; }
string *query_banned_names() { return Banned_Names; }


void load_banned_ids()
{
    string *tmp, file;
    int loop;
    Banned_IDs = ({});
    
    // reads in the list of the sites
    file = read_file(BANNED_IDS);
    if (!file) return;
    
    tmp = explode(file, "\n");
    for(loop=0; loop<sizeof(tmp); loop++)
            if(tmp[loop][0] == '#' || tmp[loop][0] == '\n' || tmp[loop] == "")
                continue;
            else Banned_IDs += ({ tmp[loop] });
}

void load_banned_names()
{
    string *tmp, file;
    int loop;
    Banned_Names = ({});
    
    // reads in the list of the sites
    file = read_file(BANNED_NAMES);
    if (!file) return;
    
    tmp = explode(file, "\n");
    for(loop=0; loop<sizeof(tmp); loop++)
            if(tmp[loop][0] == '#' || tmp[loop][0] == '\n' || tmp[loop] == "")
                continue;
            else Banned_Names += ({ tmp[loop] });
}

void load_sites()
{
    string *tmp, file;
    int loop;
    Sites = ({});
    
    // reads in the list of the banned sites
    file = read_file(BANNED_SITES);
    if (!file) return;
    
    tmp = explode(file, "\n");
    for(loop=0; loop<sizeof(tmp); loop++)
            if(tmp[loop][0] == '#' || tmp[loop][0] == '\n' || tmp[loop] == "")
                continue;
            else Sites += ({ tmp[loop] });
}

void load_welcome()
{
    string *tmp, file;
    int loop;
    Welcomes = ({});
    // reads in the list of the banned sites
    file = read_file(WELCOME);
    if (!file) return;
    
    tmp = explode(file, "\n");
    for(loop=0; loop<sizeof(tmp); loop++)
            if(tmp[loop][0] == '#' || tmp[loop][0] == '\n' || tmp[loop] == "")
                continue;
            else Welcomes += ({ tmp[loop] });
}
int is_banned(string site)
{
    string *line = ({site});
    string tmp1,tmp2,tmp3,tmp4;
    int i;
    if (!site)  return 1;

    if (sscanf(site,"%s.%s.%s.%s",tmp1,tmp2,tmp3,tmp4)!=4)
        return 1;
    // ��ֹʹ������ip �� route
    //if (tmp4=="0" || tmp4=="255") ����ĳЩ����ᵼ��һЩ����ϲ�����
	if (tmp4 == "0")
        return 1;
    for (i = 0; i < sizeof(Sites); i++)
       if (sizeof(regexp(line, Sites[i])) == 1)
            return 1;
        return 0;
}  
void add_site(string site)
{ 
 string tmp1,tmp2,tmp3,tmp4;
    int i;
   
    if (!site)  return;
   // ��ֹ��ַ
    if (sscanf(site,"%s.%s.%s.%s",tmp1,tmp2,tmp3,tmp4)==4){
      if (is_banned(site)){
         write (RED+site+"�Ѿ�����ֹ!\n"+NOR);
         return;
      }
      if (tmp1=="*"){
         write (RED+site+"��IP��Χ̫����!\n"+NOR);
         return;
      }
      Sites += ({site});
      write_file(BANNED_SITES, Sites[sizeof(Sites)-1] + "\n", 0);
  write (RED "\n��ֹ��ַ"+site+"...OK!\n" NOR);
      Netclubs -= ({ site });
      return;
    }
    // ��ֹʹ��������
    if (is_chinese(site)){
       if( member_array(site, Banned_Names)!=-1 ) {
               write (RED+site+"�Ѿ�����ֹ!\n"+NOR);
               return;
        }
        for (i=0;i<sizeof(Banned_Names);i++)
            if ( strsrch(site, Banned_Names[i])!=-1){
               write (RED+site+"�Ѿ�����ֹ!\n"+NOR);
               return;
            }
      Banned_Names+= ({site});
      write_file(BANNED_NAMES, Banned_Names[sizeof(Banned_Names)-1] + "\n", 0);
      write (RED "\n��ֹʹ��������"+site+"...OK!\n" NOR);
      return;
    }
    i=strlen(site);
    if( (strlen(site) < 3) || (strlen(site) > 12 ) ) {
       write("Ӣ�����ֱ����� 3 �� 12 ��Ӣ����ĸ��\n");
     return;
    }
    while(i--)
       if( site[i]<'a' || site[i]>'z' ) {
           write("ֻ����Ӣ����ĸ��\n");
           return;
       }
   if( member_array(site, Banned_IDs)!=-1 ) {
           write(site+"���б����Ѿ����ڡ�\n");
           return;
   }

    Banned_IDs += ({ site });
    write_file(BANNED_IDS, Banned_IDs[sizeof(Banned_IDs)-1] + "\n", 0);
    write (BOLD "\n����"+HIY+site+HIW+"���б�...OK!\n" NOR);
}


void remove_site(string site)
{
    string tmp1,tmp2,tmp3,tmp4;
    int i;
    string *line = ({site});
   
  if (!site)  return;
    // �����ֹ��ַ
    if (sscanf(site,"%s.%s.%s.%s",tmp1,tmp2,tmp3,tmp4)==4){
        if (!is_banned(site)){
            write ("\n�����ַ��δ����ֹ!\n");
            return;
        }
        for (i = 0; i < sizeof(Sites); i++)
            if (sizeof(regexp(line, Sites[i])) == 1)
                Sites -= ({ Sites[i] });
            write_file(BANNED_SITES, implode(Sites, "\n")+"\n", 1);
        write (BOLD "\n�����ַ"+site+"...OK!\n" NOR);
        return;
    }
    // �����ֹʹ�õ�������
    if (is_chinese(site)){
       if( member_array(site, Banned_Names)==-1 ) {
                write (RED+site+"û����ֹʹ��!\n"+NOR);
       }else{
                Banned_Names-= ({site});
                write_file(BANNED_NAMES, implode(Banned_Names,"\n")+"\n", 1);
                write (RED "\n���������"+site+"...OK!\n" NOR);
                return;
  }
       for (i=0;i<sizeof(Banned_Names);i++)
            if ( strsrch(site, Banned_Names[i])!=-1){
                Banned_Names -= ({site});
                write_file(BANNED_NAMES, implode(Banned_Names,"\n")+"\n", 1);
                write (RED "\n���������"+site+"...OK!\n" NOR);
                return;
            }
        write (HIY+site+HIW+"û����ֹ!\n" NOR);
        return;
    }
    i=strlen(site);
    if( (strlen(site) < 3) || (strlen(site) > 12 ) ) {
       write("Ӣ�����ֱ����� 3 �� 12 ��Ӣ����ĸ��\n");
       return;
    }
    while(i--)
       if( site[i]<'a' || site[i]>'z' ) {
           write("ֻ����Ӣ����ĸ��\n");
           return;
       }
   if( member_array(site, Banned_IDs)!=-1 ) {
        Banned_IDs -= ({ site });
  write_file(BANNED_IDS, implode(Banned_IDs,"\n") + "\n", 1);
        write (BOLD "\n���ʹ��Ӣ����"+HIY+site+HIW+"������!\n" NOR);
        return;
   }
    write (HIY+site+HIW+"û����ֹ!\n" NOR);
}




int is_welcome(string user_id)
{
    if (member_array(user_id,Welcomes)==-1)  return 0;
    return 1;
}

void add_welcome_user(string user_id)
{
    if (is_welcome(user_id)){
       write("���id�Ѿ�������welcome player!\n");
       return;
    }
    Welcomes += ({ user_id });
    write_file(WELCOME, Welcomes[sizeof(Welcomes)-1] + "\n", 0);
    write (BOLD "\n����welcome user "+HIY+user_id+HIW+"...OK!\n" NOR);
    write(list_welcome_users());
}

void remove_welcome_user(string user_id)
{
    if (!is_welcome(user_id)){
       write("���id��δ������welcome player!\n");
       return;
    }
    Welcomes -= ({ user_id });
    write_file(WELCOME, implode(Welcomes,"\n")+"\n", 1);
    write (BOLD "\nɾ��welcome user "+HIY+user_id+HIW+"...OK!\n" NOR);
    write(list_welcome_users());
}

string list_welcome_users()
{
    if (!sizeof(Welcomes))
        return (BOLD "���ڻ�û��Welcome user.\n" NOR);
    return sprintf(HIY MUD_NAME+"��Welcome users����:\n"+HIC+"  %s\n" NOR,implode(Welcomes, "\n  "));
}

void list_netclubs()
{
    if (!sizeof(Netclubs)){
        write(BOLD "����û�п��ŵ����ɵ�ַ!\n" NOR);
        return;
    }
    printf(HIY "\n�����������ͬʱ����"+MUD_NAME+"��ip��ַ����:\n"+HIC+"  %s\n" NOR,implode(Netclubs, "\n  "));
}

int is_netclub(string netline)
{
    int i;
    string *line = ({netline});
    
    for (i = 0; i < sizeof(Netclubs); i++)
        if (sizeof(regexp(line, Netclubs[i])) == 1)
            return 1;
    return 0;
}

void remove_netclub(string netline)
{
    int i;
    string *line = ({netline});
    
    for (i = 0; i < sizeof(Netclubs); i++)
        if (sizeof(regexp(line, Netclubs[i])) == 1){
            Netclubs -= ({ Netclubs[i] });
            write (HIR "\nɾ�����ɵ�ַ"+netline+"...OK!\n" NOR);
            return;
        }
    write ("\n�����ַ������������!\n");
}

void open_club_line(object user)
{
    int i;
    string netline;
    string *line;
    if (!user) user=this_player();
    netline=query_ip_number(user);
    line = ({netline});
    if (!wizardp(user) && !is_welcome(user->query("id"))){
       write("��δ����welcome player,������ʦ����!\n");
       write("\n���뷽ʽ:ͨ��mailboxд�Ÿ�arch���ϼ������ʦ,ͨ����\n��ʦ�����֪ͨ��,�Ժ������id��������������߼���,\n��ע�ⶽ�����������ɵ����������Ϸ����лл������\n\n");
       return;
    }
    for (i = 0; i < sizeof(Netclubs); i++)
        if (sizeof(regexp(line, Netclubs[i])) == 1){
            write (HIY+netline+"�������Ѿ���!\n"+NOR);
            return;
    }
      if (netline=="202.96.190.124"){
            write (HIY+"��������ռ�õ�������!\n"+NOR);
             remove_welcome_user(user->query("id"));
            return;
     }
    Netclubs += ({ netline });
    write (BOLD "\n�����ɵ�ַ"+netline+"...OK!\n" NOR);
}
string list_sites()
{
    int flag;
    string msg=HIC "\n���ڱ���ֹ����"+MUD_NAME+"��ip��ַ����:\n"+HIR;
    if (!sizeof(Sites))
        return (BOLD "����û�б���ֹ�ĵ�ַ!\n" NOR);
    flag=0;
    foreach (string str in sort_array(Sites,1)){
        msg += str;
  flag++;
        if (flag % 8 )
            msg += "\t";
        else
            msg += "\n";
    }
    return msg+"\n"+NOR;
}

int vaild_allow_address(object ob)
{
   string *address;
   string *line;
   int i;
   
   if (!ob) return 0;
   address=ob->query("allow_ip");
   if (!sizeof(address)){
       ob->set_temp("no_allow_ip",1);
  //     write(HIY+"\n���棺��δ�趨�Լ��ĵ�¼��ַ��Χ������allowipָ�����á�\n"+NOR);
   if (is_welcome(ob->query("id")) && !is_netclub(query_ip_number(ob))){
      open_club_line(ob);    // ���Զ�������������
    log_file("login/open_netclub",sprintf("user %s open ip address %s limit in %s.\n",ob->query("id"),query_ip_number(ob),ctime(time())));
    }
      return 1;
   }
   line=({ query_ip_number(ob) });
   for (i = 0; i < sizeof(address); i++)
        if (sizeof(regexp(line, address[i])) == 1){
   if (is_welcome(ob->query("id")) && !is_netclub(query_ip_number(ob))){
      open_club_line(ob);    // ���Զ�������������
    log_file("login/open_netclub",sprintf("user %s open ip address %s limit in %s.\n",ob->query("id"),query_ip_number(ob),ctime(time())));
    }
            return 1;
    }
    write(HIR+"\n���ؾ��棺�㲻���Լ����趨�ĵ�¼��ַ��Χ�ڡ�\n"+NOR);
    log_file("login/ALLOW_IP",sprintf("%s(%s)��%s��ͼ��%s��¼��\n",ob->query("name"),ob->query("id"),ctime(time()),query_ip_number(ob)));
    return 0;
   
}