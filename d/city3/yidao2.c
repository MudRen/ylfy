// Room: /d/chendu/yidao2.c
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
                "north" : __DIR__"yidao1",
                  "southwest": "/d/city3/shudao3",
	]));

        set("outdoors", "chengdu");
	setup();
	replace_program(ROOM);
}



