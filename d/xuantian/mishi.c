//mishi by suimeng 2015.3
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short","密室");
  set ("long", @LONG
       这里就是玄天派的一个不起眼的小房间，你只见到四面的墙壁上有
	   很多奇怪的痕迹，你走近一看，这似乎是某种刀法所造成的，到底是
	   如何造成的呢？或许可以研究(yanjiu)下。
LONG);
  
   set("exits", ([      
       "south" : "d/xuantian/lian",
   ]));
  setup();
}

void init()
{
  add_action("do_yanjiu", "yanjiu");
}

int do_yanjiu(string arg)
{
  object me=this_player();
  int ap;
  
 
  string *poem = ({
		"这道刀痕，似乎是「"HIM"花开花落"NOR"」，为什么会有这么大威力？",
		"这道刀痕，似乎是天行刀法其中一招「"HIG"背车一刀"NOR"」所造成的，似乎又有些不同。",
		"这道刀痕，「"HIB"风狂雨暴"NOR"」为什么.....？？难道因为某种内功？？？？？？",
		"这道刀痕「"HIY"轻风微拂"NOR"」，怎样逆天的内力，如此可怕....",
		"「"HIB"星云直坠"NOR"」么？？？？似乎又有些不同。为什么？",
		});

    if(me->is_busy() )
          return notify_fail("你现在忙着呢，哪有功夫看墙上的东西...\n");

    if((int)me->query_skill("literate",1) < 5000 )
               return notify_fail("你看了墙上的刀痕，一脸茫然，始终无法领悟。\n");
   
     ap = me->query_skill("literate", 1) /1000;
   
    if(me->query("family/family_name") != "玄天派")
        {
        tell_object(me,"你看了墙上的刀痕，这是什么刀法造成的？？？？？。\n"); 
		return 1;
		}		
	if (me->query("family/master_id")!="wuming laoren")
        {
        tell_object(me,"你看了墙上的刀痕，这似乎是某位高手练功所留下的，到底是谁呢？？？\n"); 
        return 1;
        }
	if (me->query_skill("yijing-force",1) < 1500)
        {
        tell_object(me,"似乎......内功......也许.......\n"); 
        return 1;
        }
    if(me->query("jing") < 1000)
        {
        tell_object(me,"你还是先休息一会儿吧。\n");     
        return 1;
        }
        message_vision("$N仔细的研究着墙上的刀痕：" + poem[random(sizeof(poem))] + "\n", me);
        me->add("jing",-100);		
        me->start_busy(2);
    if(me->query("zjb_dj/dj") >= 25) 
        {
        tell_object(me,"你已经完全领悟了天行刀法的精髓，不需要在这领悟了。\n");       
        return 1;
        }
    if((int)me->query_skill("tianxin-blade", 1) > 4000)
		{
        tell_object(me,HIW"你仔细研究了四周墙壁上的刀痕，尝试着练习了下......\n"NOR);
        me->improve_skill("literate", 50+random(10));
		
        me->start_busy(2);
        }
    if( random(500000) < me->query("kar") + ap && me->query("zjb_dj/dj") < 25)
        {
        me->add("zjb_dj/dj",1);
        tell_object(me,HIG"你突然醒悟道："HIY"原来天行刀法可以有此等威力"HIR"！\n"NOR);
		tell_object(me,HIG"你对天行刀法的精髓有所领悟\n"NOR);
        }
        return 1;
}             

