
inherit ROOM;
#include <ansi.h>
void create()
{
     set("short", HIG"������"NOR);
     set("long", @LONG
���������ң��㲻������������û�м�������ʵ�������ʵǡ��Ⱨ������
��������֣�����һ�����˱��Ÿ�����һ�㡣���񹤣�׿Ȼ��ɣ�����̾����
LONG        );

     set("outdoors","��Ĺ");

     set("exits", ([
         "eastdown" : __DIR__"ryy",
         "southup" : __DIR__"lyy",
         ]));

//     set("objects", ([
//              __DIR__"obj/limochou" : 1,
//      ]));

     setup();
}

