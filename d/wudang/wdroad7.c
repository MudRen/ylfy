// wdroad7.c ����·
// by Xiang
inherit ROOM;
void create()
{
    set("short", "����·");
    set("long", @LONG
������һ����������Ļ���·�ϣ���������ɭɭ�����֡������Ǻ������磬
��˵���������˳�û�����ɾ�����
LONG
    );
        set("outdoors", "wudang");
    set("no_sleep_room",1);
    set("exits", ([
        "east" : __DIR__"wdroad6",
        "west" : __DIR__"wdroad8",
        "southup" : __DIR__"tufeiwo1",
    ]));
    setup();
    replace_program(ROOM);
}
