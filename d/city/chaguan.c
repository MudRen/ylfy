// Room: /city/chaguan.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "�������");
	set("long", @LONG
��һ�߽��������ŵ�һ�ɲ���������Ƣ������Ϊ֮һˬ�����Ű�����һ���ſ���
�����˿��ˣ������̸Ц����ͷ�Ӷ�����Ҫ����������ƹʺ�ҥ�ԣ������Ǹ���
���ڡ��ϰ��ﲻʱ���Աߵ�һ��Сˮ��(well)��ȡˮ��������ˮ��衣
LONG
	);
	set("resource/water", 1);
	set("item_desc", ([
		"well" : "����С�����������ʢ(fill)�������ľ�ˮ�����Ű���ɩҲ���ᷴ�Եġ�\n",
	]));
	set("exits", ([
		"east" : __DIR__"nandajie2",
	]));
	set("objects", ([
		__DIR__"npc/aqingsao" : 1,
	]));
	setup();
	replace_program(ROOM);
}
