// Room: /d/city3/zhubaodian.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "�鱦��");
	set("long", @LONG
�������ȫ�������ġ�л���롱�鱦�ꡣл�����鱦��һ
���Ѿ������ϰ������ʷ������ѡ���ϳˣ��������ɣ�������
���Ϊ��ٹ�������������Ϊ�����������С�л���롱�鱦
����һ����ݵ��������ſڹҵ�������Ȼ��Щ���ˣ�ȴ��ʾ��
����ʷ���ƾá�������һ��С�ݣ���л�ҵ���ʮ��������л��
��ƽ�չ����ĵط���
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"xiaowu",
  "east" : __DIR__"beijie2",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/yunyan" : 1,
  __DIR__"npc/huoji" : 1,
]));

	setup();
	replace_program(ROOM);
}
