// Room: /d/quanzhou/yucun.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "С���");
    set("long", @LONG
һ����ľ����ǳ�����㼸ʮ��Զ�ĺ�̲�ϣ���ˮ������Ĵ��ź�����
��ֻ��Ÿ����������Χ���㼫ĿԶ����������ȴ������һ���洬��
LONG
    );
    set("objects", ([ /* sizeof() == 1 */
  "/d/npc/salt_seller" : 1,
]));
    set("no_clean_up", 0);
    set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"huangye",

]));
    set("outdoors", "quanzhou");
    setup();
    //replace_program(ROOM);
}

void init()
{
	object me=this_player();

	if(userp(me))
		add_action("discmds",({"pretend"}));
}

int discmds()
{
	tell_object(this_player(),"��ҵ�������������ף����ǲ�Ҫ����ߵĺðɣ�\n");

	if(!this_player()->is_busy())
		this_player()->start_busy(5);
	return 1;
}
