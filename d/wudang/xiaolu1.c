// xiaolu1.c �ּ�С��
// by Xiang
inherit ROOM;
void create()
{
    set("short", "�ּ�С��");
    set("long", @LONG
������һ��С���ϣ��������������ӣ�����ɭɭ���������أ�������Ҷ
��������������������Ķ�����
LONG
    );
    set("exits", ([
        "north" : __DIR__"xiaolu2",
        "south" : __DIR__"zijincheng",
    ]));
    setup();
    replace_program(ROOM);
}
