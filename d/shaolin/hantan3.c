// Room: /d/shaolin/hantan3.c
#include <room.h>
inherit ROOM;
void create()
{
    set("short", "��ź�̶");
    set("long", @LONG
���Ǻ�̶֮�С�����ˮ�����һ��ʹ����̶ˮ�ڴ˴����
��ϡ��һ�������ܵı���������һ����飬����˫������͸����
�������⣬ȫ��������Ѷ������ã�ֻ������ˮ�������������
��ȥ��
LONG
    );
set("objects", ([	
   "/d/npc/saveme" : 1,     	
    ]));	
    setup();
    //replace_program(ROOM);
}
