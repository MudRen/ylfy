//ROOM men1.c
inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", "�鷿����");
        set("long",@LONG
�����鷿�ſڣ�ֻ����������������һ������(duilian)��̧ͷ������
�����һ�����(bian)��д�ż������֡�
LONG
        );
        set("outdoors", "lingjiu");
        set("exits", ([
        "east" : __DIR__"shufang",
        "west" : __DIR__"changl12",
        ]));
    set("objects",([
        __DIR__"npc/zhujian" : 1,
    ]));
    set("item_desc", ([
        "duilian" : "�е�ˮ�����������ʱ.\n",
        "bian" : HIC "������ң\n" NOR,
        ]));
    setup();
}
int valid_leave(object me, string dir)
{
    object ob;
    ob=present("zhu jian", environment(me));
    if (ob && living(ob)){
        if (  (dir == "east") && ((string)me->query("family/family_name") != "���չ�") )
            return notify_fail  ("��������ס�㣬˵�������Բ��𣬱����صأ���أ���\n");
    }
    return ::valid_leave(me, dir);
}