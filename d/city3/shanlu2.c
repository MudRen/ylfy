//by enter xiaoya

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
���Ǵ����һ�������·�������Ѿ������ˣ���Ϊ��·��
������խ����Խ��Խ�����������ѡ�����ͨ����Ҫ��ʼ����
��ɽ�ˡ�
LONG
        );

        set("exits", ([
                "northeast" : __DIR__"shanlu1",
                "westup" : __DIR__"shanlu3",
        ]));

        set("outdoors", "chengdu");
        setup();
        replace_program(ROOM);
}


