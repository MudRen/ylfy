
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
"north" : "/d/party/taoism/haozhishen1470885796", /* sizeof() == 2 */
"east" : __DIR__"beidajie3",	
]));

	setup();
	replace_program(ROOM);
}
