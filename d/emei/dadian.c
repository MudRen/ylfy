// Room: /d/emei/dadian.c ������ ���
// create by host dec,15 1997
inherit ROOM;


void create()
{
	set("short", "���");
	set("long", @LONG
�����������ֵ�������й�����һ��޴�������������������㣬
����Ʈ����ͭ�����Ҹ�������ͯ��Ů�����������߸�����һ��ڵ�����
�ޱߡ������ռ�ȺӢ�����������аڷ���һ���㰸�������������ơ���ǽ
���ż���̫ʦ�Σ����Ϸ��ż������š�
LONG
	);

	set("exits", ([
               "north":__DIR__"guangchang",
	]));

	set("objects",([
               CLASS_D("emei") + "/jingxuan" : 1,
	]));

	setup();

}
