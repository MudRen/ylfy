// Room: /new/beidajie1.c
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
"west" : "/d/party/yuerong/tudoub1466848465",
"east" : "/d/party/yuerong/tudoub1466847400",
"south" : __DIR__"guanchang",	
		"north" : __DIR__"beidajie2",
	]));
	
 setup();
 replace_program(ROOM);
}
