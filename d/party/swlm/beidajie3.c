// Room: /new/beidajie3.c
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
"east" : "/d/party/swlm/xyzx1467902336",
//              "east" : __DIR__"qianzhuang",	
		"south" : __DIR__"beidajie2",
                "west" : __DIR__"dating",	
		"north" : __DIR__"beidajie4",
	]));
	
 setup();
 replace_program(ROOM);
}
