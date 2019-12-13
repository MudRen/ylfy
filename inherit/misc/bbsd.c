// bbsboard.c
// updated by Lonely 
/* ��ǿ�������԰棺BBS_BOARD �����ӣ��ظ����ܡ������ܡ�������
 * ��ֹ FLOOD ���ܣ��ο��� jjgod �����԰� */

#include <ansi.h>

inherit ITEM;
inherit F_SAVE;

#define BBS             "��ҳ��http://www.angelus.com\n��̳��http://www.angelus.com"

// ������� 100 ������
#define MAX_PLAN                1000

// �������ӳ����� MAX_PLAN��ɾ��ǰ 25 ��
#define DEL_TO          MAX_PLAN/4

// �Ƿ񱣴�����ԭ�������ӣ�������Ϊ0��������Ϊ 1
#define SAVE_ALL_OLD_PLAN 0

// �����Ҫ��ʾ����������ܳ��ܳ������룺
#define DEBUG           1

// ���ı��ⳤ��
#define MAX_TITLE_LEN   29

// ����������Ҫ������
#define NEED_EXP                10000
#define NEED_AGE                16

void setup()
{
        string loc;
        string my_long, my_id;

        if (stringp(loc = query("location")))
                move(loc);

        my_long = query("long");
        my_id = query("board_id");

        restore();
        set("icon","00023");
        set("no_get", 1);
        set("long", my_long);
        set("id", "board");
        set("location", loc);
}

void init()
{
        add_action("do_post", "post");
        add_action("do_re", "re");
        add_action("do_read", "read");
        add_action("delete_post", "delete");
        add_action("delete_post", "discard");
        add_action("do_from", "from");
        add_action("do_banzhu", "banzhu");
        add_action("do_search", "search");
}


string query_save_file()
{
        string id;

        if( !stringp(id = query("board_id")) ) return 0;
        return DATA_DIR + "board/" + id;
}

string short()
{
        mapping *notes;
        string banzhu;  
        int i, unread, last_read_time;
        
        if (! query("banzhu")) 
                banzhu = "[����������]";
        else 
                banzhu = "[����:" + this_object()->query("banzhu") + "]";

        notes = query("notes");
        if (! pointerp(notes) || ! sizeof(notes))
                return ::short() + " [ û���κ����� ]";

        if (this_player())
        {
                last_read_time = (int)this_player()->query("board_last_read/" +
                                 (string)query("board_id"));
                for (unread = 0, i = sizeof(notes) - 1; i >= 0; i--, unread ++)
                        if( notes[i]["time"] <= last_read_time ) break;
        }
        if (unread)
                return sprintf(HIC "%s" NOR " [ " HIW "%d" NOR " �����ӣ�" HIR "%d" NOR " ƪδ�� ]" + 
                               banzhu, ::short(), sizeof(notes), unread);
        else
                return sprintf("%s [ " HIW "%d" NOR " ������ ]" + banzhu, ::short(), sizeof(notes));
}

string long()
{
        mapping *notes;
        int i, last_time_read;
        string msg;

        notes = query("notes");
        if (! pointerp(notes) || ! sizeof(notes)) 
                return query("long");

        msg = query("long") + (query("banzhu") ? ("�����ĵİ����� " WHT + query("banzhu") + NOR "��\n") : "") +
              HIW "��ũ������⩤���������������������������������ߩ��ظ�������ʱ�䩤��������\n" NOR;
              
        last_time_read = this_player()->query("board_last_read/" + (string)query("board_id"));
        
        for (i = 0; i < sizeof(notes); i++) 
        {
                msg += sprintf("%s[" WHT "%2d" NOR "]" NOR "  %-29s %12s " WHT "%+3d" NOR "   [%s]\n",
                        (notes[i]["time"] > last_time_read ? HIY: ""),
                        i + 1, notes[i]["title"], notes[i]["author"], sizeof(notes[i]["re"]),
                        ctime(notes[i]["time"])[0..15] );
        }
        
        msg += HIW "��������������������������������������������������������������������������\n" NOR;
        return msg;
}


