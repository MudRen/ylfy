// wdroad6.c ����·
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
    set("exits", ([
        "northeast" : __DIR__"wdroad5",
        "west" : __DIR__"wdroad7",
    ]));
    setup();
    replace_program(ROOM);
}
