//by enter xiaoya

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
����ͨ�������һ�������·�����˴Ҵң��ƺ�����æ�Ÿ�·��
����·ɫ�������������ڲ�ȥ���·�糾���͡�
LONG
        );

        set("exits", ([
                "east" : __DIR__"xiaolu2",
                "southwest" : __DIR__"yidao3",
        ]));

        set("outdoors", "chengdu");
        setup();
        replace_program(ROOM);
}


