// Room: lianwu-chang1.c

inherit ROOM;

void create()
{
        set("short", "���䳡");
        set("long", @LONG
�������̵����䳡��������޴�Ļ������̵���ɡ�����ӿ���
������������ӡ���ɼ����е����ù�֮�������аڷ�������������
���ܹ��ɽ��Ǿ�������������ͭ�ˡ����۰����ҹ�����ɼ���ʮ����
�������ڴ˿����似��������Ǻ�ˮ�졣
LONG
        );
        set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/tongren" : 1,
]));
        set("outdoors", "none");
        set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"lianwu-chang2",
  "west" : __DIR__"houtuqi",
  "east" : __DIR__"hongshuiqi",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

