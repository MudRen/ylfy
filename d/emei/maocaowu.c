// /d/emei/maocaowu.c ������ é����
// create by host dec,20 1997
inherit ROOM;

void create()
{
	set("short", "é����");
	set("long", @LONG
����һ�����ĵ�Сé���ݣ�����ǽ�����ôִ���������������ģ���
���Ϸ������˵��ݡ����ڰ���Ƚϼ򵥣������ֳ��õ������⣬���м�ǽ
���Ϲ���һ�š�̤ѩͼ����
LONG
	);
	set("exits", ([ 
                "north" : __DIR__"liba", 
		]));
	set("objects", ([ 
	CLASS_D("emei") + "/zhou" : 1,
      ]));

	setup();
	replace_program(ROOM);
}
