// Room: /d/taishan/yidao1.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵ�
���̣����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡�
��ʱ����������������߷ɳ۶���������һ·���������ϵ���
�������ž�װ���¼��������еĻ���������ŵ�������������Щ
Щϰ��Ľ����ˡ���·��������������������֡�
LONG
);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"yidao2",
  "west" : __DIR__"yidao",
  "southeast" : "/d/quanzhou/qzroad1",
]));
	set("objects", ([ /* sizeof() == 3 */
  "/d/city2/npc/xiaoguiz" : 1,
  "/d/city2/npc/hai" : 1,
  __DIR__"npc/tangzi" : 2,
]));
	set("channel_id", "�����");
	set("outdoors", "taishan");

	setup();
	replace_program(ROOM);
}
