//room: lgting.c
inherit ROOM;

void create()
{
	set("short","����㳡");	
	 set("long",@LONG
�����ǰ�������ĵش�,Ҳ�ǰ��������ֵĵط���ƽʱ�����Ǿ��������໥�д��似,̸�۽����ϵ����Ź���.����һЩ��������Ҳ�������˹��Ѳ��,���н���ǰ����������ָ���书.����,����Щ���������ĵ�.������Ů����Ȼ�������һ�����÷羰,�����ǿ�����Щ�����ر���Ʒ.	
LONG);
	set("exits",([
		"east" : __DIR__"dongdajie1",
		"west" : __DIR__"xidajie1",
		"north" : __DIR__"beidajie1",
		"south" : __DIR__"nandajie1",
		]));
	set("objects", ([ /* sizeof() == 1 */
		"/d/npc/ji" : 1,
		"/d/taishan/npc/nainiu" : 1,
		"/d/taishan/npc/nainiu2" : 1,
		]));
	setup();
	replace_program(ROOM);
}
