//      cedian2.c ���
//      Designed by secret (����)
//      97/04/09
inherit ROOM;
void create()
{
        set("short","���");
        set("long",@LONG
������ѩɽ�µ�����ǽ��������ŷ��洫���Ĺ��¡�
LONG
        );
        set("exits",([
                "up" : __DIR__"zoulang2",
                "east" : __DIR__"dadian",
        ]));
        set("objects", ([
                CLASS_D("xueshan")+"/samu" : 1,
                __DIR__"npc/xiang-ke" : 1,
        ]));
        setup();
}
int valid_leave(object me, string dir)
{
    object ob;
        mapping myfam;
    ob=present ("samu huofo" ,environment(me) );
    if (objectp(ob) && living(ob)){
            myfam=(mapping)me->query("family");
            if( (!myfam || myfam["family_name"] !="ѩɽ��") && dir=="up") 
                    return notify_fail("��ľ���˵�� : ���ѩɽ�µ��� ,��������!! \n");
    }
        return ::valid_leave(me,dir);
}
