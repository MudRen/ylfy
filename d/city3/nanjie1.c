// Room: /chengdu/nanjie1.c
// oooc: 1998/06/20 

inherit ROOM;

void create()
{
        set("short", "�ϴ��");
	set("long", @LONG
�������ϣ�˫�˺ϱ��Ĵ����ڽֱ�ʮ��һ�꣬�������룬��
ʯ�̾͵Ľ����ɨ�øɸɾ�������û����ò�Ҫ����������
Ϊ�����ǳɶ���������֡�����һ����¥����̻Իͣ�����ĿΪ
֮ѣ�����������������������һЩ��ӡ�
LONG
	);
        set("outdoors", "chengdu");

	set("exits", ([
                "south" : __DIR__"nanjie",
                "north" : __DIR__"guangchang",
                "west" : __DIR__"wang",
                "east" : __DIR__"mj",
	]));

	setup();
	replace_program(ROOM);
}

