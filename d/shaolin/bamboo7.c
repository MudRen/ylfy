// Room: /d/shaolin/bamboo7.c
// Date: YZC 96/01/19
inherit ROOM;
void create()
{
    set("short", "����");
    set("long", @LONG
����һƬ���ܵ����֡������˼�������Ω�����ߵ��·�棬��ɮ
��ľ������΢�紵����Ҷ�������������������˳���Ϊ֮һ�ӣ�
���Ǿ��ѵ��������ڡ�
LONG
    );
    set("exits", ([
        "east" : __DIR__"bamboo"+(random(13)+1),
        "west" : __DIR__"bamboo8",
        "south" : __DIR__"bamboo"+(random(13)+1),
        "north" : __DIR__"bamboo"+(random(13)+1),
    ]));
    set("outdoors", "shaolin");
    setup();
}
int valid_leave(object me, string dir)
{
    if (dir == "west" ) me->add_temp("bamboo/count", 1);
    else             me->add_temp("bamboo/count", -1);
    return ::valid_leave(me, dir);
}