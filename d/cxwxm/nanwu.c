// Room: /d/cxwxm/nanwu.c
// marry 99.8
inherit ROOM;

#include <ansi.h>
void create()
{
        set("short",HIC"����"NOR);
         set("long",
"������ǳ��������ŵĵ�����ȡ���ŷ�װ�ĵط�������\n"
"���Ӳ�����Ů��������������(ling)��һ�׵��ӷ���\n\n"
);
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"gc",
]));
        set("objects", ([
        __DIR__"npc/long" : 1
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
        add_action("do_ling", "ling");
}
*/
int do_ling(string arg)
{
       object me;
       object cloth;
       me=this_player();
              if (me->query("family/family_name") != "����������")return notify_fail("���꽿˵������������Ǳ��ŵ��ӣ���\n");

       if (arg)  return notify_fail("���꽿˵������������ֻ�е��ӷ�����\n");
       if (cloth = present("cloth", me)) return notify_fail("���꽿˵�������㲻���Ѿ������𣿡�\n");
        message_vision("���꽿�ݸ�$Nһ�����ӷ���\n",me);
        cloth=new(__DIR__"obj/cloth");
        cloth->move(me);
       return 1; 
}

