//hudi4.c

inherit ROOM;

void create()
{
	set("short", "С���� ");
	set("long", @LONG
������С�����ף����ܺں����ģ�ͷ����ֻ�ܿ���һ�����⣬��ߵ�ˮ��
�ƺ������ļ��ˡ������ƺ���һ�����⣬Ҳ��֪��Щʲô����ΧһƬ���ţ���
�������Ų��ɱ����
LONG
	);
	set("exits", ([
		"up" : __DIR__"",	
		"down" : __DIR__"",
		"east" : __DIR__"",
		"north" : __DIR__"",
		"south" : __DIR__"",
	]));
	setup();
	replace_program(ROOM);
}
