// wdroad1.c
// by Xiang
inherit ROOM;
void create()
{
    set("short", "��ʯ���");
    set("long", @LONG
������һ����ʯ����ϣ����������ǳ���æ����ʱ������������ҴҶ�����
���������һЩС��̯���ƺ���һ�����С�����ͨ�����ݳǡ�
LONG
    );
        set("outdoors", "wudang");
    set("exits", ([
        "south" : __DIR__"wdroad2",
        "north" : "/d/city/nanmen",
    ]));
    setup();
    replace_program(ROOM);
}
