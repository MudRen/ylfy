// dating.c
// marry 8.20
inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", HIC"����"NOR);
    set("long", 
        "������ǳ��������ŵĴ����ˡ��ڴ������������һ����\n"
        "�ң��������ݵ����š�"HIY"�� �� �� �� ��"NOR"������˶��Ľ��֡���\n"
        "�ҵ��·�����������������һ��Ϊ��"HIM"��"HIG""BLINK"��"NOR""HIC"����"NOR"����������һ\n"
        "��ȴ�ǡ�"HIR"����"HIW""BLINK"��"NOR""HIB"��"NOR"����\n\n");
    set("valid_startroom", 1);
        set("no_fight", 1);
        set("no_steal", 1);
        set("no_sleep_room",1);
    set("exits", ([
       "north" : __DIR__"fanting.c",
        "west" : __DIR__"feifeng.c",
        "east" : __DIR__"menglong.c",
       "south" : __DIR__"dayuan.c",
]));
set("objects", ([
                __DIR__"npc/mylover.c" : 1,
        ]));

    setup();
    //"/clone/board/cxwxm_b.c"->foo();
}
/*
void init()
{
        int n;
        object me;
        me=this_player();
        n = (int)me->query("combat_exp");
        if (wizardp(me)) return 0;
        if ((me->query("family/family_name") == "����������")&&((int)me->query("cps")>= 20) && ((int)me->query("kar")>= 25)&&(n>=100000))
        {
         me->set("jihao",1);
         return 0;
        } 
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
