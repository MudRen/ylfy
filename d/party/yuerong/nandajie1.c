// Room: /new/nandajie1.c
inherit ROOM;
void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
�����ڰ��ڵķ�������ϣ��������Ų�ͬ���θ�ɫ�����İ��ڸ���Ħȭ���ơ�			
���¸�Ȼ��̸���Ž����Ϸ��������Ĺ��£�����ס��Ѫ���ڡ��������������
������Ҫ�ڽ����Ϻú���Ϊһ�����������������������ڽ����ϵ�������      
LONG
	);
	set("exits", ([
"west" : "/d/party/yuerong/tudoub1469719439",
"east" : "/d/party/yuerong/tudoub1469717570",
//              "east" : __DIR__"dangpu",	
		"south" : __DIR__"nandajie2",
                "north" : __DIR__"guanchang",	
	]));
	
 setup();
 replace_program(ROOM);
}
