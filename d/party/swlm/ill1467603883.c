inherit ROOM;

void create()
{
	set("short", "ժ��¥");
	set("long", @LONG
�ڳ�������İ��ڱ����һ�����ź�ɫ¶����ȹ�����Ӱ��������֮�⣬�ⱳӰ������俣�������־�ᡣŮ��һֻ��۲������������������һ��СƤ�ޣ�ǡ���ô��ش����β���Ե��

LONG
);
	set("exits", ([
"down" : "/d/party/swlm/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "swlm");
	
	setup();
}

