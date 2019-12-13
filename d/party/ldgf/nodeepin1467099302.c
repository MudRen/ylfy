// a skeleton for user rooms
inherit ROOM;
void create()
{
set("short", "谁与争锋");
set("long", @LONG
这是远古东方不败喝酒绣花的陋室  里面有一股淡淡的脂粉味道  洞口上方刻着四个古篆  谁与争锋  石桌上 洒落着几根金光闪闪的绣花针!

LONG
);
        set("exits", ([
"south" : "/d/party/ldgf/dating.c",
]));
set("objects", ([
        "/d/new/npc/tong-ren" : 1,
       ]) );
        set("owner", "bigtie7001");
        set("banghui", "ldgf");

setup();
}

