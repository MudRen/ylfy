// xiaolu4.c С��
// by arnzh
inherit ROOM;
void create()
{
    set("short", "С��");
    set("long", @LONG
������һ��С���ϣ������ǹ�ͺͺ��ɽ�ڣ�������������һ˿������
LONG
    );
    set("exits", ([
        "west" : __DIR__"xiaochidian",
        "east" : __DIR__"shiliang",
    ]));
    setup();
    replace_program(ROOM);
}
