// Room: /d/mingjiao/xuanya.c
// lisa 2003.7.3
#include <ansi.h>;
#include <room.h>;
inherit ROOM;
string look_sign(object me);
void create()
{
set("short", "悬崖");
set("long", @LONG
穿过丛林，眼前陡然一亮，群山如黛，横卧与云雾缥缈之中，不由
让人心旷神怡。往下一看，却见脚下峭壁(qiaobi)如被刀削而成，
深不见底。
LONG );
set("exits", ([
"southwest" : __DIR__"shulin12",
]));
set("item_desc", ([
"qiaobi": (: look_sign :),
]) );
set("outdoors", "mingjiao");
setup();
}
string look_sign(object me)
{
return "你探头往峭壁下望了望，只见云雾缭绕。一阵急风扑面而来，你不由倒退了几步。\n";
}
void init()
{
add_action("do_tiao","tiao");
add_action("do_tiao","jump");
}
int do_tiao(string str)
{
object me;
me=this_player();
if (!str || str==" ") return 0;
if (str!="qiaobi") return notify_fail("你要往哪儿跳？\n");	
if (str=="qiaobi")	
{
message_vision("$N迟疑了片刻，猛地跃下了悬崖。\n", me);
me->move("/d/mingjiao/gudi1");       	
me->unconcious();	
if (me->query_skill("dodge",1)<1000)	
{
me->set_temp("last_damage_from", "跳崖自杀而");                 	
me->die();
}
}
return 1;
}
