//m_weapon .....tianjianshi.c
//xuanbing.c

inherit ROOM;

void create()
{
	set("short", "�����Ŷ�");
	set("long",
	     "�����������Ŷ����ڣ����洫������Ĵ��������ƺ��ڶ�����ʲô������\n"
	     "��͸��һ����ɱ����Ϣ��\n"

	);
	set("exits", ([
		"east" : "/d/xingxiu/nanjiang2",
		"enter" : __DIR__"xuanbing1",
	]));
	set("coor/x",-150);
	set("coor/y",10);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
