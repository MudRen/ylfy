//by enter xiaoya

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
����һ����������ʯ�ֵ������ϱ���ͷ���졣�����Ǳ�
����ͨ����⡣�ϱ��Եúܷ������֡�������һ�������¥
�󣬹��š������Ŷ��������������Ŷ�������һ�����ҡ���
��Ϊֹ�����ֲ����������������ǳ������Ϲ�--�������ֱʡ�
����������ζ�˱Ƕ���,���㴹�����Ρ�������һ�����ӵ���
�ã�������ƣ��������ﲻ��,�Ǿ��Ǵ�������ͬ���������
�������Ϸ��и��续��С̶��
LONG
        );

        set("exits", ([
                "north" : __DIR__"northchengmen",
                "south" : __DIR__"beijie2",
                "west" : __DIR__"wuhou",
                "east" : __DIR__"chenmapo",
                "southwest" : __DIR__"huanhuaxi2",
        ]));

        set("outdoors", "chengdu");
        setup();
        replace_program(ROOM);
}


