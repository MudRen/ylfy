//ROM dating
inherit ROOM;
void create()
{
        set("short", "�����ô���");
        set("long",
             "���ǡ�������̡��µ�������:�����õĴ���.һλ���߾���,\n"
         "������.\n"
        );
        set("exits", ([
                "north" : __DIR__"chlang2",
                "east" : __DIR__"tang",
        ]));
		set("objects",([
                          __DIR__"npc/jiabu"   :1,
	]));
        setup();
        replace_program(ROOM);
}
