//wiz_apply

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short",HBRED "申请巫师房"NOR);
        set("long", @LONG
[1;35m 首先，你必须考虑清楚，成为一名巫师代表你将愿意花可能占去你大
部分的休闲时间在泥巴上，如果你不愿意，最好还是当个玩家的好，我们
目前需要的是优秀的巫师，共同开发好这个mud我们的需要
        1. 你必须是个「老练」的玩家.
        2. 你必须学过 C 语言 或 LPC 语言。
        3. 对武侠小说有一定的认识。
        4. 你必须有和他人合作，并且容忍批评和别人修改你的作品的雅量。

   我们并不打算给新巫师任何压力。在你下定决心要成为一名巫师之後，
并且认为自己能够满足条件后,

                请输入您的〖真实姓名〗：
                请输入您的〖巫师姓名〗：
                请输入您巫师的〖英文姓名〗：
                请输入您的〖性别〗：
                请输入您的〖年龄〗：
                请输入您的〖e-mail地址〗：

                你的联系地址和电话，传呼：
                你的单位（学校）：
                你是否有足够的时间来参与本MUD的建设：
                是否熟悉mud：
                你熟悉那几种程序语言（如：C,C++,JAVA,LPC ）

     [0;5;1;37m        请大家用return这个命令离开这里!

LONG);
        set("exits",([]));
        set("no_fight", "1");
        set("no_clean_up", 0);
        setup();
        call_other("/clone/board/wizapply_b", "???");
}

void init()
{
        add_action("do_return", "return");
        add_action("do_wizapply","wizapply");
}

int do_return(string arg)
{
        object me = this_player();

        message_vision(HIC"只见眼前一阵"HIR"狂风\n"NOR,me);
        message_vision(HIR"空间一阵转变，$N被传送回来的地方。\n"NOR,me);

        if (me->query("old_place"))     me->move(me->query("old_place"));
        else me->move("/d/city/wumiao");
        message_vision(HIR"空间一阵转变，$N被传送到了另一个国度。\n"NOR,me);
        me->delete("old_place");
        return 1;
}

int do_wizapply(string arg)
{
        write("你已经在这里就不必再用wizapply了。\n");
        return 1;
}
