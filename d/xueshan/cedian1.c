//      cedian1.c ���
//      Designed by secret (����)
//      97/04/09
#include <room.h>
inherit ROOM;
void create()
{
        set("short","���");
        set("long",@LONG
������ѩɽ�µĶ�����������̬�����ʮ���޺�����
LONG
        );
        set("exits",([
                "up" : __DIR__"zoulang1",
                "west" : __DIR__"dadian",
        ]));
        set("objects",([
                CLASS_D("xueshan")+"/jiamu" : 1,
                __DIR__"npc/xiang-ke" : 1,
        ]));
        setup();
}
int valid_leave(object me, string dir)
{
    object ob;
        mapping myfam;
    ob=present ("jiamu huofo" ,environment(me) );
    if (objectp(ob) && living(ob)){
            myfam=(mapping)me->query("family");
            if( (!myfam || myfam["family_name"] !="ѩɽ��") && dir=="up") 
                    return notify_fail("��ľ���˵�� : ���ѩɽ�µ��� ,��������!! \n");
    }
        return ::valid_leave(me,dir);
}
