// Room: /d/heimuya/zhaoze/shimao1.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������С�����ȴ������߹�һ����ʯ�̵�С�����ִ���һ����
�֣�ֻ������ɭɭ���ľ��ޱȣ����˷��׾�������������������ʯ�ݡ�
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"shimao2",
  "out" : __DIR__"shimao",
]));

	setup();
	replace_program(ROOM);
}
