// Room: ruijinqi.c

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
���������͸е�һ���������������ֻ�����еľ޴��¯����
�����Ȼ��棬���ܼ�������������������ı�������ˮ����¯̨��
ð���������������ǽ��е�����죬���������ޱȵĻ��ء�����
��ͭ�˶�����������ܹ��ɽ�֮�֡�

LONG
        );
        set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/wujingcao" : 1,
]));
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"jumuqi",
  "east" : __DIR__"lianwu-chang4",
]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

