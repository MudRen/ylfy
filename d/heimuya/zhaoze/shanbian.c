// Room: /d/heimuya/zhaoze/shanbian.c
inherit ROOM;

void create()
{
        set("short", "山边");
        set("long", @LONG
忽听得彩虹后传出一阵歌声。
    只听他唱的是个“山坡羊”的曲儿：
        城池俱坏，英雄安在？
        云龙几度相交代？
        想兴衰，苦为怀。
        唐家才起隋家败，世态有如云变改。
        疾，也是天地差！迟，也是天地差！
LONG
);
        set("exits", ([ 
  "north" : __DIR__"shanbian1",
  "west" : __DIR__"penquan",
]));
    set("objects", ([
        __DIR__"npc/jiaozi" : 1,
    ]));

        set("outdoors", "shanbian");

        setup();
}
int valid_leave(object me, string dir)
{
        object ob=present("jiao zi", environment(me));
        if (ob && living(ob) ){
            if ( ( present("hong juan",me) ) && dir == "north" ) {
                    say("樵子对"+me->name()+"喝道：请留步。\n");
                    return notify_fail("樵子喝道：这位" + RANK_D->query_respect(me) + "请止步。\n");
            }
        }
        return ::valid_leave(me, dir);
}

