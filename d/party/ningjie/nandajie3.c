// Room: /new/nandajie3.c
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
		"south" : __DIR__"nandajie4",
		"north" : __DIR__"nandajie2",
	]));
	
 setup();
 replace_program(ROOM);
}
