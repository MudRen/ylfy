// wdroad8.c ����·
// by Xiang
inherit ROOM;
void create()
{
    set("short", "����·");
    set("long", @LONG
������һ����������Ļ���·�ϣ���������ɭɭ�����֡�������һ����ɽ��
LONG
    );
        set("outdoors", "wudang");
    set("exits", ([
        "south" : __DIR__"wdroad9",
        "east" : __DIR__"wdroad7",
        "west" : __DIR__"shanmen",
    ]));
    set("objects", ([
        __DIR__"npc/yetu" : 4 ]));
    setup();
    replace_program(ROOM);
}
