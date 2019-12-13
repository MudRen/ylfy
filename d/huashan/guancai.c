// Room: /d/huashan/guancai.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
        set("short", "�ײ�");
        set("long", @LONG
�⸶�ײ��Ѿ���ʼù�ã��ײĵ��Ѿ����������������׶�������
��ֵ����������ŷ�ֽȴ������𣬺ڰ��з������ĵ���ɫ��â��
LONG
);
        set("exits",([
         "out":__DIR__"daoguan",
        ]));
        set("objects",([
        "/clone/misc/magic_seal":1,
        ]));
        setup();
}
void init()
{
      if (userp(this_player())){
         delete("exits");
         call_out("close",1);
         remove_call_out("drop");
         call_out("drop",5,this_player(),1);
      }
}
void close()
{
       message("vision","ͻȻ��֪��˭�ѹײĸǶ�����!\n",this_object());
}

void drop(object me,int i)
{
    object room;
    if (!me || environment(me)!=this_object())
           return;
    if (i<8){
       i++;
       message("vision","�ײĿ�֨��ֱ֨��......\n",this_object());
       remove_call_out("drop");
       call_out("drop",5,this_player(),i);
       return;
    }
    message_vision("ù�õĹײİ����ڲ���֧��$N�����أ�Ӧ�����ϣ�$N���ֹײĵ�ԭ���Ǹ��ں����Ĵ�.....\n",me);
    if (!room=find_object(__DIR__"heidong"))
       room=load_object(__DIR__"heidong");
    me->move(room);
}