int do_from(string arg)
{
        mapping *notes;
        int i,j,last_time_read;
        string msg;

        notes = query("notes");
        msg = query("long");
        msg = msg + "���԰��ʹ�÷������ help board��\n";
        if (! pointerp(notes) || ! sizeof(notes)) return notify_fail(query("long"));

        last_time_read = this_player()->query("board_last_read/" + (string)query("board_id"));

        if (!arg)
                i = 0;
        else
                i = atoi(arg) - 1;

        if (i < 0) i = 0;

        j = 0;
        for (; i < sizeof(notes); i++)
        {
                msg += sprintf("%s[%2d]" NOR "  %-40s %12s (%s)\n",
                        (notes[i]["time"] > last_time_read ? HIY: ""),
                        i + 1, notes[i]["title"], notes[i]["author"], ctime(notes[i]["time"])[0..15]);
                j ++;
                if (j>1000) break;
        }

        this_player()->start_more(msg);
        return 1;
}

void done_post(object me, mapping note, int n, string text)
{
        int i, j;
        int pl;
        string sign;
        string pure;
        mapping *notes;
        string *lines;
        string msg = "";

        if (! stringp(text))
                return;

        if (strlen(text) > 64 * 1024)
        {
                tell_object(me, "�������̫���ˣ�����ȥһЩ����Ҫ�ġ�\n");
                return;
        }

        lines = explode(text, "\n");
        i = sizeof(lines);
        if (i > 2000)
        {
                tell_object(me, "�������̫���ˣ�����ȥһЩ����Ҫ�ġ�\n");
                return;
        }

        if (i > 20 && strlen(text) / i < 10)
        {
                tell_object(me, "��������ж̾�̫���ˣ������һ���Ա������Ķ���\n");
                return;
        }

        while (i--)
        {
                // scan all lines
                if (strlen(lines[i]) > 300)
                {
                        tell_object(me, "����������Щ��̫���ˣ�������Ա������Ķ���\n");
                        return;
                }
        }

        if (! n) n = me->query("env/default_sign");
        if (! stringp(sign = me->query(sprintf("env/sign%d", n))))
        {
                // auto select the first none null sign
                for (i = 1; i <= 4; i++)
                {
                        sign = me->query(sprintf("env/sign%d", i));
                        if (stringp(sign)) break;
                }
        }

        if (stringp(sign))
        {
                sign = replace_string(sign, "\\n", "\n");
                sign = trans_color(sign, 1);
                pure = filter_color(sign);
                if (strlen(pure) >= 1 &&
                    pure[strlen(pure) - 1] != '\n')
                        sign += "\n";

                pure = filter_color(text);
                pl = strlen(pure);
                if (pl >= 1 && pure[pl - 1] != '\n')
                        text += "\n\n" + sign;
                else
                if (pl >= 2 && pure[pl - 2] != '\n')
                        text += "\n" + sign;
                else
                        text += sign;
        } else
                text += HIG "\n" + BBS + NOR;
        
        text = color_filter(text) + NOR;
        note["msg"] = text;
        notes = query("notes");
        if (! pointerp(notes) || ! sizeof(notes))
                notes = ({ note });
        else
        {
                i = sizeof(notes) - 1;
                if (note["time"] <= notes[i]["time"])
                        note["time"] = notes[i]["time"] + 1;
                notes += ({ note });
        }

        set("notes", notes);
        tell_object(me, HIW "��������ɡ�\n" NOR);      
        save();

        if (sizeof(query("notes")) > MAX_PLAN) 
        {
                tell_object(me, HIR "������Ŀ����������������\n" NOR);
                for (i = 0; i < DEL_TO; i++) 
                {
                        // ԭ������
                        msg += sprintf("[" WHT "%2d" NOR "] %-31s %14s [" WHT "%10s" NOR "]\n"
                                       "����������������������������������������������������������������\n%s\n",
                        i + 1,
                        notes[i]["title"],
                        notes[i]["author"] + "-" + notes[i]["owner"],
                        ctime(notes[i]["time"])[0..9],
                        notes[i]["msg"],);
                        // �ظ�����
                        if (sizeof(notes[i]["re"])) 
                        {
                                for (j = 0; j < sizeof(notes[i]["re"]); j++) 
                                {
                                        msg += sprintf("\n[ " WHT "�ظ���" NOR "%2d] %-26s %12s [" WHT "%10s" NOR "]\n"
                                                       "����������������������������������������������������������������\n""%s\n",
                                        j + 1,
                                        notes[i]["re"][j]["title"],
                                        notes[i]["re"][j]["author"] + "-" +
                                        notes[i]["re"][j]["owner"],
                                        ctime(notes[i]["re"][j]["time"])[0..9],
                                        notes[i]["re"][j]["msg"],);
                                }
                        }
                }
#ifdef DEBUG
                me->start_more(msg);
#endif
                // 25 ��ǰ�����ӽ����浽 /data/board/�����board_id �ļ���
                write_file(DATA_DIR + "board/" + query("board_id") + ".old", msg, SAVE_ALL_OLD_PLAN);
                // ɾ��Ŀǰ board ��� 25 ��ǰ������
                notes = notes[DEL_TO..sizeof(notes)-1];
                set("notes", notes);
                save();
                tell_object(me, HIR "����������ϣ�ɾ�� " HIW + (DEL_TO + 1) + HIR " ����ǰ�����ӡ�\n" NOR);
        }
        return;
}

