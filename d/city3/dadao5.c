//by enter xiaoya

inherit ROOM;

void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
    ������ͨ��ɶ��Ĵ�������ڴ��⿿���ɶ��ǣ�����������
�˲���������Ŀ��ˡ����������ꡢ������С�����������ӡ���
�ֲ��ѡ���·���Ե��������ҡ�ڲ�����������ǳɶ��ı��š�
LONG
        );

        set("exits", ([
                "north" : __DIR__"dadao6",
                "south" : __DIR__"northchengmen",
        ]));

        set("outdoors", "chengdu");
        setup();
        replace_program(ROOM);
}


