// Room: /d/chengdu/yidao1.c
// Date: oooc 1998/06/27

inherit ROOM;




void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵ�
���̣����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡�
��ʱ����������������߷ɳ۶���������һ·���������ϵ���
�������ž�װ���¼��������еĻ���������ŵ�������������Щ
Щϰ��Ľ����ˡ���·��������������������֡�
LONG
	);

	set("exits", ([
                "south" : __DIR__"yidao2",
                "north" : __DIR__"yidao",
	]));

        set("outdoors", "chengdu");
	setup();
	replace_program(ROOM);
}



