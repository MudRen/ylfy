// gmmishi1.c By csy 98/12
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{ 
       set("short",HIB"ʯ��"NOR);
       set("long", @LONG
��Ĺ��������ʯ�ң�ֻ����ԶԶ������Ų��Ļ������յ����ĸо�ʹ����
��ֻ�п־壬�������ǹ¶����㲻֪���εأ�����������һƬ��ֻ�ܿ���
��ǰ�С�
LONG
     );
    
        set("exits", ([
                "east" : __DIR__"gmls",
                "west" : __DIR__"ss4",
        ]));

        setup();
}
