// Room: /new/xidajie3.c
inherit ROOM;
void create()
{
	set("short", "�����");
	set("long", @LONG
	�������������Ĵ���ϣ����Ų�����ǻ�����ĸ�ɫ��������Ħȭ���ơ�
���¸�Ȼ��̸���Ž����Ϸ��������Ĺ��£�����ס��Ѫ���ڡ��������������
������Ҫ�ڽ����Ϻú���Ϊһ�����Թ����ͥ�����ﱾ�����߾�ѧ��
LONG
	);
	set("exits", ([
		"east" : __DIR__"xidajie2",
		"south" : __DIR__"liangong27",
		"west" : __DIR__"xidajie4",
		"north" : __DIR__"liangong28",
	]));
	
 setup();
 replace_program(ROOM);
}
