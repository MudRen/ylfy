// Room: /d/chengdu/xiaojie2.c
// oooc 1998/06/21 

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
����һ����ʯ���̳ɵ�С�֣�·��ǳ��ɾ���������Ϊÿ����
�������й��˰������ɨһ�顣�����Ƿ���ͤ�������Ǹ�����ݣ�
���������Ǹ����á�
LONG
	);
        set("outdoor","chengdu",);

	set("exits", ([
                "eastup" : __DIR__"fengyuting",
                "southeast" : __DIR__"niangjiuwo",
                "southwest" : __DIR__"jiaotang",
                "west" : __DIR__"xiaojie2",
	]));

	setup();
	replace_program(ROOM);
}

