// Room: /d/emei/jiulaodong.c ������ ���϶�

inherit ROOM;

void create()
{
	set("short", "���϶�");
	set("long", @LONG
������һ������ʮ��խС��ʯ��������ǰ�У������򶴿���ȥ��ֻ��
����һ�����ٴ������·���ֱ�¡��߽�������ȴ��Ȼ���ʣ����������һ
ЩԲ�ε�ʯ����ʯ�Ρ��˶���ů����������֣�ʵ��һ�����޵ĺ�ȥ����
LONG
	);
	set("exits", ([
                "out": __DIR__"jiudaoguai4",
                "east": __DIR__"lianhuashi",
	]));

	set("objects",([
	        "/d/emei/npc/little_monkey": 1,
                "/d/emei/npc/monkey" : 1,
        ]));
	setup();
}
