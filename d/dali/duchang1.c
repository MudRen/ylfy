// Room: /d/dali/duchang1.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��19�գ�����ʱ�䣺21ʱ30��46�롣

inherit ROOM;

void create()
{
set("short", "�ķ�");
	set("long", @LONG
����˵���˵ĵط����жĳ�������һ��Ҳ���������Ǵ������
�Ķĳ������÷ǳ�����,������������ϰ�׬�˲��١��ſ�վ�ż���
�꺴�Ĵ��֣������������ﵷ�ҵ��˲��ࡣ͸�������Ǻ������Ӳ�
��ʱ������Ů�Ľ�Ц����ׯ�ҵ�ߺ������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"duchang2",
  "east" : __DIR__"nandajie1",
]));

         set("objects", ([
                    __DIR__"npc/dashou" : 2,
        ]));
setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "west" && this_player()->query("age")<18)
                return notify_fail("Сë���������Ϲ�պ�ʲô?!\n");
        return ::valid_leave(me, dir);
}
