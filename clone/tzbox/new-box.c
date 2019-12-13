// 宝箱

#include <ansi.h>
inherit ITEM;
int do_open(string arg);
             
void create()
{
	set_name(HIG"新手套装宝箱"NOR, ({"xinshou baoxiang"}));        
	set_weight(100000);
	set_weight(10);
    set("icon","00012");
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个用红木制作而成的"+HIG"宝箱，"NOR+"似乎可以打开(openbox)获得新人装备。\n");
		set("unit", "个");
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
        if(me->query("gender")=="男性")
    tell_object(me,"你迫不及待地将"+HIG+"宝箱"NOR+"打开，\n");
        else
    tell_object(me,"你小心翼翼地将"+HIY+"宝箱"NOR+"打开，\n");

    if( me->over_encumbranced() )
    return notify_fail("身上带的东西太多了，拿不动了。\n");

     if(random(100)>0)
      {
        ob=new("clone/suit/new/new_pants");        
        ob->move(me);
        tell_object(me,"发现了一件"+HIG"新丁快靴"NOR+"。\n"NOR);
      }  
      if(random(100)>0)
      {
        ob=new("clone/suit/new/new_cloth");        
        ob->move(me);
        tell_object(me,"发现了一些"+HIG"新丁长衫"NOR+"。\n"NOR);
      }  
	  if(random(100)>0)
      {
        ob=new("clone/suit/new/new_boots");       
        ob->move(me);
        tell_object(me,"发现了一些"+HIG"新丁长裤"NOR+"。\n"NOR);
      }  
	 
	destruct(this_object());         
        return 1;
} 