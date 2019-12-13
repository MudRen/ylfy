inherit ROOM;
#include <room.h>
int doing(object me);
void create()
{
        set("short", "�᷿");
        set("long", @LONG
��С���ţ�����һ��С�����������٣��������ҡ��Ա�һԲ�ʣ�����ԧ��档
�ݽ�ľ���������ϴ����壬�����һ��ԧ��Ϸˮ��
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"corror",
]));
        set("sleep_room", 1);
        set("no_fight", "1");
        set("no_steal", "1");
        set("no_get", "1");
        set("no_bug", "1");

        set("objects", ([
//        __DIR__"npc/chick1" : 1,
                        ]) );

        setup();
        create_door("west", "ľ����", "east", DOOR_CLOSED);
}

void init()
{
    add_action("do_makelove", "makelove");
}

int do_makelove(object arg)
{
        object obj,me;
        object *ob;
        int i;

        me=this_player();
        if (me->query("gender")=="����")
        {
               tell_object(me,"��!���޸����ԣ�����������û��������ˣ�\n");
               return 1;
        }
        if(!arg || !objectp(obj = present(arg, environment(me))))
        {
               tell_object(me,"�����˭����ɽ֮�᣿\n");
               return 1;
        }

        if( !obj->is_character()||me->query("gender")==obj->query("gender") )
                return notify_fail("����...�������²��аɣ�\n");

        if(!living(obj))
                return notify_fail("�˼Ҷ������ˣ��㻹...\n");

        if( !environment(me)->query("sleep_room")||
                 environment(me)->query("no_sleep_room"))
                return notify_fail("�ܵ��Ҹ���ܰ����ĵط��ɡ�\n");

        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++)
                if( ob[i]->is_character()&&ob[i]!=me
                        &&ob[i]!=obj&&!wizardp(ob[i]) )
                        return notify_fail("������б����أ��಻����˼ѽ��\n");
        if(!me->query_temp("makelove/quest"))
        {

            if((me->query("gender")=="����"))
                {
                   message_vision(HIM "$N��������$n���˫�ֻ�����$n�����䣬\n
��$n��������˵�����װ��ģ�����...\n"NOR,me,obj);
                tell_object(obj, HIR "ɵ��Ҳ�ܿ�����������㹲��������\n
�����Ը�⣬����Ҳ��" + me->name() + "("+(string)me->query("id")+")"+ "��һ�� makelove ָ�\n" NOR);
                }
            else
                {
                        message_vision(HIM "��֪����Ϊ��⣬���Ǿƾ����������Ϊ�˷ܣ�$N��С�������ģ�\n
���žƱ���$Nֱ�����ض���$n���װ���...��˵...�Ⱦ�...����...\n"NOR,me,obj);
                tell_object(obj, HIR "ɵ��Ҳ�ܿ�����������㹲��������\n
�����Ը�⣬����Ҳ��" + me->name() + "("+(string)me->query("id")+")"+ "��һ�� makelove ָ�\n" NOR);
                }
                obj->set_temp("makelove/quest",1);

        }
        else
        {
            if((me->query("gender")=="����"))
                {
                        message_vision(HIM "$N�ؾ��ƵĶ���$n���۾�������һ�Բ�����ͻȻһ�ѱ�ס$n��\n
һ˫�ȴ���ס��$n���죬��$n��ֱ�������������Ʊ����������һ��...\n"NOR,me,obj);
                call_out("over", 1, me,obj);
                }
                else
                {
                        message_vision(HIM "$n�����ܿ���$N�ߺ�Ķ�����$N��������$n�Ļ�����\n
ĬĬ�ط�����ԡ��$nȴ��Ҳ�̲�ס��һ�ѽ�$N��������...\n"NOR,me,obj);
                call_out("over", 1, obj,me);
                }
                me->delete_temp("makelove/quest");
        }


        return 1;
}


void over(object me,object obj)
{
        message_vision(HIR"...һ�󼲷����ꡣ\n"NOR,me);
        if(me->query("qi")<30||me->query("jing")<30||obj->query("qi")<30||obj->query("jing")<30)
        {
                if(me->query("qi")<30||me->query("jing")<30)
                {
                    message_vision(HIR "$NͻȻ������Ѫ���ε��ڵء����������������ˡ�"NOR,me);
                    me->unconcious();
                }
                else
                {
                    message_vision(HIR "$NͻȻ������Ѫ���ε��ڵء����������������ˡ�"NOR,obj);
                    obj->unconcious();
                }
        }
        else
        switch(random(10))
        {
        case 0:
                message_vision(HIR "$NͻȻ���һ������Ȼ�Ǽ����˷ܣ������ž�������ȥ��\n"NOR,me);
                me->unconcious();
                obj->add("qi",obj->query_str()-55+random(10));
                obj->add("jing",obj->query_con()-55+random(10));
                break;
        case 1:
                message_vision(HIR "$NͻȻ���һ������Ȼ�Ǽ����˷ܣ������ž�������ȥ��\n"NOR,obj);
                obj->unconcious();
                me->add("qi",obj->query_str()-55+random(10));
                me->add("jing",obj->query_con()-55+random(10));
                break;
        default:
                if(random(1))
                {
                        message_vision(YEL "$N����һ����ͷ�������һ������΢΢������$n��\n
��˵����Ҫ��Ȼ...��������һ��...\n"NOR,me,obj);
                }
                else
                {
                        message_vision(HIY "$n����������$N�Ļ����������������ţ�\n
�����Ǿ��ȵĺ������е����޵��Ҹ�...\n"NOR,me,obj);
                }
                obj->add("qi",obj->query_str()-55+random(10));
                obj->add("jing",obj->query_con()-55+random(10));
                me->add("qi",obj->query_str()-55+random(10));
                me->add("jing",obj->query_con()-55+random(10));
        }
}
int valid_leave(object me, string dir)
{
        if ( dir == "west" )
        me->delete_temp("tmark");
        return 1;
}

