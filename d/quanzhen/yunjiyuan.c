// yunjiyuan.c �Ƽ�԰

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "�Ƽ�԰");
        set("long", @LONG
�������Ƽ�԰������С������԰��̨ͤ��鿣���ɽ���䣬���ﻨ�㣬
ʮ���ľ���ȫ�����ӳ�����Ʒ���۽���Ҳ��ʱָ�����µ��ӡ������ǰ�
��ͤ����������԰��
LONG
        );
        set("outdoors", "quanzhen");

        set("exits", ([
                "northwest" : __DIR__"baguating",
                "east" : __DIR__"xiaolu3",
                "southeast" : __DIR__"neiyuan",
        ]));
        
        
        setup();
        
}
int valid_leave(object me, string dir)
{
        mapping fam;

        if (dir == "southeast")
        {
                if( mapp(fam = me->query("family")) 
                &&  fam["family_name"] == "ȫ���" 
                &&  fam["generation"] == 3  ) 
                        return ::valid_leave(me, dir);
                
                if( me->query("guilty") == 0 
                &&  !wizardp(me) )
                {
                        return notify_fail("���ʸ񲻹������ܽ���԰��\n");
                }
        }
        return ::valid_leave(me, dir);
}

