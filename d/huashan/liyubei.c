// Room: /inherit/room/liyubei.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "���㼹");
	set("long", @LONG
���ǻ�ɽ�������յء����㼹����ֻ��һ����Լ��ʮ���ɣ�������ߵ�С��
ֱ��Է壬���Խ����������ƣ�����׵�Ͽ�ȣ�紵����ʹ��ƮƮ������
�ָ���ƽʱҲ����ð��Խ���˴���
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : "/d/huashan/laojun",
  "northup" : __DIR__"houzhiwangyu.c",
]));
	set("���㼹", "short");

	setup();
	replace_program(ROOM);
}
