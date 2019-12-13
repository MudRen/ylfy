inherit ROOM;

#include <ansi.h>
void create()
{
        set("short", "莫塔湖");
        set("long", @LONG 
眼前就是著名的莫塔湖，碧蓝的湖面倒影着蓝天和白云，浩淼的水面 
让人心旷神怡。居说此湖深不可测，冰冷澈骨，加上飞瀑往下冲，故名
虽是湖，而波涛汹涌非常,比之长江三峡水势，有过之而无不及,你可不
要(tiao)下去呀。
LONG    );

        set("exits", ([ /* sizeof() == 2 */
                "west" : "/d/tongchi/shandao2",        
  ]));
        set("outdoors", "tongchi" );
        set("no_clean_up", 0);
        setup();
}
 
void init()
{
        add_action("do_tiao","tiao");
}

 int do_tiao(string arg)
{
        object ob;
        int new_gin;
        ob = this_player();
        new_gin = random( ob->query("max_gin")*3 );
        if ( new_gin > ob->query("gin") ) new_gin = ob->query("gin") + 1;
        if( !arg || arg=="" ) return 0;
        if( arg != "down" )
                return notify_fail("你想死呀，这么急的河流都跳？\n");
         tell_object(ob, HIG"你不加思索，纵身一跃，跳进湖里。。。。\n"NOR);        message("vision", NOR"只见" + ob->query("name") + "鼓起勇气向莫塔湖跳去。。。。\n"NOR, environment(ob), ob);
        if((random((int)ob->query("kar")) < 15 ) && ((int)ob->query_skill("dodge")<30) )
        {
                ob->die();
                return 1;
        }
        ob->add("gin", 0 - new_gin);
        ob->move(__DIR__"hudi");
        return 1;
}