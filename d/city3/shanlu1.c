//by enter xiaoya

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
����ͨ�������һ����᫵�ɽ·��·�����˴Ҵң��ƺ���
��æ�Ÿ�·����·Խ���������죬��Խ�����˾����������ѡ�
LONG
        );

        set("exits", ([
                "northeast" : __DIR__"yidao3",
                "southwest" : __DIR__"shanlu2",
        ]));

        set("outdoors", "chengdu");
        setup();
        replace_program(ROOM);
}


