// Room: /d/emei/baoguosi.c ������ ����ʯ
// create by host dec,20 1997

inherit ROOM;


void create()
{
	set("short", "����ʯ");
	set("long", @LONG
����һ��С����������Ȼ��ï�ܵ����֡�����עĿ������·����һ��
�����ϻ��Ĵ�ʯ��������צ��Ω��ΩФ��������һ����·����������һ��
��������������ɽ�ıؾ�֮·��
LONG
	);
         set("outdoors", "emei");
	set("exits", ([
		"south" : __DIR__"fuhusi",
                "west" : __DIR__"milin2",
                "north":__DIR__"milin1",
	]));

	set("objects",([
	]));

	setup();

}
