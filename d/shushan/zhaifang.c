//����ɽ�ɡ�mhxy-yushu 2001/2
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","ի��");
	set("long", @LONG

��������ɽ���ɵ�ի��,����������С·�������������к�
��óԵġ�����ӵ����տ������ܲ����������ҪЩ(yao)
�Եġ�
LONG);
        
       set("no_fight",1);
       set("exits", ([
	  "east" : __DIR__"westway2",
	]));

        set("objects", ([         
        __DIR__"npc/chuzi" : 1,
        "/clone/food/jiudai" :1,
        ]));
       set("clean_up", 1);
       set("resource", ([        
       "water" : 1,
       ]));
      setup();
}
int valid_leave(object me, string dir)
{
       if((present("gongbao jiding", this_player())))
            return notify_fail("�������������\n");
            if((present("hulu", this_player())))
            return notify_fail("�㲻�ܰѾƴ����ߣ�\n");
             return ::valid_leave();
}