void done_re(object me, mapping report, int project, int n, string text)
{
        int i;
        int pl;
        string sign;
        string pure;        
        mapping *notes, *reports;
        string *lines;  

        if (! stringp(text))
                return;

        if (strlen(text) > 64 * 1024)
        {
                tell_object(me, "�������̫���ˣ�����ȥһЩ����Ҫ�ġ�\n");
                return;
        }

        lines = explode(text, "\n");
        i = sizeof(lines);
        if (i > 2000)
        {
                tell_object(me, "�������̫���ˣ�����ȥһЩ����Ҫ�ġ�\n");
                return;
        }

        if (i > 20 && strlen(text) / i < 10)
        {
                tell_object(me, "��������ж̾�̫���ˣ������һ���Ա������Ķ���\n");
                return;
        }

        while (i--)
        {
                // scan all lines
                if (strlen(lines[i]) > 300)
                {
                        tell_object(me, "����������Щ��̫���ˣ�������Ա������Ķ���\n");
                        return;
                }
        }

        if (! n) n = me->query("env/default_sign");
        if (! stringp(sign = me->query(sprintf("env/sign%d", n))))
        {
                // auto select the first none null sign
                for (i = 1; i <= 4; i++)
                {
                        sign = me->query(sprintf("env/sign%d", i));
                        if (stringp(sign)) break;
                }
        }

        if (stringp(sign))
        {
                sign = replace_string(sign, "\\n", "\n");
                sign = trans_color(sign, 1);
                pure = filter_color(sign);
                if (strlen(pure) >= 1 &&
                    pure[strlen(pure) - 1] != '\n')
                        sign += "\n";

                pure = filter_color(text);
                pl = strlen(pure);
                if (pl >= 1 && pure[pl - 1] != '\n')
                        text += "\n\n" + sign;
                else
                if (pl >= 2 && pure[pl - 2] != '\n')
                        text += "\n" + sign;
                else
                        text += sign;       
        } else
                text += HIG "\n" + BBS + NOR;
        
        text = color_filter(text) + NOR;
        report["msg"] = text;

        notes = query("notes");
        reports = notes[project]["re"];
        
        if (! arrayp(reports))  
                reports = ({ report });
        else 
                reports += ({ report });

        notes[project]["re"] = reports;
        notes[project]["time"] = time();

        set("notes", notes);
        tell_object(me, HIW "�ظ���ϡ�\n" NOR);

        save();
        return;
}

