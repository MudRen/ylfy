// Room: /chengdu/wang.c
// oooc: 1998/06/20 

inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
�������������Ĵ��ţ����������������ʯʨ�ӣ��߸ߵ�̨
�ף��м������ţ������Ǳ��ţ�����������ʿ��������������ԣ�
�ſ��Եúܰ�������ͨ�����ǲ������ġ�
LONG
	);

	set("exits", ([
                "east" : __DIR__"nanjie1",
	]));

	setup();
	replace_program(ROOM);
}

