// Room: /d/kunlun/dt.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǻ�̫�����¡���ͽ�ĵط������Ϲ���һ��д�š������������Ҷ
���кܿ���ȴûʲô���裬��ǽ�������ѽ��Σ��Ե�ʮ�ֵļ�ࡣ
LONG
	);
    set("objects", ([ 
        CLASS_D("kunlun")+"/hetaichong"  : 1,
    ]));
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"bwc",
  "north" : __DIR__"kjt",
]));

	setup();
	replace_program(ROOM);
}
