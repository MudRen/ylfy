// Room: hongshuiqi.c

inherit ROOM;

void create()
{
        set("short", "��ˮ��");
        set("long", @LONG
���������̵ĺ�ˮ�죬���н��ڸ�����ͨˮ�ԣ�������ʹ������
���Ķ�ˮ��������ŷ�ɥ�����Ž��湦���򶫾����ɺ�ˮ���ػ���
����ʥ��֮һ��ˮ��̶�������������������С·ͨ��һ��ɽ�ȡ�

LONG
        );
        set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/tangyang" : 1,
]));
        set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"shanlu3",
  "north" : __DIR__"liehuoqi",
  "west" : __DIR__"lianwu-chang1",
  "east" : __DIR__"shanya",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

