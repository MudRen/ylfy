//hudi3.c

inherit ROOM;

void create()
{
	set("short", "С���� ");
	set("long",@LONG
������С���ף����ܺں����ģ�ͷ���Ͽ�����һ�����⣬��ߵ�ˮ��
���Ϻ��µ�ӿ���š���������һ�����ۡ������ƺ���һ�����⣬Ҳ��֪��
Щʲô����ΧһƬ���ţ��ƺ������Ų��ɱ����
LONG

	);
	set("exits", ([
		"up" : __DIR__"",	
		"down" : __DIR__"",
		"southwest" : __DIR__"",
		"northwest" : __DIR__"",
		
	]));
	setup();
	replace_program(ROOM);
}