
inherit ROOM;

void create()
{
        set("short", "�����");
	set("long", @LONG
�����ֹᴩ�ɶ����С����������ؽֶ�����Ǯ���Ƶľ�
¥����ݣ������ֳ�Ϊ����ʳ�֡�����������������ֳ̼�Ⱥ��
�������ﳵ���������������У�ҹ���ǹ���£��ƻ�ͨ�����ϱ�
�Ǹ���ݣ������и�ˮ����
LONG
	);
        set("outdoors", "chengdu");

	set("exits", ([
                "east" : __DIR__"eastchengmen",
                "south" : __DIR__"cdchaguan",
                "north" : __DIR__"shuijing",
                "west" : __DIR__"dongjie2",

	]));
        set("objects", ([
            __DIR__"npc/youke" : 1,
        ]));

	setup();
	replace_program(ROOM);
}

