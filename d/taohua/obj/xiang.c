// xiang.c
#include <ansi.h>
inherit ITEM;
void init()
{
        add_action("do_array","array");
}
void create()
{
    set_name("������", ({ "buzhen xiang", "xiang" }) );
        set_weight(4000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("value", 0);
        set("jian",5) ;
        set("material", "steel");
        set("long", "�����һ�������ר�õĵ��ߣ��������䡹�������и��ָ�����\n"
                    "���ߣ�������������(array)��\n") ;
    }
    setup();
}
int do_array(string arg)
{
    object me, obj;
    int myexp , objexp ;
    int mylev , objlev ;
    int steps , damage_jing;
    me = this_player();
    if( !arg )
        return notify_fail("�����˭����\n");
    if( this_object()->query("jian") <=0)
        return notify_fail("�����Ѿ��ù��ˡ�\n");
    if (me->is_busy())
        return notify_fail("����æ���ء�\n");
    if (environment(me)->query("freeze"))
       return notify_fail("���ﲻ���ò����䡣\n");
    if(!objectp(obj = present(arg, environment(me))))
        return notify_fail("����û������ˡ�\n");
    if( !obj->is_character() || obj->is_corpse() )
        return notify_fail("�����һ�㣬�ǲ����ǻ��\n");
    if(obj == me)
        return notify_fail("������ɱ�� :P\n");
    myexp =  me -> query ("combat_exp" )/20 ;
    objexp = obj -> query ("combat_exp" )/20 ;
    mylev =  me -> query_skill("qimen-wuxing" )+1 ;
    objlev = obj -> query_skill("qimen-wuxing" )+1 ;
    if ( mylev <= 0 )
        return notify_fail("�㲻����������֮�������ܲ���\n");
if(obj->query("age") <= 17 && userp(obj))	
return notify_fail("Ϊ����������ã��Ź�С���Ӱ�.\n");	
if(environment(me)->query("no_fight") || environment(me)->query("no_magic")) 		
return notify_fail("�����ֹս����\n");  		
    damage_jing = 30 * objexp / myexp ;
    if ( damage_jing < 30 ) damage_jing = 30 ;
    if ((int) me ->query("jing") < damage_jing )
        return notify_fail("��ľ��������ˣ�\n");
    this_object()->add("jian", -1);
    steps = ( mylev - objlev ) / 10  ;
    if ( steps < 2 ) steps = 2 ;
    if ( steps > 8 ) steps = 8 ;
    message_vision(HIY "\n$N�������䣬��$n��ΧѸ�ٰ���ʲô����......��\n" 
                   "��$n�ѹ�����ȴ�����Լ��������У��������ã�\n\n" NOR,
                   me, obj);
    me -> start_busy (3) ;
    if( playerp(obj) ) 
    {   
        me->fight_ob(obj);
		obj -> fight_ob(me) ;
    }       
    else 
    {   
        me->fight_ob(obj);
		obj->kill_ob(me);
    }   
    if (  (random(mylev)+1)*myexp  < objlev*objexp / 2 )
      message_vision("\n��$n�ܿ��ʶ����$N���󷨣��������������\n" , me, obj);
    else
      {
         tell_object (obj , HIR "\n���в��ϻó����ָ����Ĺ��ޣ�һ����������צ\n"
               "������������ֻ�ܼ�������������ಫ��\n" NOR  ) ;
     obj -> receive_damage ("jing", steps * 10,me ) ;   
         obj -> start_busy (steps) ;
     remove_call_out("out_zhen");
         call_out ("out_zhen" , steps + 2 , obj ) ;
         
      }
    me -> receive_damage ("jing" , damage_jing ) ;
    return 1;
}
void out_zhen ( object ob )
{
  if (!ob)  return;
  if (!living(ob))
  message_vision("$N������һ�����������ѳ�������\n"  , ob ); 
}

