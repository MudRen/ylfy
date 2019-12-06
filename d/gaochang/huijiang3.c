// Room: /d/xingxiu/xxroad7.c
inherit ROOM;
void create()
{
        set("short", "南疆小镇");
        set("long", @LONG
从草原上南下, 便接近南疆沙漠了。这儿气候逐渐干燥, 热浪时而从沙
漠里涌来。沙漠里还走来骆驼商队, 在这儿休息和分发货物。于是商铺林立,
人来人往，十分热闹。西面是一小院。
LONG
        );
        set("exits", ([
            "northup" : __DIR__"huijiang2",
            "west" : __DIR__"huijiang4",
            "northeast" : __DIR__"huijiang5",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");
        setup();
        replace_program(ROOM);
}