int do_post(string arg, int n)
{
        mapping note, fam;
        int noname_board;
        string poster_lvl, family;
        object me = this_player();
        
        poster_lvl = query("poster_level");
        
        if (! stringp(poster_lvl))
                poster_lvl = "(player)";

        // write("Board Restricted to " + poster_lvl + " and above.\n");

        if ((int)SECURITY_D->check_wiz_level(me, poster_lvl) < 0)
                return notify_fail("���岻�������Ͷ�塣\n");

        family = query("poster_family");
        fam = me->query("family");
        noname_board = query("noname_board");

        // write("Board Restricted to " + family + " players only.\n");

        if (stringp(family)
                && (int)SECURITY_D->check_wiz_level(me, "(immortal)") < 0 
                && (! mapp(fam) || fam["family_name"] != family))
                return notify_fail("�Ǳ��ɵ��Ӳ����򱾰���Ϳ��д��\n");

        if (query("avoid_flood")
                && me->query("combat_exp") < NEED_EXP
                && me->query("age") < NEED_AGE)
                return notify_fail("����ʱ��û��Ȩ�������﷢�����£���Ҫ " WHT +
                                   NEED_EXP + NOR " �㾭��ֵ���� " WHT + NEED_AGE + NOR " ������䡣\n");

        if (! arg) return notify_fail("��������ָ��һ�����⡣\n");
                                           
        if (sscanf(arg, "%s with %d", arg, n) != 2)
                n = 0;

        if (replace_string(arg, " ", "") == "")
                arg = "�ޱ���";
        /*        
        else
                arg = color_filter(arg) + NOR;         
        */
        if (strlen(arg) > MAX_TITLE_LEN)
                return notify_fail("�������̫���ˣ��뻻һ�����һ��ġ�\n");

        note = allocate_mapping(5);
        note["title"] = arg;
        if (noname_board)
        {
                note["owner"] = "NULL";
                note["author"] = "����";
        }
        else
        {
                note["owner"] = me->query("id");
                note["author"] = me->name(1);
        }
        note["time"] = time();
        me->edit((: done_post, me, note, n :));
        return 1;
}

int do_re(string arg, int n)
{
        int num, noname_board;
        string title;
        mapping note, *notes, fam;
        string poster_lvl, family;
        object me = this_player();
        
        poster_lvl = query("poster_level");
        
        if (! stringp(poster_lvl))
                poster_lvl = "(player)";

        // write("Board Restricted to " + poster_lvl + " and above.\n");

        if ((int)SECURITY_D->check_wiz_level(me, poster_lvl) < 0)

                return notify_fail("���岻�������Ͷ�塣\n");

        family = query("poster_family");
        fam = me->query("family");
        noname_board = query("noname_board");

        // write("Board Restricted to " + family + " players only.\n");

        if (stringp(family)
                && (int)SECURITY_D->check_wiz_level(me, "(immortal)") < 0 
                && (! mapp(fam) || fam["family_name"] != family))
                return notify_fail("�Ǳ��ɵ��Ӳ����򱾰���Ϳ��д��\n");

        if (query("avoid_flood")
                && me->query("combat_exp") < NEED_EXP
                && me->query("age") < NEED_AGE)
                return notify_fail("����ʱ��û��Ȩ�������﷢�����£���Ҫ " WHT +
                                   NEED_EXP + NOR " �㾭��ֵ���� " WHT + NEED_AGE + NOR " ������䡣\n");
                        
        if (! arg) return notify_fail("ָ���ʽ��re <���ӱ��>.<�ظ�����> with <ǩ����>\n");
        
        if (sscanf(arg, "%d.%s", num, title) < 1)
                return notify_fail("ָ���ʽ��re <���ӱ��>.<�ظ�����> with <ǩ����>\n");
                
        if (sscanf(arg, "%d.%s with %d", num, title, n) != 3 
                && sscanf(arg, "%d with %d", num, n) != 2)
                n = 0;                          

        notes = query("notes");
        if (! arrayp(notes) || num < 1 || num > sizeof(notes))
                return notify_fail("û��������ӡ�\n");

        if (strlen(title)>MAX_TITLE_LEN)
                return notify_fail("�������̫���ˣ��뻻һ�����һ��ġ�\n");

        if (! title) title = "Re: " + notes[num - 1]["title"];
        /*
        else
                title = color_filter(title) + NOR;     
        */

        note = allocate_mapping(5);
        note["title"] = title;
        if (noname_board)
        {
                note["owner"] = "NULL";
                note["author"] = "����";
        }
        else
        {
                note["owner"] = me->query("id");
                note["author"] = me->name(1);
        }
        note["time"] = time();
        me->edit((: done_re, me, note, num - 1, n :));
        return 1;
}

