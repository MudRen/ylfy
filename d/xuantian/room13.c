// xuantian  by:pipip
inherit ROOM;
string* npcs = ({
        __DIR__"npc/shou",

});

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
���߽���ƹ�谵��ʯͷС������ܴ���Щ��ֵĺ�����
LONG
        );
        set("exits", ([
              "east" : "d/xuantian/room7",
              "north" : "d/xuantian/room6",
              "south" : "d/xuantian/room2",
              "west" : "d/xuantian/room14",
        ]));
        set("objects", ([
                npcs[random(sizeof(npcs))] : 2,

        ]));
    

        setup();
}
void init()
{
    this_player()->receive_damage("qi", 35);
    this_player()->receive_wound("qi",  35); 
    this_player()->apply_condition("fire_poison", 300);    message_vision(RED"$Nֻ���ÿ���Խ��Խ�ȣ�����Խ��Խ�ѡ�\n"NOR, this_player());
}

int valid_leave(object me, string dir)
{
        if (  (dir != "up")
           && ((string)me->query("family/master_id") != "wuming laoren")
           && objectp(present("shou", environment(me))) )
         return notify_fail
               ("��ֻ����Ѹ�ٵİ�Χ���㣬���ʱ�����ս�У���\n");
        return ::valid_leave(me, dir);
}

