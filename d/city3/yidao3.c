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
                "northeast" : __DIR__"yidao4",
                "southwest" : __DIR__"shanlu1",
        ]));

        set("outdoors", "chengdu");
        setup();
        replace_program(ROOM);
}


