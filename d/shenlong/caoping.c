#include <ansi.h>
inherit ROOM;
string* flowers = ({
    "/d/shenlong/obj/hua",
    "/d/shenlong/obj/hua",
    "/d/shenlong/obj/hua2",
    "/d/shenlong/obj/hua3",
    "/d/shenlong/obj/hua4",
    "/d/shenlong/obj/hua2",
    "/d/shenlong/obj/hua3",
    "/d/shenlong/obj/hua4",
});
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
    set("short", "��ƺ");
    set("long", @LONG
������һƬ����Ĳ�ƺ,�м�����������ˣ.���ܿ����˸�ɫ��
�ʻ�,һ�����紵��,���µĿ����д������Ƶ����Ļ���.
LONG
    );
    set("exits", ([
        "east" : __DIR__"kongdi",
    ]));
    set("objects", ([
        npcs[random(sizeof(npcs))] : 1,
        npcs[random(sizeof(npcs))] : 1,
        npcs[random(sizeof(npcs))] : 1,
        npcs[random(sizeof(npcs))] : 1,
        flowers[random(sizeof(flowers))] : 1,
        flowers[random(sizeof(flowers))] : 1,
        flowers[random(sizeof(flowers))] : 1,
    ]));
    set("outdoors", "shenlong");
    setup();
}

void init()
{

    if (objectp(present("duanchang", this_object()))) 
        if((int)this_player()->query_condition("flower_poison") < 10 ) {
        this_player()->apply_condition("flower_poison", 30);
        tell_object(this_object(), HIG "��ֻ��һ�ɵ���Ϯ��,��ʱ����һ����ľ��\n" NOR );
    }
}
int valid_leave(object me, string dir)
{
    if (objectp(present("duanchang", environment(me)))) 
    {
        if((int)me->query_condition("flower_poison") < 10 ) {
        me->apply_condition("flower_poison", 30);
        tell_object(me, HIG "��ֻ��һ�ɵ���Ϯ��,��ʱ����һ����ľ��\n" NOR );
    }
    }
    return ::valid_leave(me, dir);
}
