//����ɽ�ɡ�mhxy-yushu 2001/2
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","С����");
	set("long", @LONG

  ��������ɽ���ɵ�һ��С����,�����������ɨ�ܸɾ���
����Է��ĵĳԡ����ǵ����տ������ܲ����������ҪЩ(yao)
�Եġ�
LONG);
        
       set("no_fight",1);
       set("exits", ([
          "south" : __DIR__"midao1",
	]));

        set("objects", ([         
        __DIR__"npc/xingxing" : 1,
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


