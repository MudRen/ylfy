// Room: bwc.c

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "���䳡");
        set("long", @LONG
������ȫ��̵ı��䳡���㳡�����߷���ʮ�˰����������ľ�ˣ�ȫ
����������������Ź棬ÿ���Ϧǰ���գ����µ��Ӵ���书��������һ
�������˵Ľ�����
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"guangchang",
 ]));
        set("no_clean_up", 0);
        set("outdoors", "xxx"); 
        set("objects", ([
"/d/shaolin/npc/mu-ren" : 3, 	
   ]));
        setup();
        replace_program(ROOM);
}

