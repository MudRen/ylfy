// ����

#include <ansi.h>
inherit ITEM;
int do_open(string arg);
             
void create()
{
	set_name(HIG"������װ����"NOR, ({"xinshou baoxiang"}));        
	set_weight(100000);
	set_weight(10);
    set("icon","00012");
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ���ú�ľ�������ɵ�"+HIG"���䣬"NOR+"�ƺ����Դ�(openbox)�������װ����\n");
		set("unit", "��");
		set("value", 1000000);
	}
}


void init()
{
   add_action("do_open","openbox");
}

int do_open(string arg)
{ 
    object me=this_player(),ob;
        if(me->query("gender")=="����")
    tell_object(me,"���Ȳ������ؽ�"+HIG+"����"NOR+"�򿪣�\n");
        else
    tell_object(me,"��С������ؽ�"+HIY+"����"NOR+"�򿪣�\n");

    if( me->over_encumbranced() )
    return notify_fail("���ϴ��Ķ���̫���ˣ��ò����ˡ�\n");

     if(random(100)>0)
      {
        ob=new("clone/suit/new/new_pants");        
        ob->move(me);
        tell_object(me,"������һ��"+HIG"�¶���ѥ"NOR+"��\n"NOR);
      }  
      if(random(100)>0)
      {
        ob=new("clone/suit/new/new_cloth");        
        ob->move(me);
        tell_object(me,"������һЩ"+HIG"�¶�����"NOR+"��\n"NOR);
      }  
	  if(random(100)>0)
      {
        ob=new("clone/suit/new/new_boots");       
        ob->move(me);
        tell_object(me,"������һЩ"+HIG"�¶�����"NOR+"��\n"NOR);
      }  
	 
	destruct(this_object());         
        return 1;
} 