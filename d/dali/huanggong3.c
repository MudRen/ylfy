// Room: /d/dali/huanggong3.c
// Data: ��(ami)
// Time: ��Ԫ��1999��4��19�գ�����ʱ�䣺13ʱ22��2�롣

inherit ROOM;

void create()
{
	set("short", "[1;33m�㳡[2;37;0m");
	set("long", @LONG
���������µ�ǰ��һ���㳡�����������˴�������軨���м�һ
��������ֱͨ���µ�������վ��һ����������Ľ��������Ե�
�����ׯ�����¡�
LONG
	);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"huanggong17",
  "south" : __DIR__"huanggong2",
  "northup" : __DIR__"huanggong4",
]));

                 set("objects", ([
                __DIR__"npc/taijian" : 2,
                __DIR__"npc/weishi2" : 4,
        ]));

        setup();

}

