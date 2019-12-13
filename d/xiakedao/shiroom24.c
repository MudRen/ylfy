// /d/xiakedao/shishi24.c 侠客岛 石室24

inherit ROOM;

int do_study(string arg);
void create()
{
        set("short", "石室");
        set("long", @LONG
这里火光昏暗，只见那龙岛主与木岛主盘膝坐在锦垫之上，面对
石壁(wall)，凝神苦思。此石室已是山腹最深处，却宽阔高大，足可
容下近百人。洞中火把亦是其他洞的二三倍之多。
LONG );
        set("exits", ([
                "east" : __DIR__"shihole6",
        ]));
        set("item_desc", ([
                "wall" : @WALL
墙的正上方刻着「白首太玄经」几个大字。字的下方刻的是密密麻麻
的蝌蚪文，成千上万。文字排列甚不整齐，或横或竖，或直或斜。左
下的大片甚至混成一团难分次序，委实难以辨认（canwu）。
WALL
        ]));
        set("objects", ([
                 __DIR__"npc/mu" : 1,
                __DIR__"npc/long" : 1,
        ]));
        set("no_clean_up", 0);
       //  set("no_fight", 1);
        set("no_beg", 1);
        setup();
}

void init()
{
        add_action("do_study","think");
		add_action("do_canwu","canwu");
}
#include "/d/xiakedao/shiroom.h"

int do_canwu(string arg)
{
  object me=this_player();
  int ap;
  
 
  /*string *poem = ({
		"人徒知枯坐息思为进德之功，殊不知上达之士，圆通定慧，体用双修，即动而静，虽撄而宁。",
		"天之道，损有馀而补不足，是故虚胜实，不足胜有馀。其意博，其理奥，其趣深。天地之像分，阴阳之侯烈，变化之由表，死生之兆章。",
		"弱之胜强，柔之胜刚，天下莫不知，莫能行。",
		"天下之至柔，驰骋天下之至坚。",
		"五指发劲，无坚不破，摧敌首脑，如穿腐土。",
		"阴极在六，何以言九。太极生两仪，天地初刨判。六阴已极，逢七归元太素，太素西方金德，阴之清纯，寒之渊源。",
		});*/

    if(me->is_busy() )
          return notify_fail("你现在忙着呢，哪有功夫看墙上的东西...\n");

    if((int)me->query_skill("literate",1) > 0 )
               return notify_fail("你看了墙上的蝌蚪文，一脸茫然，始终无法领悟。\n");
   
     ap = me->query_skill("taixuan-gong", 1) /1000;
   	
    if(me->query("jing") < 1000)
        {
        tell_object(me,"你还是先休息一会儿吧。\n");     
        return 1;
        }	
    if(me->query("potential") < 1000)
        {
        tell_object(me,"你的潜能不足.....。\n");     
        return 1;
        }	
        
        me->add("jing",-100);
		me->add("potential",-100);
        me->start_busy(2);
       if(me->query("taixuan/jm")) 
        {
        tell_object(me,"你已经完全领悟了太玄经的精髓，不需要在这领悟了。\n");       
        return 1;
        }
    if((int)me->query_skill("taixuan-gong", 1) > 2000)
		{
        tell_object(me,HIW"你仔细研究了四周墙壁上的文字，尝试着练习了下......\n"NOR);
        me->improve_skill("literate", 50+random(10));
		
        me->start_busy(2);
        }
    if( random(2000000) < me->query("kar") + ap )
        {
        me->add("taixuan/jm",1);
		tell_object(me,HIG"你已经领悟太玄经的精髓\n"NOR);
        }
        return 1;
}             