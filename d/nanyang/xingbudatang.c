// xingbudatang.c  �̲�����
#include <room.h>
inherit ROOM;
string look_sign(object me);
void create()
{
        set("short", "�̲�����");
        set("long", @LONG
��������վ���̲�������������ƹܸ����̷��ĵط���
    �����ſڵĵط���һ����ľ��ɵ�����(sign)��
LONG
        );
        set("exits", ([
                "east" : __DIR__"yamen-datang",
         ]) );
        set("objects", ([
                __DIR__"/npc/kuli" : 1,
        ]));
        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );
 
        setup();
}
string look_sign(object me)
{
        return "�����ʦ��¼��\n���PK��¼��(Not ready yet)\n���͵�Լ�¼��(Not ready yet)\n";
}
int valid_leave(object me, string str)
{
    if( me->query_temp("fee_paid") ) 
        me->delete_temp("fee_paid");
    return 1;
}
