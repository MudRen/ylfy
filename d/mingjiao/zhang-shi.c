// Room: zhang-shi.c

inherit ROOM;

void create()
{
        set("short", "С����");
        set("long", @LONG
һ���������Ҳ������С�ķ��䣬�����Ͱ͵������������
һ����С�ݸɵ���ͷŭ������վ����������ӣ����۾�����
��һ��һ�ϣ���ĭ����ɣ�Ҳ��֪��Ϊ��������
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"niushi",
  "east" : __DIR__"luzhou",
]));
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhywai" : 1,
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

