
inherit ROOM;
void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵġ�
���̵ġ����Ŵ󳵵������Ͼ��Ͽ��������������������ǳ����֡�
��ʱ������������������߷ɳ۶���������һ·��������·������
��������������֡����߾��Ǿ��Ƕ��š���������һ��С·����ס
�����򺣸�ȥ��.
LONG
	);
	set("exits", ([
		"east" : "/d/city2/road10",
		"west" : "/d/city2/dongmen",
		"southeast" : __DIR__"road2",
		"northeast" : __DIR__"zhuang1",
	]));
	set("objects",([
		"/d/taishan/npc/tiao-fu" : 1,
	]));
 	set("outdoors", "city2");
	setup();
	replace_program(ROOM);
}