// dao.c ����·
// by oooc

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
������һ����������Ļ���·�ϣ���������ɭɭ�����֡�����
���Ĵ����磬��˵���������˳�û�����ɾ�����
LONG
	);
        set("outdoors", "chengdu");

	set("exits", ([
                "northeast" : __DIR__"dao1",
                "south" : __DIR__"dadao2",
	]));

	setup();
	replace_program(ROOM);
}

