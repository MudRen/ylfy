// hsroad6.c �ּ���
inherit ROOM;

void create()
{
	set("short", "�ּ���");
	set("long", @LONG
������һ���ּ����������������ѡ������Ǻ��Ͼ��ڡ�������
������·���пɹ�·����Ϣ��С��ͤ��
LONG );
        set("outdoors", "henshan");

	set("exits", ([
		"east"   : __DIR__"chating",
		"north"  : __DIR__"hsroad7",
		"south"  : __DIR__"hsroad5",
	]));

        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

