// Room: /new/nandajie2.c
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
		"east" : __DIR__"liangong14",
		"south" : __DIR__"nandajie3",
		"west" : __DIR__"liangong15",
		"north" : __DIR__"nandajie1",
	]));
	
 setup();
 replace_program(ROOM);
}
