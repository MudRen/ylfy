// leizudian.c �����

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
������й������ۣ�����ԭ�����䣬Ϊ����ʥ�������ɵĻ䣬�ĳ�
���䡣�������������������ģ��Ƕ�ʮ�����б������޵ĺϳơ����з���
��ľ���㰸���㰸�Ϲ�Ʒ�뱸�����ʮ����ʢ�� 
LONG
        );
       
        set("exits", ([
                "southeast" : __DIR__"donglang4",
                "north" : __DIR__"donglang5",
        ]));
        set("objects", ([
                __DIR__"npc/zhangyao" : 1, 
   ]));
 
        setup();
        replace_program(ROOM);
}



