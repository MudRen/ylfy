//by enter xiaoya

inherit ROOM;

void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
    �������ǳɶ��ؽ��ˡ�һ����ʯ���̳ɵ�·���ȽϿ���
��·�����ֵ������������������΢�紵��ɳɳ���졣����
��������ɶ��ǣ����������˵�Ҳ���١�������ȥ������Լ
�����ɶ�����ΰ�ĳ�ǽ��
LONG
        );

        set("exits", ([
                "north" : __DIR__"dadao7",
                "south" : __DIR__"dadao5",
        ]));

        set("outdoors", "chengdu");
        setup();
        replace_program(ROOM);
}


