
inherit ROOM;
#include <ansi.h>

void create()
{
     set("short",HIG"���С��"NOR);
     set("long", @LONG
����ɽ�µ�С��������ȫ���ƽ�����������ɽ��ȫ���ɵ������������죬
����һ�����������ٰ��ճ��������Ҳ����������ʿ������䡣
LONG        );

     set("outdoors","��Ĺ");

     set("exits", ([
         "northup" : __DIR__"xiaolu2",
         "southdown" : __DIR__"shanjiao",
     ]));

     setup();
}
