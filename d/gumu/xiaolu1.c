
inherit ROOM;
#include <ansi.h>
void create()
{
     set("short", YEL"���С·"NOR);
     set("long", @LONG
����һ����£Сİ����������ͨ���ϸڵ�ɽ·��·�ߵ����һƬ�����дУ�
��һ�ɷ��չ⾰��
LONG        );
     
     set("outdoors","��Ĺ");

     set("exits", ([
         "east" : __DIR__"fchuan",
         "south" : __DIR__"xiaolu2",
     ]));

     setup();
}

