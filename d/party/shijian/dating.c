
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
"down" : "/d/party/shijian/xiaocc1466901308",
"up" : "/d/party/shijian/xyws1466697225",
"north" : "/d/party/shijian/xiaoyao1466686588", /* sizeof() == 2 */
"east" : __DIR__"beidajie3",	
]));

	setup();
	replace_program(ROOM);
}
