
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIW"������"NOR,({ "hanbing jia", "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("icon","10001");
                set("unit", "��");
                set("material", "cloth");
				set("armor_prop/dexerity", 50);
                set("armor_prop/strength", 50);
                set("armor_prop/dodge", 50);
                set("armor_prop/parry", 50);				
                set("armor_prop/armor", 1000);
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
          message_vision("$N�������������ģ�ʪʪ�ģ�ԭ���Ǻ����׻��ˡ�\n", env);
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