// Room: /new/beidajie4.c
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
		"south" : __DIR__"beidajie3",
		"north" : __DIR__"beidajie5",
	]));
	
 setup();
 replace_program(ROOM);
}
