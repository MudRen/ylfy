// Room: /d/cxwxm/longfeng.c
// marry 8,14
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIY"龙"HIC"飞"HIG"凤"HIM"舞"HIB"楼"NOR);
        set("long", 
"这里就是痴心妄想门的密室，非嫡系弟子是无法来到这里的，地上\n"
"的灰尘足有寸余厚，看来很久都未来过人了。在密室四周的墙上刻着的\n"
""+HIW"图"HIR"案"NOR+"(tuan)想必就是本门的究极奥义！\n\n"

);
        set("item_desc", ([ /* sizeof() == 1 */
  "tuan" : HIW"图案上画的是一男一女在练武，到底是什么意思呢？看来要仔细研究（yanjiu）一下了。
\n\n"NOR,
]));
   
        set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"fanting",
]));

        setup();
}
void init()
{
        add_action("do_yanjiu", "yanjiu");
}
int do_yanjiu(string arg)
{
        object me = this_player();

    if( !arg || arg!="tuan" )
        {
        write("你想做什么？\n");
        return 1;
    }
     if ((me->query("family/family_name") == "痴心妄想门")&&(int)me->query_skill("bianfu-hebi", 1) < 800)
    {
// message_vision(HIY"$N仔细的研究了墙上的图案，终于心领神会。\n"NOR,me);
 message_vision(HIY"这里少了个skill,暂时取消。\n"NOR,me);
/*
                me->receive_damage("jing", 8 + random(5));
me->improve_skill("bianfu-hebi", me->query("int")*3);
*/
        if ( (int)me->query("jing") < 1){me->unconcious();}
    }
    else
        {
          message_vision(
                HIR "你研究了一会儿墙上的图案，只觉得头晕目眩，惨叫了一声！\n" NOR, me);
                me->set("qi",1);
                me->unconcious();
                me->move(__DIR__"fanting");
                }
                return 1;
}
