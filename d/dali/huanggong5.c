// Room: /d/dali/huanggong5.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��18�գ�����ʱ�䣺21ʱ27��26�롣

inherit ROOM;

void create()
{
	set("short", "[1;33m����[2;37;0m");
	set("long", @LONG
�����ǳеµ�ǰ��һ����������ǳ����ϳ�����֮·�����
���ڼ�ʿ�������䱸ɭ�ϡ�
LONG
	);
	set("exits", ([ /* sizeof() == 5 */
  "south" : __DIR__"huanggong4",
  "west" : __DIR__"huanggong11",
  "east" : __DIR__"huanggong10",
  "north" : __DIR__"huanggong7",
  "northup" : __DIR__"huanggong6",
]));

                 set("objects", ([
                __DIR__"npc/shiwei" : 4,

        ]));

	setup();
}

