// Room: /d/quanzhou/zhongxin.c
// Date: May 7, 96   Jay
inherit ROOM;
void create()
{
    set("short", "������");
    set("long", @LONG
Ȫ����һ�������ĸ۳ǡ���Ȼ�����ǳ����ģ�����Ҳֻ�ǽŲ������
����������������������һ���ۿڣ���������Գ�����������һ��С�
LONG
    );
    set("exits", ([
                "north" : __DIR__"beimen",
                "south" : __DIR__"nanmen",
                "east" : __DIR__"haigang",
                "west" : __DIR__"xijie",
    ]));
        set("objects",([
        __DIR__"npc/youxun" : 1,
        ]));
    set("outdoors", "quanzhou");
    setup();
}
