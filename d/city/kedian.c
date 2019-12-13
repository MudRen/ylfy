// Room: /city/kedian.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
set("short", CYN"扬州客栈"NOR);	
        set("long", @LONG
这是扬州城本地一家价钱低廉的客栈，生意非常兴隆。外地游客多
选择这里落脚，你可以在这里打听到当地的风土人情。店小二里里外外
忙得团团转，接待着南腔北调的客人。角落里几位江湖人物打扮的大汉
正围着一张桌子不知道在商量什么,客店的主人从不露面，他究竟是谁，
有各种各样的猜测。墙上挂着一个牌子(paizi)。
LONG
        );
          set("no_fight", 1);
        set("valid_startroom", 1);
//          set("no_sleep_room",1);	
        set("item_desc", ([
                "paizi" : "楼上雅房，每夜一两白银。\n",
        ]));
        set("objects", ([
                __DIR__"npc/xiaoer" : 1,
        ]));
        set("no_clean_up",1);
        set("exits", ([
                "west" : __DIR__"beidajie1",
                "up" : __DIR__"kedian2",
        ]));
        setup();
        call_other("/clone/board/kedian_b", "???");
}
int valid_leave(object me, string dir)
{
          if (!userp(me))         return ::valid_leave(me, dir);
        if (present("xiao er",environment(me))){
        if ( !me->query_temp("rent_paid") && dir == "up" )
        return notify_fail("店小二一下挡在楼梯前，"+HIW"白眼"NOR+"一翻：怎麽着，想白住啊！\n");
        if ( me->query_temp("rent_paid") && dir == "west" )
        return notify_fail("店小二跑到门边拦住：客官已经付了银子，怎麽不住店就走了呢！
旁人还以为小店伺候不周呢！\n");
        }
        return 1;
}

