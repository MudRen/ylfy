// ����

#include <ansi.h>
inherit ITEM;
int do_open(string arg);
             
void create()
{
	set_name(HIG"����"NOR, ({"bao xiang", "bao", "xiang"}));        
	set_weight(100);
	set_weight(10);
    set("icon","00012");
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ���ú�ľ�������ɵ�"+HIG"���䣬"NOR+"�ƺ����Դ�(openbox)������벻������Ʒ��\n");
		set("unit", "��");
		set("value", 100000000);
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

    /*if(random(300) < 3)
      {
        ob=new("clone/tzbox/qf-box");        
        ob->move(me);
        tell_object(me,"������һ��"+HIY"�ط籦��"NOR+"��\n"NOR);
      } */ 
    else if(random(300) < 299)
      {
        ob=new("clone/money/thousand-gold.c");        
        ob->move(me);
        tell_object(me,"������һ��"+YEL"һǧ����Ʊ"NOR+"��\n"NOR);
      }  
	else if(random(300) < 10)
      {
        ob=new("clone/map/obj/fangbao-fu.c");       
        ob->move(me);
        tell_object(me,"������һ��"+HIM"������"NOR+"��\n"NOR);
      }  
	else if(random(300) < 20)
      {
        ob=new("clone/map/obj/longwen-chijin.c");       
        ob->move(me);
        tell_object(me,"������һ��"+CYN"���Ƴ��"NOR+"��\n"NOR);
      }   	
    else if(random(300) < 4)
      {
        ob=new("clone/map/obj/bangding-stone.c");       
        ob->move(me);
        tell_object(me,"������һ��"+MAG"��ʯ"NOR+"��\n"NOR);
      }  
    else if(random(300) < 150)
      {
        ob=new("clone/winbox/box.c");       
        ob->move(me);
        tell_object(me,"������һ��"+HIG"����"NOR+"��\n"NOR);
      }  	  
	destruct(this_object());         
        return 1;
} 