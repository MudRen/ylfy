// Room: gbdixiaoshi.c
// by aji
inherit ROOM;
void create()
{
        set("short", "�ּ�С��");
        set("long", @LONG
���߽���һ��С�ݡ�����ǽ�ڶ�����������ɣ�������һ���޼ʵ����֡�
��������Ρ����̾�Ϊ���ơ���һ���˱Ƕ����Ĺ�����ζ��ȴ�Ե��������ŵ�
���׸���롣
LONG );
        set("exits", ([ /* sizeof() == 1 */
"west" : __DIR__"gbandao",
"south" : __DIR__"mishi",
]));	
	set("objects", ([
		CLASS_D("gaibang") + "/hong" : 1,
		"clone/weapon/zhubang": 1,
		"clone/food/gourou": 1,
		"clone/food/jitui": 1
	]));
        set("valid_startroom", 1);
        set("no_clean_up", 0);
        setup();
        "/clone/board/gaibang_r"->foo();
}
