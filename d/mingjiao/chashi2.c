// Room: chashi2.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
һ��������Ϳ����ŵ�һ�ɲ�Ҷ�����㣬ǽ���и���ˮ��С¯��
�����ˮ���Ѿ���ʼ���⡰˻˻����ðˮ���ˡ������ϵ�����������
�ط��ż�����Ư���ĵ񻨲��ѡ�������������

LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"tingtang",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

