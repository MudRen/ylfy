// Room: shulin10.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һƬټ������֣���ľ���죬���Ʊ��ա����������ʧ�˷���
��֪�������Լ����ںδ������в�ʱ����Ұ�޹���ĵͺ��Х��,���㲻
��ë���Ȼ��ֻ������뿪��

LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"shulin8",
  "west" : __DIR__"shulin11",
  "south" : __DIR__"shulin9",
  "east" : __DIR__"shulin10",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

