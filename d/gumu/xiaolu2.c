
inherit ROOM;
#include <ansi.h>
void create()
{
     set("short",HIG"���С��"NOR);
     set("long", @LONG
����ɽ�µ�С��������ȫ���ƽ�����������ɽ��ȫ���ɵ������������죬
����һ�����������ٰ��ճ��������Ҳ����������ʿ������䡣���ϱ���һ��
���㳡��
LONG        );

     set("outdoors","��Ĺ");

     set("exits", ([
         "north" : __DIR__"xiaolu1",
         "south" : __DIR__"xiaolu3",
         "southeast" : __DIR__"gchang",
      ]));

     setup();
}

