// xiangfang2.c �᷿

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "�᷿");
        set("long", @LONG
��վ��һ�䲻����᷿�У������ɨ�ĺܸɾ�������ǽ��һ����ܣ����Ű�
ʮ��������������䣬������Ŀ�����ǰ����һ���鰸���ķ��ı��ٶ��߱�����
���Ҳ࣬��һ�Ű��������Ϸ���һ������β�ݱ�ɵ����š�
LONG
        );
        
        set("exits", ([
                "west" : __DIR__"neiyuan",
          ]));
           set("sleep_room","1");
           set("no_yun","1");
           set("no_fight","1");
           set("no_steal","1");
        set("coor/x",-90);
        set("coor/y",280);
        set("coor/z",190);
        setup();
        replace_program(ROOM);
}
