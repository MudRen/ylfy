// Room: /d/dali/huanggong14.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��18�գ�����ʱ�䣺21ʱ27��26�롣

inherit ROOM;

void create()
{
	set("short", "[1;33m�޹�[2;37;0m");
	set("long", @LONG
�����ǻʵ۵��޹�������һֻ��¯��Ѭ��һ��̴�㣬��������
�������ƣ����˻����˯��������ɴ���ᴹ��������ʰ���˳���Ⱦ��
����̫��͹�Ů����ͣ����ʰ���䡣
LONG
	);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"huanggong13",
]));

                 set("objects", ([
                __DIR__"npc/gongnu" : 2,

                __DIR__"npc/taijian" : 2,
        ]));

         
	setup();
}

