// Room: shanlu4.c

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
����һ���ľ���Сɽ·����֪ͨ��δ���ֻ�������ҡҷ��·����ݣ�
һҡһ�ڣ����Ǹ���ָ�㷽�򡣲���һ�ſ�¶�飬��Ө͸�����������⡣��
Χ�����㾲��ֻ�����ǽŲ�����ɳɳ���졣
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"neitang",
  "north" : __DIR__"shanlu3",
]));
        set("no_clean_up", 0);
        set("outdoors", "none");

        setup();
        replace_program(ROOM);
}

