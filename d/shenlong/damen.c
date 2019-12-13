#include <ansi.h>
inherit ROOM;
string* npcs = ({
    "/d/shenlong/npc/boy",
    "/d/shenlong/npc/boy2",
    "/d/shenlong/npc/boy3",
    "/d/shenlong/npc/boy4",
    "/d/shenlong/npc/girl",
    "/d/shenlong/npc/boy",
    "/d/shenlong/npc/boy2",
    "/d/shenlong/npc/boy3",
    "/d/shenlong/npc/boy4",
    "/d/shenlong/npc/girl",
    "/d/shenlong/npc/girl",
});
void create()
{
    set("short", "����");
    set("long", @LONG
���Ǽ�ܴ�����ݡ�����վ�ż����������.��ס������������
����,������Զ,ȴҲ�������õ�����������������֮��.
LONG
    );
    set("exits", ([
        "south" : __DIR__"road2",
        "north" : __DIR__"dating",
    ]));
    set("objects", ([
        npcs[random(sizeof(npcs))] : 1,
        npcs[random(sizeof(npcs))] : 1,
        npcs[random(sizeof(npcs))] : 1,
        npcs[random(sizeof(npcs))] : 1,
                "/d/shenlong/npc/old": 2,
        npcs[random(sizeof(npcs))] : 1,
    ]));
    set("outdoors", "shenlong");
    setup();
   replace_program(ROOM); 
}
