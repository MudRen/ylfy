
inherit ROOM;
void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵġ�
���̵ģ����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡�
��ʱ����������������߷ɳ۶���������һ·��������·������
��������������֡�
LONG
	);
	set("exits", ([
		"northwest" : __DIR__"road2",
		"south" : __DIR__"road4",
"northeast" : "/d/guanwai/laolongtou",	
	]));
	set("objects",([
		"/d/taishan/npc/shu-sheng" : 1,
	]));
 	set("outdoors", "city2");
	setup();
	replace_program(ROOM);
}
