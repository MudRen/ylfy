
#include <ansi.h> 
inherit ROOM;

void create()
{
     set("short", HIY"����"NOR);
     set("long", @LONG 

���������ϣ���ͻȻ������Ҷ����Щ�������ۡ�����������!!!
LONG
);
     set("outdoors","��Ĺ");

     set("exits", ([ 
     "down" : __DIR__"xuanya",
         ]));

             setup();
        replace_program(ROOM);       

} 

