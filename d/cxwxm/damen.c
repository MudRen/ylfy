// Room: /d/cxwxm/damen.c
// This is a room made by roommaker. write by Xyx.

inherit ROOM;

#include <ansi.h>
void create()
{
        set("short", HIC"����"NOR);
        set("long",
    "����ǡ����������š��Ĵ��š��������ſڵ����ң�һ�߶�ߵ��ż�\n"
"����һ���ͻ���Ϊ��ֻ������һ��ĺ�լ��������Ī���ļž�������ë��\n"
"�Ȼ��\n\n"
);
        set("exits", ([ /* sizeof() == 1 */
        "west" : __DIR__"cxwx",
        "east" : __DIR__"gc",
]));

        setup();
}
void init()
{
        int n;
        object me;
        me=this_player();
        n = (int)me->query("combat_exp");
        if ((me->query("family/family_name") == "����������"))
         {
        if  (((int)me->query("dex") < 20) || ((int)me->query("kar")< 25)||(n<100000))
         {
         message_vision(HIR"����$N�������飬���ż�һ�裬����һ�������ڵء�\n"NOR,me);
         me->delete("jihao");
          }
         else
         {
         me->set("jihao",1);
          }
         }
         return;
}


