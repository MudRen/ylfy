// Room: shanpo1.c

inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
����ͨ��ɽ��С�ȵ�һ���������µ����µ��ɴ�����Խ��Խխ����
���������������С�

LONG
        );
        set("objects", ([ /* sizeof() == 1 */
]));
        set("outdoors", "none");
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"banshanyao1",
  "north" : __DIR__"shanpo2",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

