// newsd.c

#include <ansi.h>

inherit F_SAVE;
inherit F_DBASE;

// 最多一千条新闻
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

// 提示用户
void prompt_user(object me)
{
        int num;
        int total;
        mixed *notes;
        int last_read_time;

        last_read_time = me->query("last_read_news");
        if (! last_read_time)
        {
                tell_object(me, WHT "\n欢迎您进入" + MUD_NAME +
                                WHT "，今后请使用" HIY " news " NOR WHT
                                "命令查阅发布的新闻信息。\n" NOR);
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
                tell_object(me, "\n你目前没有未曾阅读过的新闻。\n");
        else
                tell_object(me, sprintf(WHT "\n你目前一共有 " HIY "%d" NOR
                                        WHT " 条新闻还没有阅读，请使用("
                                        HIY "news" NOR WHT ")命令阅读。\n" NOR, total));

        // 开始定时通知
        if ( get_system_config(DATA_CONFIG_DIR "system.h", "AUTO_READ_NEWS") 
			&& previous_object() == find_object(LOGIN_D) )
                me->start_call_out(bind((: call_other, __FILE__, "auto_notice", me :), me),
                                        10 + random(10));
}

// 显示所有的新闻标题
// raw = 1: 仅显示未读新闻
void show_news(object me, int raw)
{
        mixed *notes;
        int i, last_time_read;
        string msg;

        notes = query("notes");

        if (! pointerp(notes) || ! sizeof(notes))
        {
                tell_object(me, "目前没有任何新闻。\n");
                return;
        }

        msg = "目前"+MUD_NAME+"中的最新消息如下。\n"
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
                tell_object(me, "目前没有任何未读过的新闻。\n");
                return;
        }
		
		me->start_more(msg);
        msg = WHT "--------------------------------------------------------------------------------\n" NOR;
		msg += HIC"阅读新闻指令格式："HIY"news "NOR"<"HIY"new"NOR"|"HIY"next"NOR"|"HIY"新闻编号"NOR">\n"NOR;
		msg += HIC"搜索新闻指令格式："HIG"news search "NOR"<"HIG"title"NOR"|"HIG"author"NOR"|"HIG"document"NOR
			"> "NOR"<"HIM"关键字"NOR"|"HIM"关键词"NOR">\n"NOR;
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
                // 自动选择第一个非空签名
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
        tell_object(me, "新闻发布完毕。\n");
        message("system", BLINK HIW "\n【新闻精灵】有了最新新闻！各位玩家请用 news 查看。\n\n" NOR,     
                users()); 
}

// 发布新闻
void do_post(object me, string arg)
{
        int n;
        mapping note;

        if (! wizardp(me) || ! interactive(me))
        {
                tell_object(me, "只有巫师才能发布新闻。\n");
                return;
        }

        if (! arg)
        {
                tell_object(me, "发布新闻请指定一个标题。\n");
                return;
        }

        if (sscanf(arg, "%s with %d", arg, n) != 2)
                n = 0;

        if (replace_string(arg, " ", "") == "")
                arg = "无标题";
        else
                arg = color_filter(arg) + NOR;
        note = allocate_mapping(4);
        note["title"] = arg;
        note["author"] = me->name(1) + "-" + me->query("id");
        note["time"] = time();
        me->edit(bind((: call_other, __FILE__, "done_post", me, note, n :), me));
}

// 阅读新闻
void do_read(object me, string arg)
{
        int num;
        mixed *notes;
        int last_read_time;

        last_read_time = me->query("last_read_news");
        notes = query("notes");
        if (! pointerp(notes) || ! sizeof(notes))
        {
                tell_object(me, "目前没有任何新闻。\n");
                return;
        }

        if (! arg)
        {
                tell_object(me, "你想读那一条新闻？\n");
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
                tell_object(me, "你要读第几条新闻？\n");
                return;
        }

        if (num < 1 || num > sizeof(notes))
        {
                tell_object(me, "没有这条新闻。\n");
                return;
        }
        num--;
        me->start_more(sprintf(HIY "────────────────────────────────────────\n"
                               NOR "[%4d] %s %65s (%s)\n "
                               HIY "～～～～～～～～～～～～～～～～～～～～～"
							   "～～～～～～～～～～～～～～～～～～" NOR "\n%s" 
							   HIY "────────────────────────────────────────\n"NOR,
                               num + 1, sort_string(notes[num]["title"], 73, 0), notes[num]["author"],
                               ctime(notes[num]["time"])[0..9], sort_string(notes[num]["msg"], 79, 0)));

        // Keep track which post we were reading last time.
        if (notes[num]["time"] > (int)last_read_time)
                me->set("last_read_news", notes[num]["time"]);
}