int do_read(string arg)
{
        int num, rep, last_read_time, i, last, arc, private_board;
        mapping *notes, fam;
        string myid, msg, file;
        string family;
        object me = this_player();

        last_read_time = me->query("board_last_read/" + query("board_id"));
        myid    = query("board_id");
        notes   = query("notes");
        arc = query("wizard_only");
        private_board = query("private_board");
        
        if (arc && ! wizardp(me))
                return notify_fail("��ʦ�ڲ��������ÿ��ӡ�\n");
        
        family = query("poster_family");
        fam = me->query("family");

        //write("Board Restricted to " + family + " players only.\n");

        if (stringp(family)
                && ! wizardp(me) 
                && (! mapp(fam) || fam["family_name"] != family))
                return notify_fail("�Ǳ��ɵ��Ӳ��ÿ��ӱ����ڲ�������\n");

        if (! pointerp(notes) || ! sizeof(notes))
                return notify_fail("������Ŀǰû���κ����ӡ�\n");

        if (! arg) return notify_fail("ָ���ʽ��read <���ӱ��>[.<�ظ����>]|new|next|old\n");

        // ��ʾ��ǰ���ݵľ�����
        if (arg == "old") 
        {
                file = DATA_DIR + "board/" + query("board_id") + ".old";
                if (file_size(file) <= 0) 
                        return notify_fail("�Բ���Ŀǰ����û�б���ľ�����\n");
                else
                {
                        if (private_board && ! wizardp(me))
                                return notify_fail("�Բ������ھ����漰��һЩ������˽���ʲ������Ķ���\n");
                                
                        msg = read_file(file);
                        me->start_more(msg);
                        return 1;
                }
        }
        // ��ʾδ��������
        if (arg == "new" || arg == "next") 
        {
                if (! intp(last_read_time) || undefinedp(last_read_time))
                        num = 1;
                else
                        for (num = 1; num <= sizeof(notes); num++)
                                if (notes[num-1]["time"] > last_read_time)
                                {
                                        if (private_board)
                                        {
                                                if (wizardp(me)) break;
                                                else
                                                if (! strcmp(me->query("id"), notes[num - 1]["owner"]))
                                                        break;
                                        } else
                                                break;
                                }

        } else 
        if (sscanf(arg, "%d.%d", num, rep) == 2) 
        {
                if (num < 1 || num > sizeof(notes)) 
                        return notify_fail("û��������ӡ�\n");
                else num--;

                if (! wizardp(me) && private_board && strcmp(me->query("id"), notes[num]["owner"]))
                        return notify_fail("������Ӳ��������ģ������㲻���Ķ���\n"); 
                         
                if (rep < 1 || rep > sizeof(notes[num]["re"])) 
                        return notify_fail("û������ظ���\n");
                else rep --;          
                                       
                me->start_more(sprintf("[ " HIW "��ţ�" NOR "%2d | " HIW "�ظ���ţ�" NOR "%2d] [ " HIW "ԭ�⣺" NOR "%-27s ] \n"
                               "[ " HIW "�ظ����⣺" NOR "%-50s ]\n����������������������������������������������������������������\n"
                               "%s\n����������������������������������������������������������������\n[ " HIW "ʱ�䣺" NOR "%s ] [ "
                               HIW "���ߣ�" NOR " %19s]\n",
                               num + 1, rep + 1,
                               notes[num]["title"],
                               notes[num]["re"][rep]["title"],
                               notes[num]["re"][rep]["msg"],
                               ctime(notes[num]["re"][rep]["time"]),
                               notes[num]["re"][rep]["author"] + "(" +
                               notes[num]["re"][rep]["owner"] + ")"));

                if (notes[num]["time"] > last_read_time)
                        me->set("board_last_read/" + query("board_id"),
                               notes[num]["time"]);

                return 1;
        } else 
        if (! sscanf(arg, "%d", num))
                return notify_fail("��Ҫ���ڼ������ӵĻظ���\n");

        if (num < 1 || num > sizeof(notes))
                return notify_fail("û��������ӡ�\n");
        num--;

        if (! wizardp(me) && private_board && strcmp(me->query("id"), notes[num]["owner"]))
                return notify_fail("������Ӳ��������ģ������㲻���Ķ���\n");                   
                                
        msg = sprintf("[ " HIW "��ţ�" NOR "%2d ] [ " HIW "���ߣ�" NOR "%20s ] [ " HIW "ʱ�䣺" NOR "%-9s ]\n[ "
                      HIW "���⣺" NOR "%-54s ]\n����������������������������������������������������������������\n%s\n"
                      "����������������������������������������������������[" HIW " �� ƪ �� " NOR "]\n",
                      num + 1,
                      notes[num]["author"] + "(" + notes[num]["owner"] + ")",
                      ctime(notes[num]["time"])[0..9],
                      notes[num]["title"],
                      notes[num]["msg"],);
        // ��ʾ�ظ�����Ŀ
        if (sizeof(notes[num]["re"]) && me->query("env/show_reply") != "all") 
                msg += sprintf(HIW "�ظ���" NOR "%d �ݡ�\n", sizeof(notes[num]["re"]));
                
        // ��ʾ����һ���ظ�
        if (me->query("env/show_reply") == "last") 
        {
                last = sizeof(notes[num]["re"]) - 1;
                msg += sprintf(
                               "\n[ " HIW "�ظ���ţ�" NOR "%2d] [ " HIW "�ظ����⣺" NOR "%-34s ] \n"
                               "����������������������������������������������������������������\n"
                               "%s\n����������������������������������������������������������������\n[ " HIW "ʱ�䣺" NOR "%s ] [ "
                               HIW "���ߣ�" NOR " %19s]\n",
                               last + 1,
                               notes[num]["re"][last]["title"],
                               notes[num]["re"][last]["msg"],
                               ctime(notes[num]["re"][last]["time"]),
                               notes[num]["re"][last]["author"] + "(" +
                               notes[num]["re"][last]["owner"] + ")");
        }
        // ��ʾ���еĻظ�
        if (me->query("env/show_reply") == "all") 
        {
                for (i = 0; i < sizeof(notes[num]["re"]); i++) 
                {
                        msg += sprintf(
                                       "\n[ " HIW "�ظ���ţ�" NOR "%2d] [ " HIW "�ظ����⣺" NOR "%-34s ] \n"
                                       "����������������������������������������������������������������\n"
                                       "%s\n����������������������������������������������������������������\n[ " HIW "ʱ�䣺" NOR "%s ] [ "
                                       HIW "���ߣ�" NOR " %19s]\n",
                                       i+1,
                                       notes[num]["re"][i]["title"],
                                       notes[num]["re"][i]["msg"],
                                       ctime(notes[num]["re"][i]["time"]),
                                       notes[num]["re"][i]["author"] + "(" +
                                       notes[num]["re"][i]["owner"] + ")");
                }
        }
        me->start_more(msg);

        if (notes[num]["time"] > last_read_time)
                me->set("board_last_read/" + query("board_id"),
                        notes[num]["time"]);

        return 1;
}


