inherit ROOM;

void create()
{
	set("short", "Ц������");
	set("long", @LONG
���׽�����Ƿ����񹦣�Ϊ�ξ������ϰ֮���������ǣ�ԭ�����徭�籾������������������������ǿ���Ժ���֮���׽�����������ϰ�þ����񹦣�ȴ�Ǵ�����֮�¡�

LONG
);
	set("exits", ([
"southeast" : "/d/party/swlm/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "swlm");
	
	setup();
}

