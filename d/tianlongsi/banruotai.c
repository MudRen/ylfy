inherit ROOM;
void create()
{
        set("short", "����̨");
        set("long",@LONG
���Ǹ���ͨ��ʯ̨���ഫ������������ٴ�̨������������ȥ���Ǳ�
���صء���Ĳ���á������д��������µ�����֮�������������׾Ͳ���
���У�����ǧ��Ҫ��ʲô���⡣
LONG
        );
        set("exits", ([
                "south" : __DIR__"munitang",
        "north" : __DIR__"doushuai",
    ]));
        setup();
        replace_program(ROOM);
}
