//bye mei
#include <ansi.h>
inherit ROOM;
void create()
{
     set ("short", "������");
     set ("long", @LONG
���������������ڣ�������ĳ��輫Ϊ��������˹��̺��
�Ϻõ����Σ����������ƿ����Һ��������ţ����̲�ס���
�����ڡ�
LONG
    );
    set("exits",([
          "out": __DIR__"houyuan",
      ]));
    set("objects",([
          __DIR__"obj/wuliangye" : 1,
     ]));

    setup();
}
void init()
{
      if (userp(this_player())){
         delete("exits");
         remove_call_out("yangzhou");
         call_out("yangzhou",5,this_player(),1);
      }
}
void close()
{
       message("vision","����ѳ��Ź����ˣ�\n",this_object());
}
void yangzhou(object me,int i)
{
    object room;
    if (!me || environment(me)!=this_object())
    {
        if (room=find_object(__DIR__"houyuan"))
            room=load_object(__DIR__"houyuan");
        room->set("exits/enter",base_name(this_object()));
           return;
    }
    if (i<15){
       i++;
      switch(i){
        case 5:
       message("vision","����ɽ·���ϵ���......\n",this_object());
        break;
      default:
       message("vision","���������������ϵشӳ��⴫��......\n",this_object());
     }
       remove_call_out("yangzhou");
       call_out("yangzhou",5,this_player(),i);
       return;
    }
    if (!room=find_object("/d/city/postoffice"))
       room=load_object("/d/city/postoffice");
    me->move(room);
    tell_object(this_player(),HIR "����˵������ɶ�Ӻȣ����ˡ�\n" NOR,me);
    message_vision("$N�ӳ��������˳�ȥ���ص������ݡ�\n",me);
        if (room=find_object(__DIR__"houyuan"))
            room=load_object(__DIR__"houyuan");
        room->set("exits/enter",base_name(this_object()));

}

