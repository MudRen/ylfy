// zhongxin.c ���Ĺ㳡
// By csy 1999.03

inherit ROOM;

void create()
{
        set("short", "���Ĺ㳡");
        set("long", @LONG
�������书������Ĺ㳡���书���Ǹ�С��ֻ���������--�ֱ���
���֣����֣��Ͻֺͱ��֣����������ϡ��ߵ����·�ϵ����˶���Щ��
�����㶼�ͺ������ع���Ϊ��
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "east" : __DIR__"dongjie",
                "west" : __DIR__"xijie",
                "north" : __DIR__"beijie",
                "south" : __DIR__"nanjie",
        ]));

        set("objects", ([
                __DIR__"npc/liumang" : 2,
        ]));

        setup();
        replace_program(ROOM);
}

