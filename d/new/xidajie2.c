// Room: /new/xidajie2.c
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
		"east" : __DIR__"xidajie1",
		"south" : __DIR__"liangong25",
		"west" : __DIR__"xidajie3",
		"north" : __DIR__"liangong26",
	]));
	
 setup();
 replace_program(ROOM);
}
