// Room: /d/shaolin/hsyuan4.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "����Ժ�Ĳ�");
    set("long", @LONG
�����Ǻ���Ժ���͵ĵط�����ǽ�����������һ��̫ʦ�Ρ�
ǽ��һ�������ż���������и�������������ˡ����ݴ�����
��׭�֣������������ڣ��ƺ��Ǹ�����²衣һλСɳ����һ
�ߴ���վ����
LONG
    );
    set("objects", ([ /* sizeof() == 2 */
  "/kungfu/class/shaolin/hui-xu" : 1,
  __DIR__"npc/xiao-tong" : 1,
]));
    set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"wuchang3",
  "south" : __DIR__"zoulang6",
  "north" : __DIR__"hsyuan5",
  "west" : __DIR__"zhulin4",
]));
    set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));
    set("no_clean_up", 0);
    setup();
    replace_program(ROOM);
}
