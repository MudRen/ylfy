// Room: /city2/qianzhuang.c
inherit ROOM;
void create()
{
	set("short", "�鱦��");
	set("long", @LONG
���ǽ���ڱ������鱦�ֵ꣬����ղص������챦����������ʤ����
��˵�������ó�һ���䱦���Ǽ�ֵ���ǣ����ɵй��ģ�����Щ���Ǵ���
����֪��٣�Ҳû��������������ҵ��κ�������Ҳ�������ô
��Ѩ����ɣ����ж��йŹ֡�
����������ǽ�Ϲ���һ����Ŀ������(paizi)��
LONG
);
	set("item_desc", ([
		"paizi" : "\n�����ղظ�����\n"+"���鱦��cun ID\n"+"ȡ�鱦��qu ID\n"+"��ѯ��ŵ��鱦��chaxun\n"
	]));
	
	set("exits", ([
		"north" : __DIR__"chaoyan1",
	]));
	
	set("objects", ([
		__DIR__"npc/zhubaoshang" : 1
	]));
	
	set("no_fight",1);
	setup();
	replace_program(ROOM);
}
