//bye enter

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "����¥");
        set("long",@LONG
�����������������¥�ˣ�¥���ǳɶ��ĸ��Ϻӡ����治
���԰�����һƬ���֣������пھ�����Ѧ�ξ�����һ����Ů
����֮�ء�¥����Ұ��������Զ�����ٳǡ�
LONG
        );

        set("exits", ([
                "north" : __DIR__"funanhe3",
                "up" : __DIR__"wangjianglou2",
                "east" : __DIR__"wanliqiao",
            ]));
        setup();
        replace_program(ROOM);       
}


