//【蜀山派】mhxy-yushu 2001/2
inherit ROOM;
int do_climb(string arg);
void create ()
{
  set ("short","山涧");
  set ("long", @LONG

你拍了拍脑袋痛苦的爬起来，幸亏没有摔死，你向上面望了望，
可以试试爬(climb)上去，也可以往前面走看看。
LONG);

  set("exits", ([      
         "north" : __DIR__"shanjian2",
 ]));
 setup();
}

void init ()
{
  add_action ("do_climb","climb");
}

int do_climb(string arg)
{
  object me;me=this_player();
  if ((arg != "ya" && arg != "崖") || !arg)
       return notify_fail("你乱爬什么？\n");
  if (me->is_busy()) return notify_fail("你忙着呢！\n");
 if (arg="ya"&&arg="崖") 
  {
  message_vision("$N费力的向上爬去。。。\n",me);
  message_vision ("$N终于爬到了崖上。。。。。\n",me);
  me->move(__DIR__"jby");
}

  return 1;
}