//by enter xiaoya

inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
�������˶��������С·�ϣ�ż��������������Ҵ�
�������������ĳ�����������ͨ�����ݳǣ����������
�Ĵ��Ĵ����
LONG
        );

        set("exits", ([
                "east" : __DIR__"xiaolu1",
                "west" : __DIR__"yidao4",
        ]));

        set("outdoors", "chengdu");
        setup();
        replace_program(ROOM);
}


