// Room: /d/emei/zfengsi.c ������ �з���
// create by host dec,20 1997

inherit ROOM;


void create()
{
	set("short", "�з���");
	set("long", @LONG
����һ����ʯ���ɵ�ש��������ǽ�����к��裬�ϵ�����������
ǽ�ڵĴ����Ǳ���̳������÷��״��ÿ������͸�룬����з·�һ��ѩ
�׵�÷�������ǡ���������һ���ϴ�ķ��裬�ϰڷ���һ������ʯ�Ĺ�����
LONG
	);

	set("exits", ([
		"west" : __DIR__"shenshuige",
	]));

	set("objects",([
                 CLASS_D("emei") + "/jingjia": 1,
	]));

	setup();
}
