// cangjingge1.c �ؾ���

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "�ؾ���һ¥");
        set("long", @LONG
�����ǲؾ���һ¥����ǽ�Ǽ�����ܣ������˵��̵ĵ伮������
��һ�������εĴ����ӣ�����Ҳ�������顣������ͯ���������鼮��
LONG
        );

        set("exits", ([
                "out" : __DIR__"cangjingge",
                "up" : __DIR__"cangjingge2",
             ]));
        set("objects", ([
"/d/quanzhen/npc/daotong" : 2]));

        setup();
        
}
int valid_leave(object me, string dir)
{

        if( !present("letter", this_player()) && me->query("family/master_id")!="master qiu"        && (objectp(present("dao tong", environment(me)))) )
        {
                if (dir == "up" )
                {
                        return notify_fail("��ͯ˵��: ��δ����ɣ������϶�¥��\n");
                }
        }
        return ::valid_leave(me, dir);
}


