// shiguan.c By csy

inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", HIB"石棺内"NOR);
    set("long", @LONG
棺盖内侧似乎写得有字，凝目瞧去，果见是十六个大字：「玉女心经，技
压全真。重阳一生，不弱於人。」这十六个字以浓墨所书，笔力苍劲，字体甚
大。其时棺盖只推开了一半，但斜眼看去，仍是清清楚楚。
LONG
        );

    set("exits", ([ 
            "out"  : __DIR__"lingshi",
    ]));
   
    set("no_fight",1);    
    setup();
}

void init()
{
        add_action("do_dian", "use");
        add_action("do_turn", "turn");
        add_action("do_turn", "zhuan");
        add_action("do_ti", "ti");        
        add_action("do_search","search");
		add_action("do_canwu", "canwu");
}

int do_dian(string arg)
{
        object ob,me=this_player();         
        if ( arg == "fire"){
         if(!objectp(ob = present("fire", me)))        
           return notify_fail("你没有火折，点什么？\n");
          message_vision(HIR"只听见“呲 ---”的一声，$N点亮了手中的火折。\n\n"NOR,me);
          write(HIY"再看那十六个字时，只见其后还写得有许多小字：破解玉女心经之法，吾置
之于此室之下，后人有缘，一观便知 ......重阳真人 .....\n"NOR);
          me->set_temp("marks/古墓1", 1);
          return 1;
          }
       return 0;
}

int do_search()
{
         object me = this_player();
         if (!me->query_temp("marks/古墓1"))
           return 0;
         if (me->query_temp("gumu1") < 8){
           message_vision(HIY"$N点亮火折，仔细地在石棺内四下摸索。\n"NOR,me);
           me->add_temp("gumu1",1);
           return 1;
           }
           message_vision(HIR"$N觉得手下一沉，果然摸到个可容一手的凹(ao)处。\n"NOR,me);
           me->delete_temp("marks/古墓1");
           me->delete_temp("gumu1");
           me->set_temp("marks/古墓2", 1);
        return 1;
}
           
int do_turn(string arg)
{
         object me=this_player();
         string dir;               
         if (!me->query_temp("marks/古墓2"))
           return 0;
         if (!arg||arg=="") return 0;
         if (me->is_busy() || me->is_fighting())
           return notify_fail("你正忙着哪！\n");    
         if( arg=="ao" ) {
           write("你要把凹处往哪里转？\n");
           }
        if( sscanf(arg, "ao %s", dir)==1 ) {
           if( dir=="left") {
           message_vision(HIG"$N将凹处往左转动几下，果然有些松动。\n"NOR,me );
           me->delete_temp("marks/古墓2");
           me->set_temp("marks/古墓3", 1);
           }   
      else return notify_fail("你将凹处胡乱转了几下，结果什么也没发生。\n");
        }               
     return 1;
}

int do_ti(string arg)
{
         object me =this_player();          
         if (!me->query_temp("marks/古墓3"))
           return 0;
         if (me->is_busy() || me->is_fighting())
           return notify_fail("你正忙着哪！\n");
         if ( arg =="up"){
           message_vision(YEL"$N紧紧握住了凹处向上一提,只听喀喇一响，棺底石板应手而起，
$N猝不及防，翻身跌入下层石室。\n"NOR,me);
           me->delete_temp("marks/古墓3");
           me->move(__DIR__"sshi1");
           return 1;
           }
        return notify_fail("你往哪里提？\n");
}


int do_canwu(string arg)
{
  object me=this_player();
  int ap;
  
 
  string *poem = ({
		"人徒知枯坐息思为进德之功，殊不知上达之士，圆通定慧，体用双修，即动而静，虽撄而宁。",
		"天之道，损有馀而补不足，是故虚胜实，不足胜有馀。其意博，其理奥，其趣深。天地之像分，阴阳之侯烈，变化之由表，死生之兆章。",
		"弱之胜强，柔之胜刚，天下莫不知，莫能行。",
		"天下之至柔，驰骋天下之至坚。",
		"五指发劲，无坚不破，摧敌首脑，如穿腐土。",
		"阴极在六，何以言九。太极生两仪，天地初刨判。六阴已极，逢七归元太素，太素西方金德，阴之清纯，寒之渊源。",
		});

    if(me->is_busy() )
          return notify_fail("你现在忙着呢，哪有功夫看墙上的东西...\n");

    if((int)me->query_skill("literate",1) < 5000 )
               return notify_fail("你看了墙上的文字，一脸茫然，始终无法领悟。\n");
   
     ap = me->query_skill("literate", 1) /1000;
   	
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
        message_vision("$N仔细的研究着墙上的文字：" + poem[random(sizeof(poem))] + "\n", me);
        me->add("jing",-100);
		me->add("potential",-100);
        me->start_busy(2);
    if(me->query("jiuyin/jm")) 
        {
        tell_object(me,"你已经完全领悟了九阴真经的精髓，不需要在这领悟了。\n");       
        return 1;
        }
    if((int)me->query_skill("jiuyin-zhenjing", 1) > 1500)
		{
        tell_object(me,HIW"你仔细研究了四周墙壁上的文字，尝试着练习了下......\n"NOR);
        me->improve_skill("literate", 50+random(10));
		
        me->start_busy(2);
        }
    if( random(1000000) < me->query("kar") + ap )
        {
        me->add("jiuyin/jm",1);
		tell_object(me,HIG"你已经领悟九阴真经的精髓\n"NOR);
        }
        return 1;
}             