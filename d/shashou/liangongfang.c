// liangongfang.c ������
// by Xiang

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���������������������ҵط��ż�������,��λɱ��¥��������ϥ������
�������
LONG
	);
	set("exits", ([
                "west" : __DIR__"jiaochang",
	]));
	set("objects", ([
            "/clone/weapon/zhujian" : 2,
            "/d/taohua/npc/jiguan" : 2
			]));

	setup();
	replace_program(ROOM);
}
