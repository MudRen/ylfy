/*      version 1.0
        author: ken@chinesemud.net
                        fuyo@szonline.net
        version 2.0
        author: ken@chinesemud.net
                        (crba)hui@vec425pc4.me.csulb.edu

        [1997-12-6] all messages board by cbra 
        [97-12-8] modify to chinese and name modify to (Board Manager) by ken
        [97-12-8] modify by cbra at 
        [97-12-10] modify for autoload boards from BOARD_PATH by ken
        [97-12-14] modify for display message for load board by ken
        [98-2-17] modify for transfer post to document by ken
        [98-9-2] updated tansfer post by ken.
*/

#include <ansi.h>

inherit COMBINED_ITEM;

string short();
string long();
int do_discard(string arg);
int do_display();
int do_post(string arg);
int do_read(string arg);
int do_select(string arg);
int do_help(string arg);
// add for transfer post to document
int do_write(string arg);
// for autoload
void set_amount(int v);
int query_autoload();
// for load board from BOARD_PATH
int load_board();

#define BOARD_PATH "/d/board/"
// add by fuyo for save a post to save_b.c
#define BACKUP_B "save_b.c"
#undef BACKUP_B

private mapping board_db =([]);

void create()
{
        set_name("���԰������", ({ "board manager","bmgr", "bm" }) );
        set("unit","��");
        set("base_unit","��");
        set_amount(1);
        seteuid(ROOT_UID);
}

void init()
{
        if( wizardp(this_player()) ) {
                add_action("do_write","write");
                add_action("do_post", "post");
                add_action("do_read", "read");
                add_action("do_discard", "discard");
                add_action("do_select", "select");
                add_action("do_help","help");
                add_action("do_display","index");
        }
}

int do_help(string arg)
{
        if(!arg)        return 0;
        if( arg != "bm" && arg !="board manager" && arg != "bmgr")
                return 0;
        load_board();
        arg = sprintf("%d",sizeof(board_db));
        write("�� ���԰������ʹ�÷���\n\n"
                "\tѡ��һ�����԰壺select <��ţ�1-"+arg+">��\n"
                "\t�ڵ�ǰѡ�����԰巢�����£�post <����>��\n"
                "\t�ڵ�ǰѡ�����԰��ȡ���£�read <���>��\n"
                "\t�ڵ�ǰѡ�����԰�ɾ�����£�discard <���>��\n"
                "\t��ʾ��ǰѡ�����԰��������±��⣺index��\n"
                "\t����ǰѡ�����԰�ָ���������ñ�����write��\n"
                "\t��ذ����� help board��\n\n"
                "97-12-11 by cbra & ken��\n");
        return 1;
}

string short()
{
        return ::name(1) + "(" + capitalize(::query("id")) + ")";
}

string long()
{       
        int select,i=0;
        string msg,title1,title2;

        load_board();
        select = this_user()->query_temp("bm");
        msg=RED" �� "NOR"���԰��������ʹ�÷������ help bm��\n\n";
        for(i=0; i<sizeof(board_db); i++) {
                sscanf((BOARD_PATH+board_db[i])->short(),"%s %s",title1,title2);
                        msg += sprintf("\t%s %2d. %-32s %s\n",
                        (select == i+1) ? RED"��"NOR:"  ",
                        i+1,title1,title2);
        }
        this_user()->start_more(msg);
        msg = sprintf("\nĿǰ��"MUD_NAME"������ %d �����԰塣\n",sizeof(board_db) );
        return msg;
}

int do_display()
{
        string msg;
        int select;

        load_board();
        select = this_user()->query_temp("bm");
        if( select < 1 ) {
                msg=RED" �� "NOR"���԰��������ʹ�÷������ help bm��\n";
                write(msg);
                return 1;
        }
        msg = (BOARD_PATH+board_db[select-1])->long();
        this_user()->start_more(msg);
        return 1;
}

int do_select(string arg)
{
        string msg;
        int select;

        load_board();

        if (!arg)       {
                if( this_user()->query_temp("bm") )
                        select = this_user()->query_temp("bm");
                else    select = 0;
        }
        else {
                if( sscanf(arg,"%d",select) !=1)
                        select = 0;
                if( select > sizeof(board_db) )
                        select = 0;
        }
        if( select < 1 && arg && upper_case(arg) == "NEXT" ) {
                select = this_user()->query_temp("bm") + 1;
                if( select > sizeof(board_db) )
                        select = 0;
        }
        if( select < 1 ) {
                msg = sprintf("���� select <1-%d>|next ѡ����ȷ�����԰��š�\n",sizeof(board_db));
                return notify_fail(msg);
        }
        this_user()->set_temp("bm", select);
        msg = sprintf("��Ŀǰѡ����ǣ�%d. %s", select,(BOARD_PATH+board_db[select-1])->short());
        this_user()->start_more(msg);
        return 1;
}

int do_post(string arg)
{
        int select;

        select = this_user()->query_temp("bm");
        if( select < 1 ) {
                write(RED" �� "NOR"���԰��������ʹ�÷������ help bm��\n");
                return 1;
        }
        select --;
        write("��Ŀǰѡ����ǣ�"+(BOARD_PATH+board_db[select])->name());

#ifdef BACKUP_B
        if(strcmp(board_db[select],BACKUP_B)==0)
        {
                write(RED"\n\n�Բ��𣬱���Ϊ�������������ֹ post��\n\n"NOR);
                return 1;
        }
#endif
        write("\n���Ա���Ϊ��"+arg+"\n");
        return (BOARD_PATH+board_db[select])->do_post(arg);
}

