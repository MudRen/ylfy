
inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
��һ�߽��������ŵ�һ�ɲ���������Ƣ������Ϊ֮һˬ����
�Ű�����һ���ſ��������˿��ˣ������̸Ц����ͷ�Ӷ���ֻ
����ȫ��Щ���Ŵ���������֮ͽ����Ҫ������������ƹʺ�ҥ�ԣ�
�����Ǹ������ڡ���ҪЩ��ˮ�͵��Ŀ���ЩС����
LONG
	);
        set("no_fight",1);

	set("exits", ([
                "north" : __DIR__"dongjie3",
	]));

	set("objects", ([
                __DIR__"npc/boss" : 1,
	]));

	setup();
	replace_program(ROOM);
}

