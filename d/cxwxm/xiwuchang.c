// Room: /d/cxwxm/xiwuchang.c
// This is a room made by roommaker. write by Xyx.

inherit ROOM;

void create()
{
        set("short", "��ɽϰ�䳡");
        set("long", @LONG
��һ��ɽ�������������Ȼ�ǳ��������ŵ�ϰ�䳡���ڳ�����ڷ���
һ���ŵ�ľ�ˡ��ѹִ����Ǳ߷ǳ�������ԭ��������ȫ�����������䣬��
�ǵĺ�����������ɽ���лص��ţ�

LONG
);
        set("exits", ([ /* sizeof() == 1 */
  "westdown" : __DIR__"cxwx2",
]));
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/kuang" : 2,
]));
        set("outdoors", "cxwxm");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
