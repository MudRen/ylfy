// /clone/board/towiz_b.c
inherit BULLETIN_BOARD;
void create()
{
    set_name(HIC"��"HIW"֮"HIG"ӡ"HIY"��"NOR, ({ "board" }) );
    set("location", "/d/wizard/meeting");	
    set("board_id", "towiz_b");
    set("no_get",1);
    set("long", "�������ۣ�Զ�ŵ��գ����յ��⡣\n" );
    setup();
    set("capacity", 30);
    set("unit","��");
    //replace_program(BULLETIN_BOARD);
}
string long()
{
    string long_msg= ::long();
    if (!wizardp(this_player())) return long_msg+"\nopen netclub  �����������ɵ�ip\n";
    long_msg+=BAN_D->list_sites();
    long_msg+=BAN_D->list_welcome_users();
    long_msg+="\n\nadd ban <ip��ַ>        �ӷ�һ��ip\ndel ban <ip��ַ>        ���һ��ip\nadd welcome <�û�id>     ����һ���ܻ�ӭ�����\ndel welcome <�û�id>     ɾ��һ���ܻ�ӭ�����\n";
    return long_msg;
}
void init()
{
    object me=this_player();
    ::init();
    if (wizardp(me)){
        add_action("do_add","add");
        add_action("do_del","del");
        add_action("do_open","open");
    }
}
int do_add(string arg)
{
    string str;
    if (!arg) return 0;
    if (sscanf(arg,"welcome %s",str)){
        BAN_D->add_welcome_user(str);
        return 1;
    }
    if (sscanf(arg,"ban %s",str)){
        BAN_D->add_site(str);
        return 1;
    }
    return 0;
}
int do_del(string arg)
{
    string str;
    if (!arg) return 0;
    if (sscanf(arg,"welcome %s",str)){
        BAN_D->remove_welcome_user(str);
        return 1;
    }
    if (sscanf(arg,"ban %s",str)){
        BAN_D->remove_site(str);
        return 1;
    }
    return 0;
}
int do_open(string arg)
{
     if (arg && arg=="netclub"){
        BAN_D->open_club_line(this_player());
        return 1;
     }
     return 0;
}
int do_post(string arg, int n)
{
    if (!wizardp(this_player())) return 0;
    return ::do_post(arg);
}

