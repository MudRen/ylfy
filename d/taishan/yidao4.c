// Room: /d/shaolin/yidao4.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵ�
���̣����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡�
��ʱ����������������߷ɳ۶���������һ·��������·����
����������������֣���������̲�Ʈ���̫����
LONG
	);

	set("exits", ([
              "west": __DIR__"yidao3",
            "east":"/d/mr/hubian",
	]));

	set("objects",([
		__DIR__"npc/dao-ke" : 1,
	]));

	set("outdoors", "taishan");
	setup();
	replace_program(ROOM);
}



