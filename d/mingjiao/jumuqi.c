// Room: jumuqi.c

inherit ROOM;

void create()
{
        set("short", "��ľ��");
        set("long", @LONG
���������̵ľ�ľ�죬ǽ�ߵ�һ��ľ���Ϸ����˿������ߣ��м�
�ѷ��Ÿտ�������ľ�ģ���ʮ������æ�Ž�ľ������ӹ�����������
�ս�׳�󣬾�ľ��縺���˲��������������������Ρ�������һ
Ƭ���Ʊ��յ����֡����������䳡��

LONG
        );
        set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/wencangsong" : 1,
]));
        set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"ruijinqi",
  "west" : __DIR__"shulin",
  "east" : __DIR__"lianwu-chang3",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

