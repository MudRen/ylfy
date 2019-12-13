// wumu-yishu.c
#include <ansi.h>

inherit ITEM;
void setup()	
{}
void init()
{
if (this_player()==environment()){	
add_action("do_du", "du");	
add_action("do_du", "study");	
}
}

void create()
{
	set_name( "「武穆遗书」", ({ "wumu yishu", "yishu" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long",
			GRN
			"\n这就是岳武穆临死前留下的“破金要诀”。\n"
			"只见第一页上写了十八个大字：\n"
                        "“重搜选，谨训习”\n"
                        "“公赏罚，明号令”\n"
                        "“严纪  ，同甘苦”\n"
               NOR
		);
		set("value", 10000000);
		set("material", "paper");
		set("no_get", 1);
		set("no_drop", 1);
		set("treasure", 1);
	}
}

int do_du(string arg)	
{
object me = this_player();	
object where = environment(me);		
        
if (!(arg=="wumu yishu" || arg == "yishu"))	
return 0;	
if (where->query("pigging")){	
write("你还是专心拱猪吧！\n");	
return 1;	
}
if (me->is_busy()) {	
write("你现在正忙着呢。\n");	
return 1;	
}
if( me->is_fighting() ) {	
write("你无法在战斗中专心下来研读新知！\n");	
return 1;	
}
if (!id(arg)) {		
write("你要读什么？\n");	
return 1;	
}
if( !me->query_skill("literate", 1) ){	
write("你是个文盲，先学点文化(literate)吧。\n");	
return 1;	
}

if (me->query("mark/+int")) 	
        {
        write("这可真是一部兵法奇书呀！！！\n");
return 1;	
        }
message("vision", me->name() + HIY"随手翻阅武穆遗书，但见一字一句之间，无不阐明临阵对敌的妙法，不禁大声赞叹！\n"NOR,environment(me), me);
me->add("int", 1);	
        write(HIR"你的悟性提高了！\n"NOR);
me->set("mark/+int", 1); 	
destruct(this_object());	
        return 1;
}
