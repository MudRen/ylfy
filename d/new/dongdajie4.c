// Room: /new/dongdajie4.c
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
		"east" : __DIR__"dongdajie5",
		"south" : __DIR__"liangong40",
		"west" : __DIR__"dongdajie3",
		"north" : __DIR__"liangong41",
	]));
	
 setup();
 replace_program(ROOM);
}
