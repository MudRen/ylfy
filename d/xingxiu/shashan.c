// Room: /d/xingxiu/shashan.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "��ɳɽ");
	set("long", @LONG
����һ����ɳ�ѻ��γɵ�ɽ��΢�紵����ɳɽ�������˵�������
�ʶ������˳�֮Ϊ��ɳɽ��ɳ�����ƺ���һ�ֳ������䶯��
LONG
);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shachong" : 3,
]));
	set("no_new_clean_up", 0);
	set("outdoors", "xingxiuhai");
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"silk3",
  "west" : __DIR__"yueerquan",
]));

	setup();
	replace_program(ROOM);
}
