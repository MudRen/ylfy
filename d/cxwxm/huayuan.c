// Room: /d/cxwxm/huayuan.c
// marry 8,14
inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short",HIC"��԰"NOR);
        set("long", 
"�����ǰ������һ�������Ĵ�԰����԰����������ͷ׵Ļ���������\n"
"��˸�����ٻӰ�����Ǳ��ŵĽ��á���԰������һ����ˮ�أ�һ���ļ�ˮ��\n"
"����ӿ����˭����֪����ˮ�Ӻζ�������԰����������Ǳ��ŵĴ�Ժ��\n\n" 
);
        set("outdoors","cxwxm");
        set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"dayuan",
]));
        set("objects",([
                "/d/cxwxm/npc/nvdizi":2,
               "/d/cxwxm/npc/qian":1,
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
