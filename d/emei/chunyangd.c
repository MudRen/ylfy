// Room: /d/emei/chunyangd.c ������ ������
// create by host dec,12 1997

inherit ROOM;


void create()
{
	set("short", "������");
	set("long", @LONG
�����Ƕ��ҵĴ����������й�����һ������������һȺ����С��
���ڷ���ǰ�ĵ����о����������ǽ�ڵĺ���ð�������������󳪽�����
һ�����˶�ʱ���𼸷�����֮�С�
LONG
	);

	set("exits", ([
                "east":__DIR__"chanfang1",
                "north":__DIR__"chunyangd1",
                "west":__DIR__"chanfang2",
	]));

	set("objects",([
                CLASS_D("emei") + "/jingxian" : 1,
         ]));
	setup();

}
