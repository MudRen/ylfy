//【蜀山派】mhxy-yushu 2001/2
#include <ansi.h>
inherit ROOM;
int do_qian(string arg);
void create ()
{
  set ("short", "山涧");
  set ("long", @LONG

    这里有一个小的水潭，可能是崖上的瀑布流下来的水长年累月的流不
出去而变成这个水潭吧，你绝望的看了看四周，全都是悬崖峭壁，看
来想在这里出去是不可能了，只有祈祷有奇迹发生。
LONG);

  set("exits", ([      
         "south" : __DIR__"shanjian",
 ]));
  set("item_desc",([ "水潭" : "这个水潭的水非常的清晰，你有想游游的欲望。",
]));
 setup();
}

void init()
{
  add_action("do_qian", "qian");
}
int do_qian(string arg)
{
  object me;me=this_player();
  if ((arg != "shui" && arg != "水") || !arg)
                       return notify_fail("不下水你怎么游？\n");
  if (me->is_busy()) return notify_fail("你忙着呢！\n");
  if (me->query("family/family_name") == "蜀山派")
  {
   message_vision(HIM"$N你用了全身的力气终于游到了水面上。\n"NOR, me);
   me->move(__DIR__"midao");
  }
else 
 {
  tell_object (me,"你在水潭里面游了一会，心里想道还是回去吧，不要耽误了练功!\n");
 }
 return 1;
}
