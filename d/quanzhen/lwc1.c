// Room: lwc.c

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "���䳡");
        set("long", @LONG
������ȫ��̵��ӵ����䳡���㳡�����������˸�ʽ������������е��
�ܶ�ȫ�����������ͷ����������һ��һ�ȵĽ������ϵ�����Ե�ǰ
;���ڵ��Ӷ���ҹ������Ϣ��
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
            "east" : __DIR__"guangchang",
 ]));
        set("no_clean_up", 0);
        set("outdoors", "xxx");

        set("objects", ([
"/d/shaolin/npc/mu-ren" : 3, 	
   ]));
               
        setup();
        replace_program(ROOM);
}

