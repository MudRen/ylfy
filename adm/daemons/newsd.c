// newsd.c

#include <ansi.h>

inherit F_SAVE;
inherit F_DBASE;

// ���һǧ������
#define MAX_NEWS_CAPACITY 1000

nosave mixed *snotes = ({ });

void create()
{
        seteuid(getuid());
        restore();
}

void remove()
{
        save();
}

// ��ʾ�û�
void prompt_user(object me)
{
        int num;
        int total;
        mixed *notes;
        int last_read_time;

        last_read_time = me->query("last_read_news");
        if (! last_read_time)
        {
                tell_object(me, WHT "\n��ӭ������" + MUD_NAME +
                                WHT "�������ʹ��" HIY " news " NOR WHT
                                "������ķ�����������Ϣ��\n" NOR);
                //me->set("last_read_news", time());
                //return;
        }

        notes = query("notes");

        if (! arrayp(notes) || ! sizeof(notes))
                return;

        num = sizeof(notes);
        total = 0;
        while (num--)
                if (notes[num]["time"] > last_read_time)
                        total++;
                else
                        break;

        if (! total)
                tell_object(me, "\n��Ŀǰû��δ���Ķ��������š�\n");
        else
                tell_object(me, sprintf(WHT "\n��Ŀǰһ���� " HIY "%d" NOR
                                        WHT " �����Ż�û���Ķ�����ʹ��("
                                        HIY "news" NOR WHT ")�����Ķ���\n" NOR, total));

        // ��ʼ��ʱ֪ͨ
        if ( get_system_config(DATA_CONFIG_DIR "system.h", "AUTO_READ_NEWS") 
			&& previous_object() == find_object(LOGIN_D) )
                me->start_call_out(bind((: call_other, __FILE__, "auto_notice", me :), me),
                                        10 + random(10));
}

// ��ʾ���е����ű���
// raw = 1: ����ʾδ������
void show_news(object me, int raw)
{
        mixed *notes;
        int i, last_time_read;
        string msg;

        notes = query("notes");

        if (! pointerp(notes) || ! sizeof(notes))
        {
                tell_object(me, "Ŀǰû���κ����š�\n");
                return;
        }

        msg = "Ŀǰ"+MUD_NAME+"�е�������Ϣ���¡�\n"
              WHT "--------------------------------------------------------------------------------\n" NOR;
        last_time_read = me->query("last_read_news");
        i = sizeof(notes);
        while (i--)
        {
                if (raw && (notes[i]["time"] <= last_time_read))
                        break;

                msg += sprintf(NOR"%s[%4d]" NOR " %-37s %16s (%s)\n",
                               (notes[i]["time"] > last_time_read ? HIY : ""),
                               i + 1, notes[i]["title"][0..36],
                               notes[i]["author"], ctime(notes[i]["time"])[0..15]);
        }

        if (i == sizeof(notes) - 1)
        {
                tell_object(me, "Ŀǰû���κ�δ���������š�\n");
                return;
        }
		
		me->start_more(msg);
        msg = WHT "--------------------------------------------------------------------------------\n" NOR;
		msg += HIC"�Ķ�����ָ���ʽ��"HIY"news "NOR"<"HIY"new"NOR"|"HIY"next"NOR"|"HIY"���ű��"NOR">\n"NOR;
		msg += HIC"��������ָ���ʽ��"HIG"news search "NOR"<"HIG"title"NOR"|"HIG"author"NOR"|"HIG"document"NOR
			"> "NOR"<"HIM"�ؼ���"NOR"|"HIM"�ؼ���"NOR">\n"NOR;
        write(msg);
}

void done_post(object me, mapping note, int n, string text)
{
        int i;
        int pl;
        string sign;
        string pure;
        mapping *notes;
        
        if (! n) n = me->query("env/default_sign");
        if (! stringp(sign = me->query(sprintf("env/sign%d", n))))
        {
                // �Զ�ѡ���һ���ǿ�ǩ��
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
        }

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

        // Truncate the notes if maximum capacity exceeded.
        if (sizeof(notes) > MAX_NEWS_CAPACITY)
                notes = notes[MAX_NEWS_CAPACITY / 4 .. MAX_NEWS_CAPACITY];

        set("notes", notes);
		save();
        tell_object(me, "���ŷ�����ϡ�\n");
        message("system", BLINK HIW "\n�����ž��顿�����������ţ���λ������� news �鿴��\n\n" NOR,     
                users()); 
}

