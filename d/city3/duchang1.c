
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "赌窟");
        set("long", @LONG
这里是赌二十一点的地方。有个很肥的荷倌在那里坐着，嘴
里不停地自言自语着什么，一副很冷静的样子。墙上也贴着规则
说明(rule)。
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([
                "west" : __DIR__"duchang",         
        ]));
        set("no_fight",1);
        set("no_magic",1);
        set("freeze",1);

        set("item_desc",([
            "rule" : "这里玩的是世界流行的二十一点，10(T)、J、Q、K都算十点，\n"+
                     "A算一点或十一点，每次最多限压10两黄金，祝你好运！:)\n"+
                    "若你的金子太多太重，请换（huan）为金票！！\n"
                 ]));
        set("objects",([
                __DIR__"npc/qianjinbao" : 1,
        ]));

                            
        setup();
}

int valid_leave(object me, string dir)
{
        if (!userp(me))         return ::valid_leave(me, dir);
        if (present("qian jinbao",environment(me))){
           if ( me->query_temp("tmark/押") && dir == "west" )
              return notify_fail("钱进宝跑到门边拦住：“已经下了注了，怎麽不赌就走了呢!”\n");
        }
        return ::valid_leave(me, dir);
}


 
