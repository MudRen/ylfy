//����ɽ�ɡ�mhxy-yushu 2001/2
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short","����������");
	set("long", @LONG

  ������ɽ��һ�������ε������������ﾲ���ĵģ������ڳ��У�û����
��ͷ����һ�ۣ����ھ۾�����������Լ��Ĺ���
LONG);
        set("exits", ([
           "west" : __DIR__"midao1",
	]));
         set("objects", ([ 
             __DIR__"obj/muren" : 4,
             __DIR__"npc/dizi" : 1,
             __DIR__"npc/dizi1" : 1,
       ]));
        setup();
}

