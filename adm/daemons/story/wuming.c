#include <ansi.h>
#include <localtime.h>

#define GOT_MAX_NEILI 100000

int give_gift();

mixed *story = ({
  " 在深山的一个小山洞里。。。。。",
  "“死老头，那本剑谱在哪里？再不交出来今天就是你的死期！”",
  "“畜生，我已经把剑谱烧了，哈哈！剑谱就在我的脑里，你这辈子都别想得到！”",
  "“那你去死吧！”，说完手上钢剑便往老人刺去！老人身受重伤不能动弹，只好闭目等死。",
  "“叮。。。。”，钢剑被人撩开，只见一人立于老人之前。",
  "“这人好快的身手”，“阁下是何人？”",
  " 那人冷冷答道：“哼！你又是谁！为何如此对待一个老人？”",
  "“他就是老夫的徒弟”，咳。。。咳。。。",
  "“什么！？欺师灭祖，死有余辜，看剑！”",
  "“呲”。。。。长剑已穿胸而过。。。。",
  "“你。。。。。”",
  " 。。。。。。",
  "“老前辈，你怎样了？”",
  "“唉！我被这孽徒偷袭，身受重伤，恐怕活不了多久了。”",
  "“前辈，我给你运功疗伤。”",
  "“不必了，我的心脉已然受到重创，再世华佗也救不了我。”",
  " 老人把身旁的石块一拧，旁边的石壁突然弹出一个石匣，老人从石匣里拿出一本旧书。",
  "“你帮我杀了这个孽徒，也算帮了我一个大忙，这本剑谱就送给你吧，希望你以后能多行侠仗义。”",
  "“我将不久于人世，我就成全你，把我的一身功力都传给你吧。”",
  "“前辈不可！”",
  "“别动！”",
  "“。。。。。”",
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
    string msg;
    object book;
    mixed *tm=localtime(time());

    players = users();
    if (sizeof(players) >= 30)
    {
	for (i = 0; i < 30; i++)
	{
	    ob = players[random(sizeof(players))];
	    if (wizardp(ob)) continue;
	    if (!environment(ob)) continue;
	    if (ob->query_temp("netdead")) continue;
		//if (ob->query("max_neili") > 10000000) continue;
	}
	if(!ob) return 1;

	if (ob)
	{
	    tell_object(ob, HIC "你从无名老人那得到无名剑谱和老人的毕生功力。\n" NOR);  
	    message("channel:chat", HIG"【武林奇遇】"+HIW" 听说" + ob->name(1) + "从无名老人那得到了无名剑谱和老人的毕生功力。\n"NOR,users() );
		if (ob->query("max_neili") < 100000)
		{
	    ob->add("max_neili",GOT_MAX_NEILI * random(10));
		}
		else if (ob->query("max_neili") < 1000000)
		{
	    ob->add("max_neili",GOT_MAX_NEILI + random(GOT_MAX_NEILI));
		}
		else ob->add("max_neili", random(GOT_MAX_NEILI));
	    book = new("/clone/book/wuming");
	   /* if(book && objectp(book))
	    {
		book->move(ob);
		ob->set("qinhuang",1);
	    }*/
	    msg=sprintf("%d-%d-%d %d:%d:%d",tm[LT_YEAR],tm[LT_MON]+1,tm[LT_MDAY],tm[LT_HOUR],tm[LT_MIN]+1,tm[LT_SEC]+1);
	    log_file("story_wuming.log",ob->name(1) + "从无名老人那得到了无名剑谱和老人的毕生功力。["+msg+"]\n");
	}
	STORY_D->remove_story("wuming");
    }
    return 1;
}

