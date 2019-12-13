//LUCAS 2000-6-18
#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
   set_name(HIW "������" NOR, ({"hanbing dao", "balde", "dao"}));
   set_weight(5000);
   set("unit", "��");
   set("icon", "10015");
   set("long", "һ��ɢ����ɭɭ�����ĺ�����,������֮������\n");
   set("material", "ice");
   set("wield_msg","$N��ৡ���һ�����һ��$n�������У�ֻ��һ�ɺ������������\n");
   set("unwield_msg","$N�����е�$n�������䣬����ů�Ͷ��ˡ�\n");

   init_blade(500);

   if( clonep(this_object()) ) {
     set_default_object(__FILE__);
   }
   setup();
}  
void init()
{

   remove_call_out("do_melt");
   call_out("do_melt", 1);
}

void do_melt()
{
   if(this_object()) call_out("melt", 1);
}

void melt()
{
   object env;

   if(!this_object()) return;

   env=environment(this_object());

   if( env->is_character() && playerp(env) )
   {//a player or a NPC.
     
        if(environment(env))
          message_vision("$N�������������ģ�ʪʪ�ģ�ԭ���Ǻ��������ˡ�\n", env);
        destruct(this_object());
        return;
   }

   else if( (int)env->query_max_encumbrance() > 0 && !environment(env) )
   {//a room.  
   
        tell_object(env,"���������ڻ�����һ̲ˮ�����õ������ǡ�\n");
        destruct(this_object());
        return;  
   } 
}


