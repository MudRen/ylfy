// Room: /d/city/zuixianlou.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "����¥");
	set("long", @LONG
	��Բ����������������¥����˵�����˲�֪�����˲�����������ѧʿ��
�ε��ˣ�������¥�Ļ�����޲����ڣ���ȻΪ�����ң�����һ�δ��麣�ڵļѻ���
�Ӵ�����¥��������¥�²��ü��ף��˿Ͷ��ǴҴҵ����ˣ������ӡ����ȡ�
�׾ƾ͸�·ȥ�ˡ�¥����������
LONG
	);
	set("no_new_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"beidajie2",
  "up" : __DIR__"zuixianlou2",
  "east" : "/d/wizard/fightroom5",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiaoer2" : 1,
]));
	setup();
	replace_program(ROOM);
}
