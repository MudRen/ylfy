// Room: lianwu-chang2.c

inherit ROOM;

void create()
{
        set("short", "���䳡");
        set("long", @LONG
�������̵����䳡��������޴�Ļ������̵���ɡ�����ӿ���
������������ӡ���ɼ����е����ù�֮�������аڷ�������������
���ܹ��ɽ��Ǿ�������������ͭ�ˡ����۰����ҹ�����ɼ���ʮ����
�������ڴ˿����似����������һ��졣
LONG
        );
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tongren2" : 1,
]));
        set("outdoors", "none");
        set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"guangchang1",
  "south" : __DIR__"lianwu-chang1",
  "east" : __DIR__"liehuoqi",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

