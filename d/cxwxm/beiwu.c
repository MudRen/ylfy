// Room: /d/cxwxm/beiwu.c
// This is a room made by roommaker. write by Xyx.

inherit ROOM;

#include <ansi.h>
void create()
{
        set("short",HIC"����"NOR);
        set("long", 
"��һ���ݱ㿴��һ���ű�������������ķ��ڵ��ϣ�������\n"
"��ʽ�ı�����ԭ�������ǳ��������ŵı����ҡ�\n\n"
);
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"gc",
]));
        set("no_fight",1);
        set("objects", ([
        __DIR__"obj/axe" : 2,
        __DIR__"obj/whip" : 2,
        __DIR__"npc/xiaojin" : 1
        ]));

        setup();
}
/*
void init()
{
        object me;
        me = this_player();
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