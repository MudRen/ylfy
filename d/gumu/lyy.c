
inherit ROOM;
#include <ansi.h>
void create()
{
     set("short",YEL"������"NOR);
     set("long", @LONG
ɽ���˴���Ȼ��խ�������ľ����ضٰ���ӭ����һ����ʯ��������״��
ɭ�ɲ����Կ�ƾ�٣�����һ�������������ӡ�˵�����Ĺ����������Һ�����
��֪���ж���ɱ����
LONG        );

     set("outdoors","��Ĺ");
    
     set("exits", ([
         "east" : __DIR__"shulin1",
         "northdown" : __DIR__"bzy",
         "northup" : "d/quanzhen/baoquan",
       ]));
     
     setup();
}
int valid_leave(object me, string dir)
{
        if (dir=="east" )
        {
        if(me->query("can_ride"))
                {
                                        return 0;

                }
        
        if(me->query_temp("ride_horse"))
        return notify_fail("���澣������������������\n");
        }
        return ::valid_leave(me, dir);
}

