// Room: /d/heimuya/zhaoze/shimao.c
inherit ROOM;

void create()
{
        set("short", "寺庙");
        set("long", @LONG
游目四顾，只见对面平地上有一座小小寺院，庙前有一个荷塘，此时七月
将尽，高山早寒，荷叶已然凋了大半。
LONG
);
        set("exits", ([ 
  "east" : __DIR__"shiliang1",
  "enter" : __DIR__"shimao1",
]));
    set("objects", ([
        __DIR__"npc/shusheng" : 1,
    ]));

        set("outdoors", "shimao");

        setup();
}
int valid_leave(object me, string dir)
{
        object ob=present("shu sheng", environment(me));
        if (ob && living(ob) ){
            if ( ( present("hong juan",me) ) && dir == "enter" ) {
                    say("书生对"+me->name()+"喝道：请留步。\n");
                    return notify_fail("书生喝道：这位" + RANK_D->query_respect(me) + "请止步。\n");
            }
        }
        return ::valid_leave(me, dir);
}