// 删除新闻
void do_discard(object me, string arg)
{
        mixed *notes;
        int num;
        string author, aid;

        if (! arg || sscanf(arg, "%d", num) != 1)
        {
                tell_object(me, "你想去掉拿一条新闻？\n");
                return;
        }
        notes = query("notes");
        if (! arrayp(notes) || num < 1 || num > sizeof(notes))
        {
                tell_object(me, "没有这条新闻。\n");
                return;
        }

        num--;
        if ((! stringp(author = notes[num]["author"]) ||
             sscanf(author, "%*s-%s", aid) != 2 ||
             aid != me->query("id")) &&
            (string)SECURITY_D->get_status(me) != "(boss)")
        {
                tell_object(me, "只有创世者才能去掉他人发布的新闻。\n");
                return;
        }

        notes = notes[0..num - 1] + notes[num + 1..sizeof(notes) - 1];
        set("notes", notes);
        save();
        tell_object(me, "删除第 " + (num + 1) + " 条新闻....Ok。\n");
}

// 自动通知玩家
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

        // 还有一些新闻待读，开始新的 call_out
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

                // 继续查找下一个
        }

        if (num < 0) num = 0;

        switch (random(5))
        {
        case 0:
                msg = HIM "一阵烟雾过后，新闻精灵出现在你的面前，手里"
                      "捏着一张破破烂烂的纸头，对你宣读起来。\n" NOR;
                break;
        case 1:
                msg = HIM "地上突然开了一个裂缝，冒出一个鬼鬼祟祟的新"
                      "闻精灵，对着你就喋喋不休的罗嗦起来。\n" NOR;
                break;
        case 2:
                msg = HIM "你忽然听见有人喊你，你回头一看，原来是新闻"
                      "精灵满头大汗的跑了过来，\n" NOR;
                break;
        case 3:
                msg = HIM "你刚打了一个哈欠，忽然前面冒出一股烟雾，散"
                      "去以后只见一个新闻精灵懒洋洋的看着你，口中念念有词。\n" NOR;
                break;
        default:
                msg = HIM "“啪啦”一声，新闻精灵狼狈不堪的摔在地上，"
                      "你连忙将他扶起。\n" NOR;
                break;
        }

        msg += HIG "新闻精灵告诉你来自神界的最新消息：\n" NOR;
        tell_object(me, msg);
        /*me->start_more(sprintf(" [%d] %-" + (40 + color_len(notes[num]["title"])) +
                               "s %15s (%s)\n" HIC "≡"
                               HIY "───────────────────────"
                               "───────────────" HIC "≡\n" NOR,
                               num + 1, notes[num]["title"], notes[num]["author"],
                               ctime(notes[num]["time"])[0..9]) + notes[num]["msg"]);*/
		me->start_more(sprintf(HIY "────────────────────────────────────────\n"
                               NOR "[%4d] %s %65s (%s)\n "
                               HIY "～～～～～～～～～～～～～～～～～～～～～"
							   "～～～～～～～～～～～～～～～～～～" NOR "\n%s" 
							   HIY "────────────────────────────────────────\n"NOR,
                               num + 1, sort_string(notes[num]["title"], 73, 0), notes[num]["author"],
                               ctime(notes[num]["time"])[0..9], sort_string(notes[num]["msg"], 79, 0)));

        // Keep track which post we were reading last time.
        if (notes[num]["time"] > (int)last_read_time)
                me->set("last_read_news", notes[num]["time"]);
        tell_object(me, HIM "新闻精灵说完后，消失在一阵烟雾之中。\n" NOR);
}

void do_search(object me, string arg)
{
        mixed *notes;
        int i, last_time_read, j;
        string msg, topic, theway;
        notes = query("notes");
  
        if (! arrayp(notes) || ! sizeof(notes))
        {
                tell_object(me, "目前没有任何新闻。\n");
                return;
        }
        
        if (! arg)
        {
                tell_object(me, "你想搜索那一条新闻？\n");
                return;
        }
        
        if (sscanf(arg, "%s %s", topic, arg) != 2)
        {
                tell_object(me, "你只能搜索标题(title)、作者(author)、内容(document)。\n");   
                return;
        } else
        {
                if (topic == "title") 
                        theway = "标题";
                else
                if (topic == "author") 
                        theway = "作者";
                else
                if (topic == "document") 
                        theway = "内容";
                else
                {
                        tell_object(me, "你只能搜索标题(title)、作者(author)、内容(document)。\n");  
                        return;
                }
        }
                             
        last_time_read = me->query("last_read_news");       

        msg = sprintf("根据 " HIY "%s" NOR " 搜索 " HIY "%s" NOR " 得到如下符合条件新闻：\n"           
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
                        msg += HIW "\n由于搜索到的结果太多，因此只显示一百条新闻，请使用更明确的关键字|词。\n" NOR;
                        break;
                }
        }  

        if (j == 0)
        {
                tell_object(me, "根据 " HIY + arg + NOR " 搜索 " HIY + theway + NOR " 没有找到符合要求的新闻。\n");
                return;
        } 
        
        msg += WHT "--------------------------------------------------------------------------------\n" NOR;

        me->start_more(msg);  
}      

string query_save_file() { return DATA_DIR "newsd"; }
