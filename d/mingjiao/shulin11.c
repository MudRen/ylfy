// Room: shulin11.c

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
  "north" : __DIR__"shulin3",
  "west" : __DIR__"shulin5",
  "south" : __DIR__"shulin12",
  "east" : __DIR__"shulin10",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
