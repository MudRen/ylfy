
inherit ROOM;
#include <ansi.h>
void create()
{
     set("short", HIY"������"NOR);
     set("long", @LONG
��ȥ��·��Ȼ�վ�����ʯ���£��������ϡ��ߴ�ɭȻ��Խ����ʯ��ң���
Ӧ��һʯ��Բ�������գ�һʯ����������¡��������������ڡ�
LONG        );

     set("outdoors","��Ĺ");

     set("exits", ([
         "northdown" : __DIR__"jlg",
         "westup" : __DIR__"bzy",
       ]));
        set("objects", ([
                "/d/wugongzhen/npc/youke" : 2, 
   ]));
     setup();
}

