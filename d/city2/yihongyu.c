// Room: /d/city2/yihongyu.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "����Ժ");
	set("long", @LONG
��һ�߽�����һ�۾Ϳ���������ǽ�Ϲ���һ��������ͼ(tu)��һ���Ӿ�
����������ʲô�ط������ڵ����ŵƽ�ʣ������˱ǡ�����������������
��Ů�˷�վ���Զ��㷢����Ц��һ���������æ��ǰ�к����ˡ���¥�ϴ���
������������ε�������
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/laobaopo" : 1,
]));
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"dongcha2",
]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
