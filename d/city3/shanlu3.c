//by enter xiaoya

inherit ROOM;

void create()
{
        set("short", "���ɽ");
        set("long", @LONG
����һ��ͨ���ɶ��ıؾ�ɽ·��������ľ�����дУ���ʱ����
�������˵�ɽȪ����ż��·�Ի�ܳ�һ��ֻС����������ɫ������
��,������¶���ϡ�����ʯ,ʹ��ٲ�ά�衣
LONG
        );

        set("exits", ([
                "eastdown" : __DIR__"shanlu2",
                "westdown" : __DIR__"shanlu4",
        ]));

        set("outdoors", "chengdu");
        setup();
        replace_program(ROOM);
}


