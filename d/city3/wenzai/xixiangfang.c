//bye enter

inherit ROOM;

void create()
{
        set("short", "���᷿");
	set("long", @LONG
���ǹ�������Ϣ���᷿�����Ӳ��󣬵��Ǻ����࣬ǽ�Ϲ�
��һЩ�ֻ����и�Ѿ����æ��Ϊ�����ݲ衣
LONG
	);
	set("exits", ([ 
            "east" : __DIR__"yuanzi",
            ]));
        set("objects", ([
            "/d/city3/obj/chair" : 1,
            __DIR__"npc/yahuan" : 1,
             ]));

	setup();
	replace_program(ROOM);
}
