//bye enter

inherit ROOM;

void create()
{
        set("short", "�෿");
	set("long", @LONG
��������¼������·����ס�����������࣬ǽ�Ϲ��ŰѴ��ʵ�
������������������һ��ͼ������������ר�ĵؿ���ͼ�ϵ����ݣ���
�������дʡ�
LONG
	);
	set("exits", ([ 
            "east" : __DIR__"zoulang2",
            ]));
        set("objects", ([
            __DIR__"npc/wenfangshan" : 1,
              ]));

	setup();
	replace_program(ROOM);
}
