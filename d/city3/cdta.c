
inherit ROOM;

void create()
{
        set("short", "�ٻ�̶");
	set("long", @LONG
̶��ƽ������һ�����λεľ��ӣ���ӳ�ź���������̶��ļ�
Ƭ��Ҷ���ָ�̶ˮ�����˼�����ɫ����������佻�Ϫ��
LONG
	);
        set("outdoors","chengdu");

	set("exits", ([
                "west" : __DIR__"caotang",
                "northeast" : __DIR__"cdcc",
                "north" : __DIR__"huanhuaxi1",
	]));
        set("objects" , ([
             __DIR__"npc/youke" : 2,
        ]));
	setup();
}


