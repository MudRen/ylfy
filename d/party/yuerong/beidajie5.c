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
"north" : "/d/party/yuerong/tudoug1469432584",
"west" : "/d/party/yuerong/tudoug1469431143",
"east" : "/d/party/yuerong/tudoug1469371091",
		"south" : __DIR__"beidajie4",
	]));
	
 setup();
 replace_program(ROOM);
}
