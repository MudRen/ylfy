
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
�����ǶĶ�ʮһ��ĵط����и��ܿ��˧�����������ţ���
�ﲻͣ�ؽ���ʲô�������Ÿ�ī����һ�����侲�����ӡ�ǽ��Ҳ
���Ź���˵��(rule)��
LONG
        );

        set("exits", ([
                "west" : __DIR__"daxiao",                
        ]));
        set("no_fight",1);

        set("item_desc",([
             "rule" : "����������������еĶ�ʮһ�㣬10��\n"+
                      "J��Q��K����ʮ�㣬A��ʮһ�㣬ÿ����\n"+
                      "ѹ�����ƽ�ף����ˣ�:)\n"
                 ]));
        set("objects",([
                __DIR__"npc/fazai" : 1,
        ]));

                            
        setup();
        replace_program(ROOM);
}


 
