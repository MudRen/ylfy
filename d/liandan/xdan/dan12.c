inherit ITEM;
#include <ansi.h>
void init()
{
        add_action("do_eat", "eat");
}
void create()
{
    set_name( HIY "�ɵ�" NOR, ({"xian dan","xian","dan"}));
        set("unit", "��");
        set("value", 0); 
    set("long", "һö���ɫ�ĵ�ҩ�����������ĵĻƹ⡣\n");
        setup();
}
void add_age(object me)
{
    if (me!=environment()) return; 
    message_vision(HIG "����һ��$Nͷ��ð����������������������ȵ�վ��������\n" NOR, me);
    if ( ( me->query("mud_age") / 86400) > 5 ){
    if ( ((int)me->query("mud_age") / 86400)  > 5 - me->query("age_modify") )
    me->add("age_modify",-1);
    else
    me->set("age_modify",-((int)me->query("mud_age") / 86400) + 5 );
    }
    me->set_temp("add_age",0);
    me->update_age();
    destruct(this_object());
}

int do_eat(string arg)
{
    object me;
    me = this_player();
    if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
    if ( me->query_temp("add_age"))  return notify_fail("��Ҫ��ʲô��\n");
     
    message_vision(HIG "$N���ɵ��������ʵ����У���ɫͻȻת�̣�һ�µ����ڵأ�\n" NOR, me);
    tell_object(me,MAG "�㸹����ͬ����һ�����ܣ�ʹ�����ڵ���ֱ�����\n\n" NOR);
    if (me->query("age")<20){
       tell_object(me,HIR"��������������̫С��,�˵�������Ч��\n"NOR);
        destruct(this_object());
        return 1;
     }
     call_out("add_age",1,this_player());
     me->set_temp("add_age",1);
    return 1;
}
void reset(){ }

