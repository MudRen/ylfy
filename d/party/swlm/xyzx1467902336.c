inherit ROOM;

void create()
{
	set("short", "Ů��й�");
	set("long", @LONG
��ǰ��������ʽ𣻽�ͯ�Զ�ִ������Ů˫˫�����⡣��б�ң������������գ�������涣���Բ�𽳯�������䴲�ߣ����������𽣻���㱦������������ɷƮƮ�����Ѱ������¯������������������������Ի͡�

LONG
);
	set("exits", ([
"west" : "/d/party/swlm/beidajie3.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "swlm");
	
	setup();
}

