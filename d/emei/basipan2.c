// Room: /d/emei/basipan2.c ������ ��ʮ����2

inherit ROOM;

void create()
{
	set("short", "��ʮ����");
	set("long", @LONG
�����ǰ�ʮ���̵��м䣬��խխ��ɽ���ϴ����������ֳ�������������
һ�����֣���ֻ�ܽ�����ʯ�����Ƕ��ϡ�
LONG
	);
        set("outdoors", "emei");
	set("exits", ([
		"eastdown" : __DIR__"basipan1",
                "southup":__DIR__"basipan3",
	]));

	setup();
}
