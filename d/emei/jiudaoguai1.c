// Room: /d/emei/jiudaoguai1.c ������ ��ʮ�ŵ���1

inherit ROOM;

void create()
{
	set("short", "��ʮ�ŵ���");
	set("long", @LONG
������ɽ����һ��խխ��С·��������վ�ڹȿڣ�ֻ�������ͱ�ֱ
������·��Ȼ�Ƚ�ƽ���������������Ŀ�������ͷ���߽�ɽ���У�ʱ��
ʱ��������������������ٲ����ڶ��£�������淢�������졣
LONG
	);
        set("outdoors", "emei");
	set("exits", ([
                 "north" : __DIR__"shangu",
		"southwest" : __DIR__"jiudaoguai2",
	]));

	setup();
}



