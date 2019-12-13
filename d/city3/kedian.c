// by enter
// modified by wind
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "���տ͵�");
        set("long", 
"������һ�����ֺŵĿ�ջ��ո�µ������ŵ������룬����һ\n"
"��������������һ�������������������ǿ�ջ�ĳ��������ϱ�\n"
"��ǽ�ڱ�����һ��ͨ����¥��¥�ݣ��ſ�һ���̽�Ĵ�������д\n"
"���ĸ����֡����տ�ջ����"HIG"���滹�и���Ժ��������������ֱ\n"
"�ӻ�����ȥ��"NOR"ǽ�ϻ��и����ӡ�(paizi)\n"
        );

        set("no_roar", 1);
        set("no_steal", 1);
        set("valid_startroom", 1);
        set("no_sleep_room",1);

        set("item_desc", ([
                "paizi" : "���տ͵꣬ȫ����������ȫ���ʣ�������顣\n"
                          "���������۸����飬����С����ϵ��\n",
        ]));

        set("objects", ([
                __DIR__"npc/qiuwa" : 1,
        ]));

        set("exits", ([
                "south" : __DIR__"dongjie1",
                "up" : __DIR__"kedian2",
        ]));

        setup();
//       "/clone/board/cdkd_b"->foo();
}
int valid_leave(object me, string dir)
{
        if (!userp(me))         return ::valid_leave(me, dir);
        if (present("qiu wa",environment(me))){
                if ( !me->query_temp("rent_paid") && dir == "up" )
                        return notify_fail("����һ�µ���¥��ǰ������һ�����ٺ٣���ס������\n\nһ��Ҫ�������ӵ�Ү��\n");
                if (!NATURE_D->outdoor_room()  && dir == "up" )
                        return notify_fail("����һ�µ���¥��ǰ��������˯ʲô�����ͷ��ڴ�ɨ�أ�\n");
                if ( me->query_temp("rent_paid") && dir == "south" )
                        return notify_fail("�����ܵ��ű���ס���͹��Ѿ�����Ǯ�ˣ����᲻ס��������أ�\n���˻���ΪС���ź����أ�\n");
        }
        return ::valid_leave(me, dir);		
}

