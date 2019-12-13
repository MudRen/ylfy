
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�Ŀ�");
        set("long", @LONG
�����ǶĶ�ʮһ��ĵط����и��ܷʵĺ������������ţ���
�ﲻͣ������������ʲô��һ�����侲�����ӡ�ǽ��Ҳ���Ź���
˵��(rule)��
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([
                "west" : __DIR__"duchang",         
        ]));
        set("no_fight",1);
        set("no_magic",1);
        set("freeze",1);

        set("item_desc",([
            "rule" : "����������������еĶ�ʮһ�㣬10(T)��J��Q��K����ʮ�㣬\n"+
                     "A��һ���ʮһ�㣬ÿ�������ѹ10���ƽ�ף����ˣ�:)\n"+
                    "����Ľ���̫��̫�أ��뻻��huan��Ϊ��Ʊ����\n"
                 ]));
        set("objects",([
                __DIR__"npc/qianjinbao" : 1,
        ]));

                            
        setup();
}

int valid_leave(object me, string dir)
{
        if (!userp(me))         return ::valid_leave(me, dir);
        if (present("qian jinbao",environment(me))){
           if ( me->query_temp("tmark/Ѻ") && dir == "west" )
              return notify_fail("Ǯ�����ܵ��ű���ס�����Ѿ�����ע�ˣ����᲻�ľ�������!��\n");
        }
        return ::valid_leave(me, dir);
}


 
