//LUCAS 2000-6-18
// Room: muwu.c

#include <room.h>

inherit ROOM;
void create()
{
        set("short", "木屋");
        set("long", @LONG
这是凌霄城弟子在城外巡逻护山的哨所，每天都有雪山弟子
守卫，以保护凌霄城安全清净。不过，凭凌霄城在武林中的名头,
一般宵小之辈也不敢来此捣乱
LONG );
        set("no_fight", "1");
        set("no_steal", "1");
        set("no_sleep_room", "1");

        set("objects", ([
                __DIR__"npc/wang" : 1,
        ]));

        set("exits", ([
                "west" : __DIR__"sroad6",
        ]));
        create_door("west", "木门", "east", DOOR_CLOSED);
        set("no_clean_up", 0);
        setup();
} 

