// Room: /d/wudie/wdt.c
// This is a room made by roommaker. write by Xyx.

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
�߽���һ����������ʲô��ɫ���ƣ�ԭ���������ڷɵĲʵ�����
�ģ��ڵģ��Ƶ�......ʲô��ɫ���С�԰����һʯ�������Ͽ���һ��ʫ��
        ɽ����ˮ�����أ����ȺȺ����С�
            ң�Ӳ������˼䣬ȷ��������԰�㡣
LONG
);
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yadie" : 1,
]));
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"pxt",
  "north" : __DIR__"pjt",
  "east" : __DIR__"ydt",
  "west" : __DIR__"cdt",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
