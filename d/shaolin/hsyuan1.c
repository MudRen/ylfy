// Room: /d/shaolin/hsyuan1.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "����Ժһ��");
    set("long", @LONG
�����Ǻ���Ժ���͵ĵط�����ǽ�����������һ��̫ʦ�Ρ�
ǽ��һ�������ż���������и�������������ˡ����ݴ�����
��׭�֣������������ڣ��ƺ��Ǹ�����²衣һλСɳ����һ
�ߴ���վ����
LONG
    );
    set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/xiao-tong" : 1,
  "/kungfu/class/shaolin/hui-he" : 1,
]));
    set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"zhulin1",
  "south" : __DIR__"zoulang7",
  "north" : __DIR__"hsyuan2",
  "west" : __DIR__"wuchang3",
]));
    set("no_clean_up", 0);
    setup();
    replace_program(ROOM);
}
