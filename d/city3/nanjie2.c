// Room: /chengdu/nanjie2.c
// oooc: 1998/06/20 

inherit ROOM;

void create()
{
        set("short", "�ϴ��");
	set("long", @LONG
�����ǳɶ����ϴ�֣�˫�˺ϱ�����ͩ�ڽֱ�ʮ��һ�꣬
��ʯ�̾͵�·���ɨ�øɸɾ�������Ϊ����󶼽������ǹ�
�����ˣ����������ؾ�֮·�����Բ��������˵����¶����ġ�
�����ǳɶ����ã������Ǹ�ȫ��������˵�鳡��
LONG
	);
        set("outdoors", "chengdu");

	set("exits", ([
                "south" : __DIR__"nanjie",
                "north" : __DIR__"nanjie1",
                "east" : __DIR__"cdym",
                "west" : __DIR__"cdshuchang",

	]));

	setup();
	replace_program(ROOM);
}

