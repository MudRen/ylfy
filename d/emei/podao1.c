// Room: /d/emei/podao1.c ������ �µ�1

inherit ROOM;

void create()
{
	set("short", "�µ�");
	set("long", @LONG
������һ��խխ����ɽС·����Ȼ��ɡ���·�ܶ��ͣ��ߴ�����ʹ��
�����ĺ�����ɽ����һ����С�ĺ����ױ����鵽�¹�֮�С����������
����Ȼ�γɵ�һ���ʯ���ϣ��Ѿ��е�����������
LONG
	);
        set("outdoors", "emei");
	set("exits", ([
                "enter": __DIR__"lianhuashi",
                "southup":__DIR__"podao2",
	]));

	setup();
}