int do_banzhu(string arg)
{
        if (! arg) return notify_fail("ָ���ʽ�� banzhu <����id>\n");
        
        if (! stringp(arg) || strlen(arg) < 3) 
                return notify_fail("û������ˡ�\n");
                
        if (query("banzhu") == arg) 
                return notify_fail("Ŀǰ�İ������� " + arg + "������Ҫ���á�\n");
                
        if (SECURITY_D->get_status(this_player(1)) != "(admin)" &&
            query("owner_id") != this_player()->query("id")
			&& (string)SECURITY_D->get_status(this_player(1)) != "(boss)") 
                return notify_fail("�㲻�����񣬲��������ð�����\n");
                
        set("banzhu", arg);
        write("���� " HIW + arg + NOR " Ϊ" + name() + "�����ɹ���\n"); 
        save();
        return 1;
}

int delete_post(string arg)
{
        mapping *notes;
        int num, re_num;

        if (! arg ||sscanf(arg, "%d.%d", num, re_num) < 1)
                return notify_fail("ָ���ʽ��delete <���ӱ��>[.<�ظ����>]\n");
                
        notes = query("notes");
        if (! arrayp(notes)|| num < 1 || num > sizeof(notes))
                return notify_fail("û���������ӡ�\n");
                
        else 
        if (re_num) 
        {
                if (re_num < 1 || ! arrayp(notes[num - 1]["re"]) 
                        || re_num > sizeof(notes[num - 1]["re"]))
                        return notify_fail("û�����Żظ���\n");
                else 
                {
                        num--;
                        re_num--;
                        
                        if (notes[num]["re"][re_num]["owner"] != (string)this_player(1)->query("id")
                                && query("banzhu") != this_player(1)->query("id")
								&& (string)SECURITY_D->get_status(this_player(1)) != "(admin)"
                                && (string)SECURITY_D->get_status(this_player(1)) != "(boss)")
                                return notify_fail("����ظ�������д�ģ����ֲ��ǰ�����\n");
                                
                        else 
                        {
                                notes[num]["re"] = notes[num]["re"][0..re_num-1] + notes[num]["re"][re_num+1..sizeof(notes[num]["re"])-1];
                                set("notes", notes);
                                write("ɾ���� " + (num+1) + " �����ӵĵ� "+ (re_num + 1) + " �Żظ�....Ok��\n");                                            
                                save();         
                                return 1;
                        }
                }
        } else 
        {
                num--;
                if (notes[num]["owner"] != (string)this_player(1)->query("id")
                        && query("banzhu") != this_player(1)->query("id")
                        && (string)SECURITY_D->get_status(this_player(1)) != "(admin)"
						&& (string)SECURITY_D->get_status(this_player(1)) != "(boss)")
                        return notify_fail("������Ӳ�����д�ģ����ֲ��ǰ�����\n");

                notes = notes[0..num-1] + notes[num+1..sizeof(notes)-1];
                set("notes", notes);
                write("ɾ���� " + (num + 1) + " ������....Ok��\n");
                save();
                return 1;
        }
}


