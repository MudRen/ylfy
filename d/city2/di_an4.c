inherit ROOM;
void create()
{
	set("short", "�ذ��������");
	set("long", @LONG
����һ����������Ĵ��������ͨ���ذ��š�����ͨ�����ı���֡�
�ϱ��������ˣ�һ���˶��������Ƕ�ȥ��
LONG
	);
        set("outdoors", "city2");
	set("exits", ([
		"east" : __DIR__"di_an3",
		"west" : __DIR__"xisi2",
		"south" : __DIR__"xichangdamen",
	]));
	setup();
	replace_program(ROOM);
}
