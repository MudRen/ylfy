// Room: /new/dongdajie1.c
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
		"east" : __DIR__"dongdajie2",
	//	"south" : __DIR__"liangong34",
                "west" : __DIR__"guanchang",	
	//	"north" : __DIR__"liangong35",
	]));
	
 setup();
 replace_program(ROOM);
}
