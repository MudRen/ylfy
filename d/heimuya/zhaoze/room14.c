
inherit ROOM;
void create()
{
	set("short", "���˲���");
	set("long", @LONG
����ǰͻȻһ����ԭ�����߽���һ�����˲��䡣������Χ���ڻ�
�ѱߣ���ɫ�ϣ���������ĳ�ּ�����ʽ��������ʿ������ľ�ۣ���
�������дʡ�ͻȻ�����Ǻ��������㡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"room16",
  "east" : __DIR__"room15",
]));

        set("objects",([
                        __DIR__"npc/wushi": 4,        
        ]));
	setup();
	replace_program(ROOM);
}
