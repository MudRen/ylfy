// Room: /d/dali/huanggong4.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��18�գ�����ʱ�䣺21ʱ27��26�롣

inherit ROOM;

void create()
{
	set("short", "[1;33m���µ�[2;37;0m");
	set("long", @LONG
�����ǳеµ�ǰ��һ���������Ǹ����ϳ�ʱ��Ϣ�õġ�����
�Ѿ�ɢ���ˣ�ֻ�м�����ʿ�ڵ���ִ�ڡ�����ǰ�������͵��˻ʹ�
�����ĳеµ
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"huanggong3",
  "north" : __DIR__"huanggong5",
]));
                 set("objects", ([
                __DIR__"npc/shiwei" : 2,
        ]));


	setup();
}

