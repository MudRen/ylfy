// Room: /d/quanzhou/yanyu.c
// Date: May 23, 96   Jay
inherit ROOM;
void create()
{
    set("short", "����¥");
    set("long", @LONG
����¥�����Ϻ����ĵ�һ��С���ϡ��Ϻ����겻�ϵ�ˮ������
���ֵ��������ɵġ�¥���Ǽҷ��ꡣ
LONG
    );
    set("exits", ([
                "up" : __DIR__"yanyu",
                "north" : __DIR__ "nanhu1",
    ]));
    set("outdoors", "quanzhou");
        set("objects", ([
            __DIR__"npc/xiaoer" : 1]));
    setup();
}
int valid_leave(object me, string dir)
{
    if (dir=="up")
    return notify_fail("��������װ��¥�ݡ�������¥��\n");
    return 1;
}
