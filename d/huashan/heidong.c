// Room: /d/huashan/heidong.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
        set("short", "黑洞");
        set("long", @LONG
你的身子不住地往下坠，伸手不见五指......
LONG
);

        setup();
}
void init()
{
      if (userp(this_player())){
         remove_call_out("drop");
         call_out("drop",5,this_player(),1);
      }
}

void drop(object me,int i)
{
    object room;
    if (!me || environment(me)!=this_object())
           return;
    if (i<15){
       i++;
       message("vision","风声在你耳边呼呼直响......\n",this_object());
       remove_call_out("drop");
       call_out("drop",5,this_player(),i);
       return;
    }
    if (!room=find_object(__DIR__"pubu"))
       room=load_object(__DIR__"pubu");
    me->move(room);
    message_vision("扑通一声，$N掉进了瀑布里。\n",me);
    me->set_temp("die_for","掉进瀑布摔");
    me->receive_wound("qi",2000);
}
