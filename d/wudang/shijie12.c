// shijie2.c ʯ��
// by Xiang
inherit ROOM;
void create()
{
    set("short", "ʯ��");
    set("long", @LONG
������һ����ʵ��ʯ���ϣ���ʱ���н���ʹ��������߹���һ������
�ڣ�һ�������£�̧ͷ��Լ�ɼ������������е������壬������ˮ���ȣ���
���Ŀ�������
LONG
    );
        set("outdoors", "wudang");
    set("exits", ([
        "southdown" : __DIR__"shijie11",
        "northup" : __DIR__"yuzheng",
    ]));
        set("objects", ([
                __DIR__"npc/guest" : 1]));
    setup();
    replace_program(ROOM);
}
