// shijie2.c ����
// by Xiang
// by arnzh 97/1/23
inherit ROOM;
void create()
{
    set("short", "����");
    set("long", @LONG
������һ����ʵ��ʯ���ϣ���Χ�������ԲԵİ��֣�����������������
����������徲����࣬ż���н�����߹���һ�����ͱڣ�һ�������£�̧
ͷ��Լ�ɼ������������е������壬������ˮ���ȣ������Ŀ�������
LONG
    );
        set("outdoors", "wudang");
    set("exits", ([
        "southdown" : __DIR__"shijie22",
        "northup" : __DIR__"shijie31",
    ]));
        set("objects", ([
                CLASS_D("wudang") + "/famu" : 1,
                __DIR__"npc/monkey" : 1]));
        setup();
    replace_program(ROOM);
}
