// Room: /new/nandajie1.c
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
		"east" : __DIR__"liangong12",
		"south" : __DIR__"nandajie2",
		"west" : __DIR__"liangong13",
		"north" : __DIR__"lgting",
	]));
	
 setup();
 replace_program(ROOM);
}
