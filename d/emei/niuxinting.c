// /d/emei/niuxinting.c ������ ţ��ͤ

inherit ROOM;

void create()
{
	set("short", "ţ��ͤ");
	set("long", @LONG
������һ������ͤ��һ����ɽС���������£���ͤ���������ߣ�ֻ��
ɽʽԽ�������վ������ڶ����ְأ���Ȫ�ٲ���������䡣���پ�ï����
��Ȥζ��ÿ�����˪�������и�Գ��Х���չȴ��죬��ת�þ�������Ҳ��
·;�Ͷ٣�������Ϣ��һ���õط���
LONG
	);
        set("outdoors", "emei");
	set("exits", ([ /* sizeof() == 3 */
                "westdown":__DIR__"qingyinge",
                "southup":__DIR__"yixiantian",
		]));

	set("objects", ([ 
             "/d/emei/npc/youke" : 1,
	]));

	setup();
}
