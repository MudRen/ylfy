// Room: /d/city2/duchang.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "�ĳ�");
	set("long", @LONG
�����Ƕĳ��Ĵ��ã����ܵķ����ﴫ����ߺ������ĶĲ�����
�����Ƕġ���С���ķ��䣬ǽ�Ϲ���һ������(paizi)��¥�Ͽ���
����. һ���ţ�ֻ�������������ӣ�ʮ�ֻ��ҡ���һ��Χ��һȺ�ˣ�
����һ��һ������ͷ��ʮ�����ۡ�һ���Ͻл��������Ƕĵ��𾢡�
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/wuliuqi" : 1,
]));
	set("no_new_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"xidan1",
  "up" : __DIR__"duchang2",
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "��¥�Ĺ�������ʹ�ã�Ϊʲôû������?
",
]));
	setup();
	replace_program(ROOM);
}
