// Room: /new/nandajie4.c
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
		"east" : __DIR__"liangong18",
		"south" : __DIR__"nandajie5",
		"west" : __DIR__"liangong19",
		"north" : __DIR__"nandajie3",
	]));
	
 setup();
 replace_program(ROOM);
}
