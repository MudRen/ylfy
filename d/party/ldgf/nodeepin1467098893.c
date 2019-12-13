// a skeleton for user rooms
inherit ROOM;
void create()
{
set("short", "曾经拥有");
set("long", @LONG
这是远古独孤求败增长江湖经验的陋室  里面有一股淡淡的江湖味道  洞口上方刻着四个古篆  曾经拥有  洞内虽然有着广阔的空间 小桥 流水 绿树 石凳  但是依然遮不住无限的寂寞孤独

LONG
);
        set("exits", ([
"west" : "/d/party/ldgf/beidajie3.c",
]));
set("objects", ([
        "/d/new/npc/tong-ren" : 1,
       ]) );
        set("owner", "bigtie7001");
        set("banghui", "ldgf");

setup();
}

