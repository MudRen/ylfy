// shijie3.c ʯ��
// by Xiang
inherit ROOM;
void create()
{
    set("short", "ʯ��");
    set("long", @LONG
������һ����ʵ��ʯ���ϣ���ʱ���н���ʹ��������߹���һ������
�ڣ�һ�������£�̧ͷ��Լ�ɼ������������е������壬������ˮ���ȣ���
���Ŀ�������������һ���Ʒ���
LONG
    );
        set("outdoors", "wudang");
    set("exits", ([
        "southdown" : __DIR__"shijie21",
        "northup" : __DIR__"bolin",
    ]));
    setup();
    replace_program(ROOM);
}
