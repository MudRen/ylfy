
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
������ǶĴ�С�ĵط��ˣ��и����������Ļ�С�Ӳ�����
��ض������Ǯ����ǽ�������Ź���˵��(rule)��
LONG
        );

        set("exits", ([
                "west" : __DIR__"duchang",
                "east" : __DIR__"ershi",                
        ]));
        set("no_fight",1);

        set("item_desc",([
             "rule" : "���������Ǯ������ĵط�����С��\n"+
                      "�Ͻ�������Ҫ�����ȸ�Ǯ�������С\n"+
                      "Ϥ�����㣬Ҳ������ѹ����Ǯ��\n"
                 ]));
        set("objects",([
                __DIR__"npc/xingge" : 1,
        ]));

                            
        setup();
        replace_program(ROOM);
}


 
