inherit ROOM;

void create()
{
	set("short", "ѧ��");
	set("long", @LONG
ׯ���С���������������飬�����Ǹ���ʮ�����ҵ������ˣ���˵
������ţ���Ҫ�����־������ɵ��飬û����֪��������������Ҳ
����û�к��κ��������

LONG
);
	set("exits", ([
"east" : "/d/party/yuerong/beidajie4.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "yuerong");
	
	setup();
}

