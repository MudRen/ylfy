// storeroom.c

inherit ROOM;

void init();
int do_open(string);

void create()
{
        set("short", "储藏室");
        set("long", "这是一个储藏室，四周密不透风。只有关闭着的大门(door)。\n");
        set("item_desc" , ([
         "door" : "一扇木门，也许能打开。\n",
         ]) );
         setup();
       call_out("do_out",300);
}
void init()
{
 add_action("do_open","open");
}
int do_open(string arg)
{
  object me=this_player();
  object room;
 if( !arg|| arg!="door")
  return notify_fail("你要开什么？\n");
 if(!( room = find_object(__DIR__"yuanzi")) )
    room = load_object(__DIR__"yuanzi");
 if(!objectp(room))  return notify_fail("ERROR:not found 'yuanzi.c' \n");
 if(room->query_temp("lock")==1)
   return notify_fail("门已经从外面锁住了。\n");
if( me->is_busy() )	
return notify_fail("你上一个动作还没有完成！\n");	
 message_vision("$N轻轻推开门，走了出去，随手把门掩了起来。\n",me);
 message("vision", "有人走了出来，随手把门掩上了。\n",room);
 me->move(room);
me->start_busy(1);              	
 return 1;
}

void do_out()
{
    object *env=all_inventory(this_object());
    if (sizeof(env)>0){
       foreach (object npc in env){
          if (living(npc) && !userp(npc)) {
             npc->force_me("open door");
             break;
          }
       }
    }
    remove_call_out("do_out");
    call_out("do_out",300);
}