int do_search(string arg)
{
        mapping *notes;
        int i, last_time_read, j = 0;
        string msg, topic, note;
        object me = this_player();

        notes = query("notes");
        if (! pointerp(notes) || ! sizeof(notes))
        {
                tell_object(me, "Ŀǰû���κ����ӡ�\n");
                return 1;
        }
        
        if (! arg)
        {
                tell_object(me, "����������һ�����ӣ�\n");
                return 1;
        }
        
        if (sscanf(arg, "%s %s", topic, arg) != 2)
        {
                tell_object(me, "��ֻ����������(title)������(author)������(document)��\n");   
                return 1;
        } else
        {
                if (topic == "title") note = "����";
                else
                if (topic == "author") note = "����";
                else
                if (topic == "document") note = "����";
                else
                {
                        tell_object(me, "��ֻ����������(title)������(author)������(document)��\n");  
                        return 1;
                }
        }
                             
        last_time_read = this_player()->query("board_last_read/" + (string)query("board_id"));
        i = sizeof(notes);

        msg = sprintf("���� " HIY "%s" NOR " ���� " HIY "%s" NOR " �õ����·����������ӣ�\n"           
                      HIW "��ũ������⩤���������������������������������ߩ��ظ�������ʱ�䩤��������\n" NOR,
                      arg, note); 
                     
        while (i--)
        {
                if (topic == "document")
                {
                        if (strsrch(notes[i]["msg"], arg) == -1)
                                continue;
                } else  
                {                      
                        if (strsrch(notes[i][topic], arg) == -1)
                                continue;
                }

                msg += sprintf("%s[" WHT "%2d" NOR "]" NOR "  %-29s %12s " WHT "%+3d" NOR "   [%s]\n",
                               (notes[i]["time"] > last_time_read ? HIY: ""),
                               i + 1, notes[i]["title"], notes[i]["author"], sizeof(notes[i]["re"]),
                               ctime(notes[i]["time"])[0..15] ); 
 
                j++;          
                if (j > 19)
                { 
                        msg += "�����������Ľ��̫�࣬���ֻ��ʾ��ʮ�����ԣ���ʹ�ø���ȷ�Ĺؼ���|�ʡ�\n";
                        break;
                }                   
        }  

        if (j == 0)
        {
                tell_object(me, "���� " HIY + arg + NOR " ���� " HIY + note + NOR " û���ҵ��������������ӡ�\n");
                return 1;
        } 

        msg += HIW "��������������������������������������������������������������������������\n" NOR;
        me->start_more(msg);  
        return 1;
}      
        
