//by enter xiaoya

inherit ROOM;

void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
    ������һ����ʯ�������ʯ���г����������͵���ݣ���
·����������������ż��ô�׳����������·��ʱ����Щ����
��ʿ����ȥȥ����ʱ����װ�кܶ����ӵĴ󳵾�������������
�ϱ��ǳɶ���
LONG
        );

        set("exits", ([
                "east" : __DIR__"guandao3",
                "south" : __DIR__"dadao6",
"north" : "/d/qingcheng/qcroad1",	
        ]));

        set("outdoors", "chengdu");
        setup();
        replace_program(ROOM);
}


