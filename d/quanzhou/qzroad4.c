// Room: /d/quanzhou/qzroad4.c
// Date: May 7, 96   Jay
inherit ROOM;
void create()
{
    set("short", "ɽ·");
    set("long", @LONG
������һ��ɽ·�ϡ�ʱֵ���գ�·�Ե�ɽ���Ͽ����˽��ɫ���Ͳ˻���
�����ǽ������Ǽ��ˡ���������븣������ɽ����
LONG
    );
    set("exits", ([
                "north" : __DIR__"jxnanmen",
                "west" : __DIR__"qzroad3",
        "south" : __DIR__"qzroad5",
    ]));
    set("outdoors", "quanzhou");
    setup();
    replace_program(ROOM);
}
