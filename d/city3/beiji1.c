//by enter xiaoya

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
����һ����������ʯ�ֵ������ϱ���ͷ���졣�����Ǳ�����ͨ����⡣
�ϱ��Եúܷ������֡�������һ�������¥�󣬹��š������Ŷ�����
���������Ŷ�������һ�����ң����鵽Ϊֹ�����ֲ���������������
�ǳ������Ϲ�--�������ֱʡ�����������ζ�˱Ƕ���,���㴹�����Ρ�
������һ�����ӵ����ã�������ƣ��������ﲻ��,�Ǿ��Ǵ�������
ͬ�������������
LONG
        );

        set("exits", ([
                "north" : __DIR__"beimen",
                "south" : __DIR__"beidajie2",
                "west" : __DIR__"wuhou",
                "east" : __DIR__"chenmapo",
        ]));

        set("outdoors", "chengdu");
        setup();
        replace_program(ROOM);
}


