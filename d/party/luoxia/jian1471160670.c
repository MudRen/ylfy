inherit ROOM;

void create()
{
	set("short", "�㳡");
	set("long", @LONG
����ǰ������һƬ�ܴ�Ĺ㳡��ǰ��ñ�û�Ȼ����ԭ�����ǰ��ڶ��ߵ�һ�����䳡���ܶ��Ǹ�ɽֱ���Ƽ䣬�γ�һ����Ȼ����أ����ﳣ���������Ҳ�ǰ�������ļ��ѳ��أ���˵���������������°빦����
��

LONG
);
	set("exits", ([
"west" : "/d/party/luoxia/beidajie4.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "luoxia");
	
	setup();
}

