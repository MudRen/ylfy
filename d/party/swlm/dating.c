
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
"southwest" : "/d/party/swlm/xyzx1469029101",
"northwest" : "/d/party/swlm/ill1468664667",
"down" : "/d/party/swlm/ill1467708858",
"up" : "/d/party/swlm/ill1467603883",
"south" : "/d/party/swlm/jackie1467433435",
"north" : "/d/party/swlm/shabi1467026792",
"west" : "/d/party/swlm/zhang1466150332", /* sizeof() == 2 */
"east" : __DIR__"beidajie3",	
]));

	setup();
	replace_program(ROOM);
}
