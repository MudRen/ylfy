// Room: /new/beidajie5.c
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
"west" : "/d/party/killer/jiuyanga1470803557",
"east" : "/d/party/killer/snow1466053499",
"north" : "/d/party/killer/afei1465866077",
		"south" : __DIR__"beidajie4",
	]));
	
 setup();
 replace_program(ROOM);
}
