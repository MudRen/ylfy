// Room: /d/emei/jiudaoguai4.c ������ ��ʮ�ŵ���4

inherit ROOM;

void create()
{
	set("short", "��ʮ�ŵ���");
	set("long", @LONG
�����Ǿ�ʮ�ŵ�����ĩβһ��ɽ������·���������˸��ָߴ����ľ��
�����дС����·���Զ�ĵط����Կ����и�ɽ�����ڣ�������ȥ������֮
��Խ��ԽŨ�ˡ�
LONG
	);
        set("outdoors", "emei");
	set("exits", ([
                 "northwest" : __DIR__"jiudaoguai3",
                 "enter": __DIR__"jiulaodong",
	]));

	setup();
}
