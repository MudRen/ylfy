
inherit ROOM;
#include <ansi.h>
void create()
{
     set("short",HIG"������"NOR);
     set("long", @LONG
�˵�����ȫ��������ţ�һ��ߴ���Ʒ������ڰ�ɽ�Ŀ������ϣ�ȫ���
�����µ�ʿ�ڴ˷����������ʴ˴�����������ƣ�����������Ů���Ĺ����
�����ġ�
LONG        );

     set("outdoors","��Ĺ");

     set("exits", ([
         "southdown" : __DIR__"jlg",
         "westdown" : __DIR__"shanlu3",
     ]));
        set("objects", ([
                "/d/wudang/npc/guest" : 2, 
   ]));

     setup();
}