// ��������
void do_post(object me, string arg)
{
        int n;
        mapping note;

        if (! wizardp(me) || ! interactive(me))
        {
                tell_object(me, "ֻ����ʦ���ܷ������š�\n");
                return;
        }

        if (! arg)
        {
                tell_object(me, "����������ָ��һ�����⡣\n");
                return;
        }

        if (sscanf(arg, "%s with %d", arg, n) != 2)
                n = 0;

        if (replace_string(arg, " ", "") == "")
                arg = "�ޱ���";
        else
                arg = color_filter(arg) + NOR;
        note = allocate_mapping(4);
        note["title"] = arg;
        note["author"] = me->name(1) + "-" + me->query("id");
        note["time"] = time();
        me->edit(bind((: call_other, __FILE__, "done_post", me, note, n :), me));
}

// �Ķ�����
void do_read(object me, string arg)
{
        int num;
        mixed *notes;
        int last_read_time;

        last_read_time = me->query("last_read_news");
        notes = query("notes");
        if (! pointerp(notes) || ! sizeof(notes))
        {
                tell_object(me, "Ŀǰû���κ����š�\n");
                return;
        }

        if (! arg)
        {
                tell_object(me, "�������һ�����ţ�\n");
                return;
        }

        if (arg == "new" || arg == "next")
        {
                if (! last_read_time)
                        num = 1;
                else
                        for (num = 1; num <= sizeof(notes); num++)
                                if (notes[num - 1]["time"] > last_read_time)
                                        break;
        } else
        if (! sscanf(arg, "%d", num))
        {
                tell_object(me, "��Ҫ���ڼ������ţ�\n");
                return;
        }

        if (num < 1 || num > sizeof(notes))
        {
                tell_object(me, "û���������š�\n");
                return;
        }
        num--;
        me->start_more(sprintf(HIY "��������������������������������������������������������������������������������\n"
                               NOR "[%4d] %s %65s (%s)\n "
                               HIY "������������������������������������������"
							   "������������������������������������" NOR "\n%s" 
							   HIY "��������������������������������������������������������������������������������\n"NOR,
                               num + 1, sort_string(notes[num]["title"], 73, 0), notes[num]["author"],
                               ctime(notes[num]["time"])[0..9], sort_string(notes[num]["msg"], 79, 0)));

        // Keep track which post we were reading last time.
        if (notes[num]["time"] > (int)last_read_time)
                me->set("last_read_news", notes[num]["time"]);
}

// ɾ������
void do_discard(object me, string arg)
{
        mixed *notes;
        int num;
        string author, aid;

        if (! arg || sscanf(arg, "%d", num) != 1)
        {
                tell_object(me, "����ȥ����һ�����ţ�\n");
                return;
        }
        notes = query("notes");
        if (! arrayp(notes) || num < 1 || num > sizeof(notes))
        {
                tell_object(me, "û���������š�\n");
                return;
        }

        num--;
        if ((! stringp(author = notes[num]["author"]) ||
             sscanf(author, "%*s-%s", aid) != 2 ||
             aid != me->query("id")) &&
            (string)SECURITY_D->get_status(me) != "(boss)")
        {
                tell_object(me, "ֻ�д����߲���ȥ�����˷��������š�\n");
                return;
        }

        notes = notes[0..num - 1] + notes[num + 1..sizeof(notes) - 1];
        set("notes", notes);
        save();
        tell_object(me, "ɾ���� " + (num + 1) + " ������....Ok��\n");
}

