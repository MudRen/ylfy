//shandong.c
//by mei

inherit ROOM;
void create()
{
        set("short", "ɽ��");
        set("long", @LONG
��׳���ӣ��߽���ɽ���У����ﰵ�����գ�ͻȻ�䣬��
ֻ����������ǰ�ɹ����㱻������һ���亹��Խ�����߾�Խ��
Խ�ڣ��������ʧ�����ˡ�
LONG
        );
        set("exits", ([
                "north" : __DIR__"shandong"+random(8),
                "south" : __DIR__"shandong"+random(8),
                "east" : __DIR__"shandong"+random(8),
                "west" : __DIR__"shandong"+random(8),
        ]));
        setup();
}
void reset()
{
        ::reset();
        set("exits", ([
                "north" : __DIR__"shandong"+random(8),
                "south" : __DIR__"shandong"+random(8),
                "east" : __DIR__"shandong"+random(8),
                "west" : __DIR__"shandong"+random(8),
        ]));
}


