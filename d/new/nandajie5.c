// Room: /new/nandajie5.c
inherit ROOM;
void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
	�������������Ĵ���ϣ����Ų�����ǻ�����ĸ�ɫ��������Ħȭ���ơ�
���¸�Ȼ��̸���Ž����Ϸ��������Ĺ��£�����ס��Ѫ���ڡ��������������
������Ҫ�ڽ����Ϻú���Ϊһ�����Թ����ͥ�����ﱾ�����߾�ѧ��
LONG
	);
	set("exits", ([
		"east" : __DIR__"liangong20",
		"south" : __DIR__"liangong22",
		"west" : __DIR__"liangong21",
		"north" : __DIR__"nandajie4",
	]));
	
 setup();
 replace_program(ROOM);
}
