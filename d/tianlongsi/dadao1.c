inherit ROOM;
void create()
{
    set("short", "��ʯ���");
    set("long", @LONG
������һ����ʯ����ϣ����������ǳ���æ����ʱ������������ҴҶ�����
���������һЩС��̯���ƺ���һ�����С��������ͨ��������ǡ�������
LONG
    );
        set("outdoors", "tianlongsi");
    set("exits", ([
        "east" : "/d/heimuya/zhaoze/zbdd",
        "south" : __DIR__"dadao2",
    ]));
    setup();
    replace_program(ROOM);
}
