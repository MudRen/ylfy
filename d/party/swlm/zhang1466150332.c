inherit ROOM;

void create()
{
	set("short", "媹�Ȫ");
	set("long", @LONG
һ���޶��ģ�������ע�����ײ��綦�У����������¡������̺̼ڣ�ͣ�����׳��������᷺���������Ž�

LONG
);
	set("exits", ([
"east" : "/d/party/swlm/dating.c",
		]));
	
	set("objects", ([
		"/clone/room/npc/peilian" : 1,
       ]) );
	
	set("owner", "bigtie7001");
	set("banghui", "swlm");
	
	setup();
}

