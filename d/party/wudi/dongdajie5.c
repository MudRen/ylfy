// Room: /new/dongdajie5.c
inherit ROOM;
void create()
{
	set("short", "�����");
	set("long", @LONG
�����ڰ��ڵķ�������ϣ��������Ų�ͬ���θ�ɫ�����İ��ڸ���Ħȭ���ơ�			
���¸�Ȼ��̸���Ž����Ϸ��������Ĺ��£�����ס��Ѫ���ڡ��������������
������Ҫ�ڽ����Ϻú���Ϊһ�����������������������ڽ����ϵ�������      
LONG
	);
	set("exits", ([
	//	"east" : __DIR__"liangong44",
	//	"south" : __DIR__"liangong42",
		"west" : __DIR__"dongdajie4",
	//	"north" : __DIR__"liangong43",
	]));
	
 setup();
 replace_program(ROOM);
}
