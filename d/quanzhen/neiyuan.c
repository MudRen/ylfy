// neiyuan.c ��԰

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "��԰");
        set("long", @LONG
ӭ����һ�����ɽ����ʯ�������ѵ����ˣ�������죬ʯ������Ż��ʯ
�񡢰�Ƥ�ɵ�ֲ���ɽ�����������ԣ��޻����ͣ����������������ľ���԰��
���м����᷿,������ͯ�ֽ�վ�����⡣
LONG
        );
        set("outdoors", "quanzhen");

        set("exits", ([
                "northwest" : __DIR__"yunjiyuan",
                "west" : __DIR__"xiangfang1",
                "east" : __DIR__"xiangfang2",
                "south" : __DIR__"waishi",
        ]));
        setup();
        
}

/*
int valid_leave(object me, string dir)
{
        int skill;

        skill = me->query_skill("taoism", 1);
        if (!wizardp(me) && skill < 80)
        {
                if (dir == "south" )
                {
                        return notify_fail("\n");
                }
        }
        return ::valid_leave(me, dir);
}
*/
