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
        "west" : "d/dali/dongdajie3",
        "east" : __DIR__"dadao2",
    ]));
    setup();
    replace_program(ROOM);
}
