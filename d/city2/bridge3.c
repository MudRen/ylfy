
inherit ROOM;
void create()
{
	set("short", "�ŵ׶���");
	set("long", @LONG
������С�����࣬һ�ɺ��紵���������ɪɪ������ֻ���뿪��
LONG
	);
	set("resource/water", 1);
	set("exits", ([
		"west" : __DIR__"bridge",
	]));
        setup();
	replace_program(ROOM);
}
