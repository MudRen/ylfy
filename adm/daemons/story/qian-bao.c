//钱包

#include <ansi.h>
string give_gift();

mixed *story = ({
        "某--秋高气爽的一天",
        "碎梦和一帮朋友相约在ktv喝酒。",
        "翠花........上酒。",
        "兄弟，感情深一口闷,感情浅舔一舔。",
        "说完。",
        "举起酒瓶..一口见底.。",
		"....",
		"....",
		"确定是酒？",
		"......确定.......",
		"说完，所有人都倒地上了......",
		"第二日",
		"碎梦：我的钱包呢！~~~？？？？",
        (: give_gift :),
});

void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

string give_gift()
{
        STORY_D->give_gift("/clone/misc/qian-bao", 1,
                           HIM "\n“啪”的一声一个钱包掉到你面前。\n\n" NOR);
        return HIM "听说碎梦居士的钱包丢了。\n" NOR;
}