int do_read(string arg)
{
        int select;
        string name;

        select = this_user()->query_temp("bm");
        if( select < 1 ) {
                write(RED" �� "NOR"���԰��������ʹ�÷������ help bm��\n");
                return 1;
        }
        select --;
        name = (BOARD_PATH+board_db[select])->short();
        if( arg == "new" && name[sizeof(name)-6..sizeof(name)-3] != "δ��" )
                while( select<sizeof(board_db) ) {
                        name = (BOARD_PATH+board_db[select])->short();
                        if( name[sizeof(name)-6..sizeof(name)-3] == "δ��" ) {
                                break;
                        }
                        else
                                select ++;
                }
        if( select > sizeof(board_db) -1 ) {
                select = sizeof(board_db);
                select --;
        }
        this_user()->set_temp("bm", select+1);
        write("��Ŀǰѡ����ǣ�"+name+"\n");
        return (BOARD_PATH+board_db[select])->do_read(arg);
}

int do_discard(string arg)
{
        int select;
        select = this_user()->query_temp("bm");
        if( select < 1 ) {
                write(RED" �� "NOR"���԰��������ʹ�÷������ help bm��\n");
                return 1;
        }
        select --;

#ifdef BACKUP_B
        if(strcmp(board_db[select],BACKUP_B)==0) {
                if( wiz_level(this_player()) < wiz_level("(adept)") )           {
                        write(RED"\n�Բ��𣬱���Ϊ�������������ֹ discard��\n\n"NOR);
                        return 1;
                }
        }
#endif
        write((BOARD_PATH+board_db[select])->name());
        return (BOARD_PATH+board_db[select])->do_discard(arg);
}

// for autoload

void set_amount(int v)
{
        if( v < 0 ) error("combine:set_amount less than 1.\n");
        if ( v==0 ) call_out("destruct_me", 1);
        else { 
                if (v>1) write(RED"�������ϵ�"+this_object()->name()+"�����ˡ�\n"NOR);
                amount = 1;
        }
}

int query_autoload() { 
        return 1;
}

// load boards
int load_board() {
        int i,jj;
        mixed *names;

        names = get_dir(BOARD_PATH, -1);
        if( !sizeof(names)) {
                if (file_size(BOARD_PATH) == -2)
                        return notify_fail(MUD_NAME+"����Ŀ¼�����κ����԰档\n");
                else
                        return notify_fail("��������԰�Ŀ¼�����ڡ�\n");
        }
        
        jj=0;
        for( i=0; i<sizeof(names);i++) {
                if(strsrch(names[i][0],".c")==-1) continue;
                board_db[jj]=sprintf("%s",names[i][0]);
                if( !find_object(BOARD_PATH+board_db[jj]) ) {
                        write("����"BOLD);
                        load_object(BOARD_PATH+board_db[jj]);
                        write((BOARD_PATH+board_db[jj])->name());
                        write(NOR"("+board_db[jj]+")");
                        write("�ɹ���\n");
                }
                jj++;
        }
        return 1;
}

int do_write(string arg)
{
        int select,num;
        string syntax,body;
        object wiz,source;
        mapping post,notes;

        wiz = this_player();

// add by ken for check Backup of board at 98-11-20
#ifdef BACKUP_B
        syntax="ָ���ʽ��write ���Ա�š�\n";
#else
        write("The BACKUP_B not define(������δ����), check program of this object.\n");
        return 1;
#endif
        select = this_user()->query_temp("bm");
        if( select < 1 ) {
                write(RED" �� "NOR"���԰��������ʹ�÷������ help bm��\n");
                return 1;
        }

        if(!arg) return notify_fail(syntax);

        if( !arg )
                return notify_fail(syntax);

        select --;

#ifdef BACKUP_B
        if(strcmp(board_db[select],BACKUP_B)==0)
        {
                write(RED"\n�����Ѿ��Ǿ������������ظ��ռ���\n\n"NOR);
                return 1;
        }
#endif
        source = load_object(BOARD_PATH+board_db[select]);

        if( !sscanf(arg, "%d", num) )
                return notify_fail("��Ҫ������һ�����ԣ�\n");

        num --;

        if( num < 0 || num > sizeof(source->query("notes"))-1 )
                return notify_fail("û���������ԡ�\n");

        notes = source->query("notes")[num];
        post = ([]);
        post["title"]   = notes["title"];
        post["author"]  = notes["author"];
        post["time"]    = notes["time"];
        body = notes["msg"];
        body += sprintf(
"\n������ƪ��������%s(%s)ѡ��%s��",
        wiz->name(),
        wiz->query("id"),
        source->name()
        );
        
#ifdef BACKUP_B
        if( objectp(transfer=find_object(BOARD_PATH+BACKUP_B)) )
        {
                transfer->done_post(wiz,post,body);
                write(BOLD"\n�����µ������浽"+(BOARD_PATH+BACKUP_B)->name()+"��ϡ�\n\n"NOR);
        }
#endif
        write("��Ŀǰѡ����ǣ�"+(BOARD_PATH+board_db[select])->name()+"\n");
        return 1;
}


