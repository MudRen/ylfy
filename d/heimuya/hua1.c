//ROOM: hua1.c
inherit ROOM;
void create()
{
	set("short", "��԰");
        set("long",
	     "����һ�������µ�С��԰,԰��,��÷����, ���ɴ��\n"
	     ", ���õ��ľ߽���, ����ȥ��һƬ��ݵ�\n"
                         );
        set("exits", ([
		"west" : __DIR__"grass2",
                      ]));
        setup();
        replace_program(ROOM);
}
