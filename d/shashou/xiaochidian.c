// Room: /city/zuixianlou.c
// YZC 1995/12/04 
// arnzh 97/1/24

inherit ROOM;

void create()
{
	set("short", "С�Ե�");
	set("long", @LONG
���С�Ե겼�ü��ף���ֱ����һ������͸��������Ҳ�ܽ�С�Եꡣ
�˿Ͷ��ǴҴҵ����ˣ������ӡ����ȡ��׾ƾ͸�·ȥ�ˡ�
LONG
	);

	set("exits", ([
               "east" : __DIR__"fenglin2",
	]));

	set("objects", ([
"/d/city/npc/xiaoer2" : 1,
	]));

	setup();
	replace_program(ROOM);
}
