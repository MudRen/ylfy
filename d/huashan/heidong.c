// Room: /d/huashan/heidong.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
        set("short", "�ڶ�");
        set("long", @LONG
������Ӳ�ס������׹�����ֲ�����ָ......
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
       message("vision","����������ߺ���ֱ��......\n",this_object());
       remove_call_out("drop");
       call_out("drop",5,this_player(),i);
       return;
    }
    if (!room=find_object(__DIR__"pubu"))
       room=load_object(__DIR__"pubu");
    me->move(room);
    message_vision("��ͨһ����$N�������ٲ��\n",me);
    me->set_temp("die_for","�����ٲ�ˤ");
    me->receive_wound("qi",2000);
}
