// Room: /d/dali/yaopu.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��19�գ�����ʱ�䣺21ʱ57��49�롣

inherit ROOM;

void create()
{
	set("short", "ҩ��");
	set("long", @LONG
����һ�����ص�ҩ�̣������ڶ���ֺ������ĵĽ��紦����ͨ��
��������ƣ��ַ��Ƕ�˵���ҩ�̵�ҩ����ĺܡ���ҩ���ϵļ��ٸ�
С������ɢ��������һ��ŨŨ��ҩζ�����㼸����Ϣ����˵��ҵ���
��һ�ֺ����ܵ�ҩ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"dongdajie1",
]));

        set("objects", ([
                __DIR__"npc/moyixin" : 1,
        ]));

	setup();
}
