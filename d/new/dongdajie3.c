// Room: /new/dongdajie3.c
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
		"east" : __DIR__"dongdajie4",
		"south" : __DIR__"liangong38",
		"west" : __DIR__"dongdajie2",
		"north" : __DIR__"liangong39",
	]));
	
 setup();
 replace_program(ROOM);
}
