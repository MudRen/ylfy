// Room: /d/emei/lianhuashi.c ������ ����ʯ


inherit ROOM;


void create()
{
	set("short", "����ʯ");
	set("long", @LONG
�������Ӿ��϶��Ե�һ��֧��������߸ߴ���һ����״��������
�Ĵ�ʯ(stone)����ʯ��Ө��͸���������������������£���������
�⻪�������������ﾲ��������õ��޵�������
LONG
	);

	set("exits", ([
                "west":__DIR__"jiulaodong",
                "out": __DIR__"podao1",
	]));

	set("objects",([
	]));

	setup();
}
