// Room: /d/shaolin/fumoquan.c
// Date: YZC 96/01/19
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "��շ�ħȦ");
    set("long", @LONG
���ô������������ϸ����˸�������һ�˵Ĵ󶴣��и�����
¶����ɫɮ��һ�ǣ��ƺ�ס�����ˡ�������һƬ���ƺ�����Ĵ�
��ͺͺ�ģ��ƺ������ܴ����������´�ݲ�����
LONG
    );
    set("exits", ([
        "out" : __DIR__"qyping",
    ]));
    set("objects",([
        CLASS_D("shaolin") + "/du-nan" : 1,
        CLASS_D("shaolin") + "/du-e" : 1,
        CLASS_D("shaolin") + "/du-jie" : 1,
    ]));
    setup();
}
void init()
{
    object ob1,ob2,ob3;
    ob1=present("du nan",this_object());
    ob2=present("du jie",this_object());
    ob3=present("du e",this_object());
    if (!ob1 && !ob2 && !ob3)    return;
    if( interactive( this_player()) ) {
        if ( this_player()->query("family/family_name") == "������" 
        && this_player()->query("family/generation") == 36 ) return;
        else
    message_vision(HIR "ͻȻ�侢���ݺᣬ��������������������͵ع�����˲�����
����һ�����Եı��У��糤ì����˰������������ֱ���$N��ͷ��
�أ�������Ҫ�����̶�����$NһƳ�䣬����������ɮ�־�������
��֮�У���ȫ���ֱ���$N������$N��������������֮�̺����Ͻ�
ħ�󷨵Ľ�շ�ħȦ��\n\n" NOR, this_player());
    }
    if (this_player()->query("family/generation") > 2 
    && this_player()->query("family/family_name") == "������" 
    && this_player()->query("qi") < 300 ) 
    {
        message_vision(HIR "$N��һ����ɽ������ľ������У���ʱ���˳�ȥ !\n" NOR, this_player());
    }else
        this_player()->set_temp("on_time",time());
}
int valid_leave(object me, string dir)
{
    
    if( dir == "out"){
        if (time()-me->query_temp("on_time")<(random(10))
        && me->query_temp("fighter",1) )
                return notify_fail("�����ݷ�ħȦ����������!\n");
        me->delete_temp("on_time");
        if ( present("puti zi", me) )
                return notify_fail("����˵��: ���ܴ����������뿪��ħȦ !\n");
        me->delete_temp("fighter");
    if(me->query_temp("marks/no_putizi"))
       me->delete_temp("marks/no_putizi");
      me->set_temp("dex",me->query_temp("old_dex"));
      me->delete_temp("old_dex");
    }
    return ::valid_leave(me, dir);
}

