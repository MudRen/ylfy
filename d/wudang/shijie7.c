// shijie1.c ʯ��
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
        "east" : __DIR__"guangchang",
        "northup" : __DIR__"taiziyan",
    ]));
    setup();
    replace_program(ROOM);
}
