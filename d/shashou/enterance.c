// enterance.c

inherit ROOM;

void create()
{
	set("short", "ɱ��¥����");
	set("long", @LONG
�ߵ�����㷢�������Ȼ���ж��졣ǰ����һ�����ž�լ��
��ǰһ�Խ����ʦ���������ͣ�����ɱ֮�ơ��������ұ����絶��ɱ��
��Ȼ�������������֡�ɱ��¥����һ�����Ż���Ҳ�Ǵ���ɽ��ģ����
�������������������צ����������һ����
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
//                   "south" : "/d/dali/dadao1",	
"south" : "/d/henshan/hsroad9",	
		"north" : __DIR__"xiaolu",
	]));
	set("no_clean_up", 0);
        set("objects",([
                      __DIR__"npc/weishi":2,
                        ]));
	set("outdoors", "shashou" );

	set("coor/x",-10);
	set("coor/y",-30);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",-30);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",-30);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
