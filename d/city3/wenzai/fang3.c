//bye enter

inherit ROOM;

void create()
{
        set("short", "�෿");
	set("long", @LONG
��������¼������·�ʩ��ס������˵���ڳɶ��ڱ���̫�ã�
��Ҫ�Ǻ�ɫ���㿴������������һ��Ѿ���ڵ��顣
LONG
	);
	set("exits", ([ 
            "west" : __DIR__"zoulang5",
            ]));
        set("objects", ([
            __DIR__"npc/wenfangshi" : 1,
            __DIR__"npc/yahuan" : 1,
              ]));

	setup();
	replace_program(ROOM);
}
