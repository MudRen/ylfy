// Room: /d/emei/baoguosi.c ������ ������
// create by host dec,20 1997

inherit ROOM;


void create()
{
	set("short", "������");
	set("long", @LONG
����һ�����ӵķ��á��������������ȣ� ����һ��ѩɽ��Хͼ��
��������������ŷ�����ʮ���Ʋ����ţ�������һ��ľ�������Ϸ��Ÿ���
�Ƶ�ľ�㡣�������ƣ��뵷ҷ�������һƬ���֮����
LONG
	);

	set("exits", ([
		"north" : __DIR__"fuhusi1",
                 "west": __DIR__"chanfang3",
	]));

	set("objects",([
         CLASS_D("emei") + "/jingzhen": 1,
	]));

	setup();
}
