// guangchang.c �㳡
// by kyd

#include <ansi.h> 
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "ȫ��̹㳡");
        set("long", @LONG
����һ���ɴ�ʯ���̳ɵĹ㳡����Χ��������ͩ����һ�����������
�ص���Ҷ�������������ĵ�ͯ���ڴ�ɨ����������������ʵ
LONG
        );
        set("outdoors", "quanzhen");

        set("exits", ([
                "southdown" : __DIR__"tyroad2",
                "north" : __DIR__"yuhuangdian",
                "west" : __DIR__"lwc1",
                "east" : __DIR__"bwc",
        ]));
        
        set("objects", ([
"/d/quanzhen/npc/zhaozhijing" : 1]));
        
        setup();
//        replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "ȫ���") && dir == "north" &&                 objectp(present("master zhao", environment(me))))
     return notify_fail(HIW"\n ��־���ȵ����㲻��ȫ����ӣ�Ҫ���ȥ��ʤ�������г���! \n\n"NOR);
                
        return ::valid_leave(me, dir);
}


