// Room: /d/cxwxm/menglong.c
// marry 8,21
inherit ROOM;

#include <ansi.h>
void create()
{
        set("short",HIC"������"NOR);
        set("long",
"������������Ĵ�ʦ�־�ס�ĵط������˰ڷŵ����߱Ƚ��ݳ�����\n"
"��ûɶ����������ˡ������ŵ�����ǽ�Ϲ���һ����ͷ��������������\n"
"��ʲô"HIW"���"HIB"����"NOR"�������ߴ�����Щ���ţ�Ҳ����������˵�ƫ���ɡ�\n\n"
 );
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"dating",
]));
        set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/liang.c" : 1,
  __DIR__"npc/puren.c" : 2,
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
