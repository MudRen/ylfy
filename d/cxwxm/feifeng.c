// Room: /d/cxwxm/feifeng.c
// This is a room made by roommaker. write by Xyx.

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�ɷ���");
        set("long", @LONG
���Ǳ��������Ļ���ң���������ȴ�����鷿����ǽ�ڷ���һ�����,
�����������İ���һЩ�顣��������Ÿ���������Щ���ϵ�̴ľС������
����һ�Ѿ��µ�С���ͼ��������С�豭��

LONG
);
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"dating",
  "west" : __DIR__"feifeng2.c",
]));
        set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/feng" : 1,
  __DIR__"npc/yahuan" : 2,
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