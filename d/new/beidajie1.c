// Room: /new/beidajie1.c
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
		"east" : __DIR__"liangong1",
		"south" : __DIR__"lgting",
		"west" : __DIR__"liangong2",
		"north" : __DIR__"beidajie2",
	]));
	
 setup();
 replace_program(ROOM);
}