// �Զ�֪ͨ���
void auto_notice(object me)
{
        int num;
        mixed *notes;
        string msg;
        int last_read_time;

        if (! objectp(me))
                return;

        last_read_time = me->query("last_read_news");
        notes = query("notes");

        if (! pointerp(notes) || ! sizeof(notes))
                return;

        num = sizeof(notes) - 1;
        if (notes[num]["time"] <= last_read_time)
                return;

        // ����һЩ���Ŵ�������ʼ�µ� call_out
        me->start_call_out(bind((: call_other, __FILE__, "auto_notice", me :), me), 30 + random(30));

        if (! living(me) || me->query_temp("block_msg/all"))
                return;

        while (num-- > 0)
        {
                if (notes[num]["time"] <= last_read_time)
                {
                        num++;
                        break;
                }

                // ����������һ��
        }

        if (num < 0) num = 0;

        switch (random(5))
        {
        case 0:
                msg = HIM "һ������������ž�������������ǰ������"
                      "����һ���������õ�ֽͷ����������������\n" NOR;
                break;
        case 1:
                msg = HIM "����ͻȻ����һ���ѷ죬ð��һ������������"
                      "�ž��飬��������ੲ��ݵ�����������\n" NOR;
                break;
        case 2:
                msg = HIM "���Ȼ�������˺��㣬���ͷһ����ԭ��������"
                      "������ͷ�󺹵����˹�����\n" NOR;
                break;
        case 3:
                msg = HIM "��մ���һ����Ƿ����Ȼǰ��ð��һ������ɢ"
                      "ȥ�Ժ�ֻ��һ�����ž���������Ŀ����㣬���������дʡ�\n" NOR;
                break;
        default:
                msg = HIM "��ž����һ�������ž����Ǳ�������ˤ�ڵ��ϣ�"
                      "����æ��������\n" NOR;
                break;
        }

        msg += HIG "���ž����������������������Ϣ��\n" NOR;
        tell_object(me, msg);
        /*me->start_more(sprintf(" [%d] %-" + (40 + color_len(notes[num]["title"])) +
                               "s %15s (%s)\n" HIC "��"
                               HIY "����������������������������������������������"
                               "������������������������������" HIC "��\n" NOR,
                               num + 1, notes[num]["title"], notes[num]["author"],
                               ctime(notes[num]["time"])[0..9]) + notes[num]["msg"]);*/
		me->start_more(sprintf(HIY "��������������������������������������������������������������������������������\n"
                               NOR "[%4d] %s %65s (%s)\n "
                               HIY "������������������������������������������"
							   "������������������������������������" NOR "\n%s" 
							   HIY "��������������������������������������������������������������������������������\n"NOR,
                               num + 1, sort_string(notes[num]["title"], 73, 0), notes[num]["author"],
                               ctime(notes[num]["time"])[0..9], sort_string(notes[num]["msg"], 79, 0)));

        // Keep track which post we were reading last time.
        if (notes[num]["time"] > (int)last_read_time)
                me->set("last_read_news", notes[num]["time"]);
        tell_object(me, HIM "���ž���˵�����ʧ��һ������֮�С�\n" NOR);
}

void do_search(object me, string arg)
{
        mixed *notes;
        int i, last_time_read, j;
        string msg, topic, theway;
        notes = query("notes");
  
        if (! arrayp(notes) || ! sizeof(notes))
        {
                tell_object(me, "Ŀǰû���κ����š�\n");
                return;
        }
        
        if (! arg)
        {
                tell_object(me, "����������һ�����ţ�\n");
                return;
        }
        
        if (sscanf(arg, "%s %s", topic, arg) != 2)
        {
                tell_object(me, "��ֻ����������(title)������(author)������(document)��\n");   
                return;
        } else
        {
                if (topic == "title") 
                        theway = "����";
                else
                if (topic == "author") 
                        theway = "����";
                else
                if (topic == "document") 
                        theway = "����";
                else
                {
                        tell_object(me, "��ֻ����������(title)������(author)������(document)��\n");  
                        return;
                }
        }
                             
        last_time_read = me->query("last_read_news");       

        msg = sprintf("���� " HIY "%s" NOR " ���� " HIY "%s" NOR " �õ����·����������ţ�\n"           
                      WHT "--------------------------------------------------------------------------------\n" NOR,
                      arg, theway);   
                      
        i = sizeof(notes);   
        j = 0;             
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
                
                j++;
                msg += sprintf("%s[%4d]" NOR " %-37s %16s (%s)\n",
                               (notes[i]["time"] > last_time_read ? HIY : ""),
                               i + 1, notes[i]["title"][0..36],
                               notes[i]["author"], ctime(notes[i]["time"])[0..15]);  
                if (j > 99)
                { 
                        msg += HIW "\n�����������Ľ��̫�࣬���ֻ��ʾһ�������ţ���ʹ�ø���ȷ�Ĺؼ���|�ʡ�\n" NOR;
                        break;
                }
        }  

        if (j == 0)
        {
                tell_object(me, "���� " HIY + arg + NOR " ���� " HIY + theway + NOR " û���ҵ�����Ҫ������š�\n");
                return;
        } 
        
        msg += WHT "--------------------------------------------------------------------------------\n" NOR;

        me->start_more(msg);  
}      

string query_save_file() { return DATA_DIR "newsd"; }
