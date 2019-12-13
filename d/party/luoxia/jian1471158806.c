// a skeleton for user rooms
inherit ROOM;
void create()
{
set("short", "校场");
set("long", @LONG
这里是落霞的校场，在这里有一些帮内的的弟兄在研讨武艺中间是个大的平台，大雨过后夕阳照在场地上显得特别明亮平台周围种着各类奇花异草东边是帮内的主干道。

LONG
);
        set("exits", ([
"east" : "/d/party/luoxia/beidajie4.c",
]));
set("objects", ([
        "/clone/room/npc/tong-ren" : 1,
       ]) );
        set("owner", "bigtie7001");
        set("banghui", "luoxia");

setup();
}

