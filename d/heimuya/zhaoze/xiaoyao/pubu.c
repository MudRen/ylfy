// pubu.c 
// shilling 97.2
inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", "�ٲ�");
    set("long", @LONG
��������ˮ�����������¡¡�����糱ˮ����һ�㣬̧ͷһ����ֻ��һ
�����ٲ����������ӵ������Ӹ�����ֱк�������±��ϳ���ЩС����������
��������Ԩ��������������������ͷ. . . .
LONG    );
    set("outdoors", "xiaoyao" );
    set("no_clean_up", 0);
    setup();
}
 
void init()
{
    add_action("do_jump","jump");
    add_action("do_climb","climb");
}
int do_jump(string arg)
{
    object ob;
    ob = this_player();
        if( !arg || arg=="" ) return 0;
        if( arg != "down" )
        return notify_fail("����Ҫ������ɱ����ô�벻������\n");
    tell_object(ob, HIR"�㲻��˼��������һԾ�����������¡�������\n"NOR);
    message("vision", NOR"ֻ��" + ob->query("name") + "�����ң���������������֮�С�������\n"NOR, environment(ob), ob);
    if((random((int)ob->query_kar()) < 10 ) && ((int)ob->query_skill("dodge")<30) )
    {
        ob->die();
        return 1;
    }
    ob->set("qi", -1);
    ob->move(__DIR__"yanfeng");
    return 1;
}

int do_climb(string arg)
{
    object me;
    me = this_player();
        if( !arg || arg=="" ) return 0;
        if( arg != "up" )
        return notify_fail("����Ҫ��ȥ�ǣ�\n");
    if ((int)me->query_skill("dodge",1) < 600 ) {
        message_vision("ֻ��$Nץ���±��ϵ�С��������Ҫ����ȥ����Ȼһ�����ȣ�����������\n", me); 
    me->set("qi", -1);
    return 1;
    } else           
        message_vision("ֻ��$Nץ���±��ϵ�С������������������ȥ��\n", me);
          me->move("/d/heimuya/zhaoze/pubu");
    return 1;    
}
