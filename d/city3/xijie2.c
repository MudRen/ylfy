inherit ROOM;

void create()
{
        set("short", "�����");
	set("long", @LONG
����������֣��������������ַǷ��������������αȵĵ�
�̣�������ɫ�Ļ�������Ʈ��ɷ�����ޡ������и�ľ���̣���˵
�����ľ�����պ����˵á�
LONG
	);
        set("outdoors", "chengdu");

	set("exits", ([
                "east" : __DIR__"guangchang",
                "west" : __DIR__"xijie1",
                "south" : __DIR__"mujiangpu",
		"north" : __DIR__"qianzhuang",
	]));
        set("objects", ([
            __DIR__"npc/flowerg" : 1,
            __DIR__"npc/chike" : 1,
        ]));


	setup();
	replace_program(ROOM);
}

