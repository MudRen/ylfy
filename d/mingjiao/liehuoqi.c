// Room: liehuoqi.c

inherit ROOM;

void create()
{
        set("short", "�һ���");
        set("long", @LONG
���������̵��һ��죬��������æ�Ű�ɽ�²ɼ����ĺ������
���������ɻ��ͣ�Ȼ��С�������װ��һ������Ͳ�С���˵�������
�����Ļ���ǹ��ֻ��ϧ���Ͳɼ����ף�����һ�㲻����ʹ�á�������
��ˮ�죬����ͨ�����䳡��

LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"hongshuiqi",
  "west" : __DIR__"lianwu-chang2",
  "east" : __DIR__"shandao0",
]));
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xinran" : 1,
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

