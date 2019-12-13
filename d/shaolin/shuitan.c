// Room: /d/shaolin/hantan3.c
#include <room.h>
inherit ROOM;
void create()
{
    set("short", "��ˮ��̶");
    set("long", @LONG
ֻ��̶ˮ�峺��������һ�����һ�㣬һ�Ҿ޴���ٲ�
������������Խɽ��ֱй���£���������̶֮�У���ˮ��
�ϻ�����һ�㱡�����������۲�ɢ�����ɾ�һ�㡣��̶ˮ
����ף�Ҳ��֪������̶֮�������һ�����¡�̶����һ
����񣬲�֪�Ǻ��˺�ʱ���̣���ȷ���������ľ����ԣ�Ҳ
���ǳ���������̶֮�������֮������Ե�ʰɡ�
LONG
    );
    set("exits", ([
        "west" : __DIR__"shijie5",
    ]));
    set("outdoors", "shaolin");
    setup();
}
void init()
{
    add_action("do_ketou", "ketou");
//  this_player()->set_temp("shui", 0);
    add_action("do_daoshui", "daoshui");
}
int do_ketou(string arg)
{
    object tong;
    message_vision("$N�ϵع����������������һ��ͷ��\n", this_player());
    
    if ((int)this_player()->query_skill("dodge", 1) >= 30 
    && (int)this_player()->query_skill("dodge", 1) <= 100 )
    {
        tong = new("d/shaolin/obj/tong");
        tong->move(__DIR__"shuitan");
        this_player()->set_temp("shui", 0);
        message_vision("ڤڤ֮�У����ƺ����÷����ڵ㲦�����Ṧ��������ѡ�\n", this_player());
        return 1;
    }
    return notify_fail("���ʲôҲû������\n");
}
int do_daoshui(string arg)
{
    object me;
    int i, jing_cost, qi_cost;
    me = this_player();
    i = (int)me->query_skill("dodge", 0) + random(200);
    jing_cost = 600 / (int)me->query_int();
    qi_cost = 500 / (int)me->query_int();
    if(((int)me->query("jing") < jing_cost) || ((int)me->query("qi") < qi_cost))
        i = 0;
    if ( !me->query_temp("shui") || (me->query_temp("shui") == 0 ))
        return notify_fail("��Ͱ��û��ˮ����֪������Ҫ��ʲô��\n");
    
    if ( me->query_temp("shui") == 1 )
    {
        me->improve_skill("dodge", 2*(int)me->query_skill("dodge", 1));
        me->receive_damage("jing", jing_cost );
        me->receive_damage("qi", qi_cost );
        me->set_temp("die_for","��ˮ��");
        me->delete("last_damage_from");
        me->delete_temp("shui");
        return notify_fail("���Ͱ���ˮ��������̶�\n");
    }
}
