// Room: /d/emei/lshenggang.c ����ƺ

inherit ROOM;

void create()
{
        set("short", "����ƺ");
	set("long", @LONG
����һ���������Ѷ��ϵ�С·����������״Ť������һ���������ʳ�Ϊ
����ƺ�������˹������ʯ�׶��ϣ����Կ���Զ����ɽ��ʱ��ʱ���������У�
����ͦ�㣬��ȶ��ʡ��㲻����̾�����Ŷá��������ں��ңհ���ɷ
Ū�紨����
LONG
	);
        set("outdoors", "emei");
	set("exits", ([
               "west":__DIR__"chunyangd1",
               "southup":__DIR__"shenshuige",
	]));

	setup();
	replace_program(ROOM);
}



