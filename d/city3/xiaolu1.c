//modified by wind

inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
�������˶��������С·�ϣ�ż���������������
�Ҷ������������ĳ�����������ͨ�����ɽ��������
�ǽ����츮֮��֮�׸��ɶ��Ĵ����
LONG
        );

        set("exits", ([
                "west" : __DIR__"xiaolu2",
                "north" : "/d/changan/ca34",
//                "northeast" : "/d/emei/xiaolu2",
        ]));

        set("outdoors", "chengdu");
        setup();
        replace_program(ROOM);
}


