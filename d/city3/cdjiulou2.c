// Room: /chengdu/cdjiulou2.c
// oooc: 1998/06/25 

inherit ROOM;
inherit F_DEALER;

void create()
{
        set("name", "ӭ�ɾ�¥");
        set("short", "ӭ�ɾ�¥��¥");
	set("long", @LONG
����¥��֪��ʲôʱ�򽨵ģ������ƺ��Ѿ��ܳ�ʱ��������
�Ǹ��������ڡ����ﵽ�Ǹ����ɶ��ǵĺõط������Ҹ��ڴ���λ��
���£�Ъһ����������Ŀ���ƽ���İٻ�̶��������һ�ߵĽֵ���
����е��ܺ�г�����ߵķ�ǽ(wall)���в�������ī�����ʫ�ʡ�
ǽ�Ϲ��ż۸�����(paizi)��
LONG
	);

	set("item_desc", ([
		"paizi" : "������ۿ�Ѽ���ϵȻ���ơ�\n",
	]));

	set("exits", ([
                "down" : __DIR__"cdjiulou",
	]));

	setup();
	replace_program(ROOM);
}
