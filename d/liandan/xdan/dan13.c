//by : pipip
inherit ITEM;
#include <ansi.h>
void init()
{
        add_action("do_eat", "eat");
}
void create()
{
    set_name(HIR "解毒丸" NOR, ({"jiedu wan", "wan"}));
        set("unit", "朵");
    set("long", "西门家传秘药，专解世间百毒。\n");
        setup();
}
int do_eat(string arg)
{
    if (!id(arg))  return notify_fail("你要吃什么？\n");
  if(this_player()->query("id")==query("value"))
 return notify_fail("这棵丹不是你练的,你吃个什么劲。\n");
    this_player()->set_temp("nopoison", 1); 
	this_player()->clear_condition();
    this_player()->set("eff_jing",this_player()->query("max_jing"));
    this_player()->set("jing",this_player()->query("max_jing"));
    this_player()->set("eff_qi",this_player()->query("max_qi"));
    this_player()->set("qi",this_player()->query("max_qi"));
   message_vision(HIC "$N吞下解毒丸，一股热力从单田升起，渐渐的渗入全身血脉。\n" NOR,this_player() );
    destruct(this_object());
    return 1;
}

