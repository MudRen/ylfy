// Room: /new/nandajie3.c
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
		"east" : __DIR__"liangong16",
		"south" : __DIR__"nandajie4",
		"west" : __DIR__"liangong17",
		"north" : __DIR__"nandajie2",
	]));
	
 setup();
 replace_program(ROOM);
}
