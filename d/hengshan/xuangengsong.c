// xuangengsong.c

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
���ڻ�����������յأ�ȴ��һ����ɣ��䱻��紵��������¶��
ǧ��������ӭ��ͦ��������Ǻ�ɽ�����ġ�����������
LONG);
	set("exits", ([ /* sizeof() == 4 */
		"east"      : __DIR__"hufengkou",
	]));
set_temp("wayao1",2);
	set("outdoors", "hengshan");
	set("coor/x", 10);
	set("coor/y", 3150);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}
