// Room: /d/cxwxm/cxwx2.c
// This is a room made by roommaker. write by Xyx.

#include <ansi.h> 
inherit ROOM;

void create()
{
        set("short", "����ǰ");
        set("long", @LONG
��һ���ţ������������ı������ѵĴ�ɽ���������滷ɽ������С·ͨ
��ɽ�У�û��ʲô�ر�ľ��£��������е������ƺ�������һЩ��

LONG
);
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/dizi" : 2,
  __DIR__"npc/chuhuan" : 1,
]));
        set("outdoors", "cxwxm");
        set("exits", ([ /* sizeof() == 4 */
  "eastup" : __DIR__"xiwuchang",
  "northup" : __DIR__"xiwuchang2",
  "southup" : __DIR__"xiwuchang3",
  "west" : __DIR__"houmen",
]));

        setup();
}
/*
void init()
{
        object me;
        me=this_player();
        if (wizardp(me)) return 0;
        if (!me->query("jihao",1))
        {
        message_vision(HIC"ͻȻ,��ǰ������һ��Ʊ���ˣ�����һ����ָ��$N��У�\n"NOR
                    CYN"�����������ˣ��������ɵģ���\n"NOR
                    HIR"���̺�ѹѹ��һȺ���������ϵ����˹�������$Nһ���ҿ���\n"NOR,me);
                me->move("/d/cxwxm/tianye");
                me->unconcious();
        } 
}
*/
