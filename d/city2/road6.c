
inherit ROOM;
void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵġ�
���̵ġ����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡�
��ʱ����������������߷ɳ۶���������һ·��������·������
��������������֡�������ԶԶ�ľͿ������������ǡ�
LONG
	);
	set("exits", ([
		"northwest" : "/d/city2/road5",
		"southeast" : __DIR__"road7",
"southwest" : "/d/hengshan/jinlongxia",	
	]));
 	set("outdoors", "city2");
	setup();
	replace_program(ROOM);
}
