//bye enter

inherit ROOM;

void create()
{
        set("short", "СԺ��");
	set("long", @LONG
�����Ǹ�СԺ�ӣ���ɨ����Ϊ���࣬�Ա��пô�����Ժ����
����һЩɨ�ѵ���������Ǹ�����Ŀ�����
LONG
	);

        set("outdoors","chengdu");
	set("exits", ([ 
            "southwest" : __DIR__"xiaodao1",
            "north" : __DIR__"xiaoting",
            ]));

	setup();
	replace_program(ROOM);
}
