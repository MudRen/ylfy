inherit ROOM;

void create()
{
	set("short", "����ר��");
	set("long", @LONG
����ר�þ���ר�þ���ר�þ���ר�þ���ר�þ���ר�þ���ר�þ���ר�þ���ר�þ���ר�þ���ר�þ���ר�þ���ר�þ���ר��

LONG
);
	set("exits", ([
"east" : "/d/party/wudi/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "wudi");
	
	setup();
}

