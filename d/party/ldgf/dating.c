
inherit ROOM;
void create()
{
set("short", "����");	
	set("long", @LONG
�����ǰ������´���,������һ��Ƥ��ߴ��ι�������������֮��,Ҳ�ǰ�������Ȩ��������.���߸�����һ�����������ң�		
���������������������ƣ������񺿡�
�����������������Ƹ��꣬Ψ�Ҷ���
�Ա߱��ǻ���ľ���Σ������к�Ⱥ�ۻ���ڻ㱨��С�������Ϣ�ط���
LONG
);
set("no_fight",1);
	set("exits", ([
"south" : "/d/party/ldgf/nodeepin1467100368",
"west" : "/d/party/ldgf/nodeepin1467100128",
"north" : "/d/party/ldgf/nodeepin1467099302", /* sizeof() == 2 */
"east" : __DIR__"beidajie3",	
]));

	setup();
	replace_program(ROOM);
}