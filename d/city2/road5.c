
inherit ROOM;
void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵġ�
���̵ġ����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡�
��ʱ����������������߷ɳ۶���������һ·��������·������
��������������֡����߾����������ˡ�
LONG
	);
	set("exits", ([
		"north" : "/d/city2/yongding",
		"southeast" : __DIR__"road6",
		"west" : "/d/xueshan/bieyuan",
	]));
	set("objects",([
		"/d/taishan/npc/seng-ren" : 1,
	]));
 	set("outdoors", "city2");
	setup();
	replace_program(ROOM);
}
