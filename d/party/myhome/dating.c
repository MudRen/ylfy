
inherit ROOM;
void create()
{
set("short", "����");	
	set("long", @LONG
�����ǰ������´���,������һ��Ƥ��ߴ��ι������������֮��,Ҳ�ǰ�������Ȩ��������.���߸�����һ�����������ң�		
���������������������ƣ�����񺿡�
�����������������Ƹ��꣬Ψ�Ҷ���
�Ա߱��ǻ���ľ���Σ������к�Ⱥ�ۻ���ڻ㱨��С�������Ϣ�ط���
LONG
);
set("no_fight",1);
	set("exits", ([
"south" : "/d/party/myhome/mydjh1468030138",
"west" : "/d/party/myhome/myone1466324906",
"north" : "/d/party/myhome/mydjh1465993167", /* sizeof() == 2 */
"east" : __DIR__"beidajie3",	
]));

	setup();
	replace_program(ROOM);
}
