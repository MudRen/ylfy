// songlin4.c ����

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
		"south" : __DIR__"cuihuamiao",
		"north" : __DIR__"songlin1",
                "west" : __DIR__"songlin2",  
	]));
	setup();
	replace_program(ROOM);
}
