inherit ROOM;

void create()
{
	set("short", "����ɭ��");
	set("long", @LONG
�����ǰ��ڵ����䳡�����ɾ����������ĵ����汻��ˮ��ù����羵
���ܰڷ��Ÿ��������������м����������������չ㳡��������������Ļ��ݡ�

LONG
);
	set("exits", ([
"west" : "/d/party/luoxia/beidajie3.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "luoxia");
	
	setup();
}

