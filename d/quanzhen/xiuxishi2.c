// Room: xiuxishi.c

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "��Ϣ��");
        set("long", @LONG
���Ǽ�������᷿�����Ŵ������ţ����ߺܻ谵������������
ֻ���м����һ����ʰ����������Ĵ󴲣����ž�������˯����
LONG
        );

        set("sleep_room", 1);
        set("no_fight", 1);
          
        set("exits", ([
            "west": __DIR__"donglang3",    
        ]));
        
        setup();
        replace_program(ROOM);
     
}
