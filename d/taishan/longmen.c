// Room: /d/taishan/.c
// Date: CSWORD 96/03/25
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "����");
    set("long", @LONG
�������̩ɽʮ���̵���㡣�˴�ɽ�ƶ��ͣ���ɽ����һ����
С�ĺ����ױ����鵽�¹�֮�С�
LONG
    );
    set("exits", ([
        "northup" : __DIR__"shengxian",
        "southdown" : __DIR__"wudafu",
    ]));
    set("outdoors", "taishan");
    setup();
}
void init()
{
    object me = this_user();
    
    if( random((int)me->query_skill("dodge")) <= 80) 
    {
         if ( (int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance()<18) return;
        me->receive_damage("qi", 50);
        me->receive_wound("qi",  50);
        message_vision(HIR"$Nһ��С�Ľ���̤�˸��գ�... ��...��\n"NOR, me);
        me->move(__DIR__"daizong");
        tell_object(me, HIR"���ɽ�Ϲ���������ֻ���û����޴����ۣ������˼����ˡ�\n"NOR);
        message("vision", HIR"ֻ��" + me->query("name") + "��ɽ�Ϲ�µµ�ع������������ڵ��ϰ�������������\n"NOR, environment(me), me);
    }
}
        
