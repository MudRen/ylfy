// Room: /d/kunlun/mw.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "Сɽ��");
	set("long", @LONG
������ʥ��ɽ���һ��Сɽ�ȣ������˼����������й��ɲ��죬��ѩ
������ż����Զ����������ѩ�������䡣������һé�ݴ�ɵ�ɽͤ��ͤ��
��һ����С����һλ�׷��Բ�������������������ڼ�ǰ���١�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"ssy",
]));
	set("objects", ([ /* sizeof() == 1 */
  "/kungfu/class/kunlun/hezuodao" : 1,
]));

        set("no_magic",1);
	setup();
	replace_program(ROOM);
}
