// story:shenzhao 凝血神爪

#include <ansi.h>

int give_gift();


mixed *story = ({
        "只听“镪铛”一声，阎世章五行双轮一招「指天划地」，挡开了霍青桐的长剑。",
        "阎世章退出一步，叫道：“且慢，我有话说。”",
        "众回人逼上前去，兵刃耀眼，眼见就要将他乱刀分尸。",
        "阎世章右手一扯，将背上的红布包袱拿在手中，双轮高举，叫道：“且慢！”",
        "众回人俱都大惊，退了几步。",
        "阎世章暗道：这次身入重围，难以逃脱，看来只有凭一身艺业以图侥幸。",
        "阎世章奸笑一声，说道：“如果你们要倚多取胜，我先将这包裹砍烂了。”",
        "霍青桐道：“好，就我和你单挑，接你五行轮的高招。”",
        "霍青桐说罢剑走偏锋，斜刺左肩。阎世章的双轮遮锁封拦，招数严密。两人转瞬拆了七八招。",
        "只听一声惊叫，阎世章右腕中剑，右轮飞上半空，众人不约而同，齐声喝彩。",
        "阎世章纵身飞出丈余，说道：“我认输了，经书给你！”反手去解背上红布包袱。",
        "霍青桐欢容满脸，抢上几步，还剑入鞘，双手去接这部他们族人奉为圣物的《可兰经》。",
        "阎世章脸色一沉，喝道：“拿去！”右手一扬，突然三把飞锥向她当胸疾飞而来。",
        "这一下变起仓卒，霍青桐难以避让，仰面一个「铁板桥」，全身笔直向后弯倒，躲了开去。",
        "阎世章一不做，二不休，三把飞锥刚脱手，紧接着又是三把连珠掷出。",
        "霍青桐双眼向天，不见大难已然临身。旁视众人尽皆惊怒，齐齐抢出。",
        "霍青桐刚挺腰立起，只听得叮、叮、叮三声，三柄飞锥被暗器打落地下，跌在脚边。",
        "霍青桐暗道：若非有人相救，三把飞锥已尽数打中自己要害。",
        "阎世章和身扑上，势若疯虎，五行轮对准霍青桐当头砸下。",
        "只见阎世章的五行轮渐渐压向霍青桐头上，轮周利刃已碰及她帽上翠羽。",
        "众人正要上前援手，忽然间青光一闪，霍青桐左手短剑扑的一声，插入阎世章胸腹之间。",
        "阎世章大叫一声，向后便倒。众人又是轰天价喝一声彩。",
        "霍青桐拔出短剑，看阎世章早已断气，松了口气，忽见无忧向她微微一笑。",
        "霍青桐心想：刚才打落这奸贼暗器，救了我性命的原来是他。",
        "霍青桐道：“承恩人相救小女性命，感激万分，请问恩人尊姓大名？”",
        "无忧轻轻一笑，说道：“在下无忧，女英雄有礼了。”",
        "无忧又道：“久闻天山双鹰两位前辈三分剑术冠绝当时，今日得见姑娘神技，真乃名下无虚。”",
        "霍青桐道：“今天承蒙想救，无以为赠，这套三分剑术如阁下如果有意，也可参详一番。”",
        "霍青桐又道：“若你我有缘，他日可上天山找我，将此套剑法的绝招传授予你。”",
        "无忧看了看说道：“什么破玩意?随手把三分剑术给扔了”",
        (: give_gift :),
});
string prompt() { return HIG "【武林奇遇】" NOR; }	

void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

int give_gift()
{
         
        int i;
        object ob;
        object *players;

        players = users();
        if (sizeof(players) >= 10)
        {
                for (i = 0; i < 10; i++)
                {
                        ob = players[random(sizeof(players))];
                        if (wizardp(ob)) continue;
                        if (ob->is_fighting()) continue;
                        if (!environment(ob)) continue;
                        if (ob->query_temp("netdead")) continue;
                        if (ob->query("story/luohuajian")) continue;                        
                                
                }
if(!ob) return 1;
        if (ob->query_skill("luohua-jian", 1) < 50)
                ob->set_skill("luohua-jian", 50);

        ob->set("story/luohuajian", 1);
if (ob)
{
        tell_object(ob, HIC "你从霍青桐那里学习到了三分剑术之落花剑法。\n" NOR);
//           CHANNEL_D->do_channel(this_object(), "rumor", "听说" + ob->name(1) +	
//                                 "从霍青桐那里学习到了三分剑术之落花剑法。");	
message("chat", HIG"【武林奇遇】"+NOR" 听说" + ob->name(1) + "从霍青桐那里学习到了三分剑术之落花剑法。\n"NOR,users() ); 	
}
        STORY_D->remove_story("new9");
      }
        return 1;
}
