inherit ROOM;
void create()
{
          set("short", "后花园");
        set("long", @LONG
这里是通吃帮的后花园，花园中种着来自天下各地的名花
如：白牡丹,菊花，紫蓝香等等,花丛中站着一位美丽的少女，
在众花的衬托下,散发出一种清新脱俗的气质。
LONG
        );
        set("exits", ([
                   "south" : __DIR__"xiefj",
        ]));
        set("objects", ([
       __DIR__"npc/hanling" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
