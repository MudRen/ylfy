// Room: /d/dali/dbdajie1.c
// Data: һ��(not)
// Time: ��Ԫ��1999��4��21�գ�����ʱ�䣺17ʱ46��27�롣

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
�����Ǵ���ʹ�����ĳ���·�������ڽ��ʹ���Ե�������Ե���
�ֶ�����Ȼ������ɴ����ز��Ĵ���ʯ�̳ɣ���Χ�긨���������ص�
���ˣ��ο����ﲻ����������������䡣��һƬ�����ľ���
LONG
	);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"dbdajie2",
  "west" : __DIR__"jiulou.c",
  "east" : __DIR__"qianzhuang",
  "south" : __DIR__"dongdajie1",
]));

        set("objects", ([
                                __DIR__"npc/jieba" : 1,
        ]));

	setup();
}
