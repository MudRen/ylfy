
inherit ROOM;
#include <ansi.h>
void create()
{
     set("short",HIY"���㳡"NOR);
     set("long", @LONG
�˴������С������Ǵ��ɹ���ĵط�������Ϸ�Ż�ÿ��������ᣬ����
����ļ�������ƽ���ﳣ�к����ڴ���ˣ���������и�С���С�
LONG        );

     set("outdoors","��Ĺ");

     set("exits", ([
         "northwest" : __DIR__"xiaolu2",
         "southeast" : __DIR__"jishi",
     ]));

     setup();
}

