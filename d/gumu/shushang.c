// Room: shushang.c 

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIG"����"NOR);
        set("long", @LONG
һ���ȳ�֮�������������̧ͷһ������ʱë���Ȼ��һ����ڴ�ϸ�ľ�
�������������ϣ��ſ���ڣ���Ҫ����������
LONG
        );
        set("exits",([
                "down" : __DIR__"shanlu7",
        ]));

        set("objects",([
               __DIR__"npc/dumang" : 1,
"clone/misc/fengjiangping" : 1,  	
        ]));

        set("outdoors", "��Ĺ");

        setup();
}

