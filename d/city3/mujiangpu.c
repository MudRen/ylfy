
inherit ROOM;

void create()
{
	set("short", "ľ����");
	set("long", @LONG
����һ�Ҽ�ª��ľ���̣�һ������ľ�������ڵ��϶�������ֵ��������ľ
����Ҳֻ������Щ��ǹ����ʲô�������Һ��ڡ����Ϻ�ǽ�����ҵضѷ���һЩ
ľ����ľ����ľ��ʲô�ģ����м�������ӣ�����һ���ľ�����ߡ�
LONG
	);

	set("objects", ([
		__DIR__"npc/mujiang" : 1,
	]));

	set("exits", ([
                "north" : __DIR__"xijie2",
	]));

	setup();
	replace_program(ROOM);
}

