// Room: /d/emei/lengshanlin1.c ������ ��ɼ��1

inherit ROOM;

void create()
{
	set("short", "��ɼ��");
	set("long", @LONG
�������ٲ��Ϸ�һ��խխ��ɽ������Ȼ��ɡ�ʯ�������˹�
���һ�����ݡ����϶��˼���ľ׮�����ϴֳ���������Ϊ���֡�
�ٲ��ڽ��±��ڶ������ڲ�Զ��ɽ���»��һ����̶��
LONG
	);

	set("exits", ([
               "northwest":__DIR__"basipan2",
		"southeast" : __DIR__"jieyindian",
	]));

	set("outdoors", "shaolin");
	setup();
	replace_program(ROOM);
}



