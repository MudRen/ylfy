// Room: /d/quanzhou/huangye.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "��Ұ");
    set("long", @LONG
������Ȫ�ݽ���Ļ�Ұ�ϣ���ʱ��һ���󺣷�����洵��������ͨ��
�Ϸ���һ��Ȫ�ݣ�������һ��С��塣
LONG
    );
    set("outdoors", "quanzhou");
    set("no_clean_up", 0);
    set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"nanmen",
  "south" : __DIR__"yucun",
]));
    setup();
    //replace_program(ROOM);
}

void init()
{
	object me=this_player();

	if(userp(me))
	add_action("discmds",({"touxi"}));
}

int valid_leave(object me, string dir)
{
	object ob;
	me=this_player();

	if(dir=="south")
	{
		if(!me->query("xy_huiyuan") && me->query("combat_exp") < 200000)
			return notify_fail("���ʵս���鲻�㣬���ǲ�Ҫȥ�������߻��ӵĵط�Ϊ�\n");
		
		if(me->query_temp("apply/name") && userp(me))
			return notify_fail("��ҵ�������������ף����ǲ�Ҫ����ߵĺðɣ�\n");

	ob=first_inventory(me);
    while(ob)
		{
		if (ob->is_character() && !ob->is_corpse() )
			return notify_fail("���ǰ�"+ob->name()+"�ȷ�������ȥ���ΰɣ�\n");
		ob=next_inventory(ob);
		}
	}

	return ::valid_leave(me, dir);
}

int discmds()
{
	tell_object(this_player(),"�󵨣���ҵ���׳���Ҳ�����ף�\n");

	if(!this_player()->is_busy())
	this_player()->start_busy(5);
	return 1;
}
