// Room: houtuqi.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
���������̺����졣���н��ڸ��������Բ��������������ӡ�
��ʮ��������������,�ѹ���������ü���ޱȡ�������Ľǵ����
����ľ����ˮ���һ����컥���Ӧ�������������Ρ�
LONG
        );
        set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/yanyuan" : 1,
]));
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"guangming-ding",
  "north" : __DIR__"guangchang1",
  "west" : __DIR__"lianwu-chang3",
  "east" : __DIR__"lianwu-chang1",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

