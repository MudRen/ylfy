// Room: /d/dali/huanggong16.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��18�գ�����ʱ�䣺21ʱ27��26�롣

inherit ROOM;

void create()
{
	set("short", "[1;33m������[2;37;0m");
	set("long", @LONG
�������Ǵ���ʹ��������ŵ����ڣ����޹����ڵ����������ڡ�
���ܽ����״ӡ������й��ᾯ�����ǽ��ϡ�
LONG
	);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"huanggong17",
  "north" : __DIR__"huanggong15",
  "west" : __DIR__"huanggong18",
]));

                 set("objects", ([
                __DIR__"npc/weishi2" : 4,
        ]));

	setup();
}

