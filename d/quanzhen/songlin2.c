// songlin1.c ����

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
ï�ܵ����֣���ʱ�ܼ�����ֻ����������������ȥ����Ȼֻ�м�
˿������͸�ֶ��룬ȴ���Ե���ɭ�ɲ���ϰϰ���粻ʱӭ�洵����
ʹ�˻����泩��ʹ�����������˯��һ����
LONG
	);
        set("outdoors", "quanzhen");

	set("exits", ([
		"north" : __DIR__"songlin1",
		"south" : __DIR__"songlin3",
                "east" : __DIR__"songlin2",
                "west" : __DIR__"songlin4",
        ]));
	setup();
	replace_program(ROOM);
}
