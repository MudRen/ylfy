// hubudatang.c
#include <room.h>
inherit ROOM;
string look_sign(object me);
void create()
{
        set("short", "��������");
        set("long", @LONG
��������վ�ڻ��������������ר�����˸������ֵĵط���ȫ������
���������������Լ������ֲ������磬���ǵ���������Ǯ������
    �����ſڵĵط���һ����ľ��ɵ�����(sign)��
LONG
        );
        set("exits", ([
                "west" : __DIR__"yamen-datang",
               
         ]) );
        set("objects", ([
                __DIR__"/npc/shuji" : 1,
        ]));
        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );
 
        setup();
}
string look_sign(object me)
{
        return "�������ĸ��մ�����\n";
}
int valid_leave(object me, string str)
{
    if( me->query_temp("fee_paid") ) 
        me->delete_temp("fee_paid");
    return 1;
}
