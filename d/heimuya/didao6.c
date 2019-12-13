//ROOM didao6
inherit ROOM;
void init();
int do_move(string);
string look_wan();
void create()
{
  set("short","�ص���ͷ");
  set("long",
        "�����ǰ��һ������ǰ���Ǳ��ж��죬������·������ȫ��\n"
        "ʯ�ڡ��������ʮ���ɣ�����������һʯ��(wan)��\n"
     );
  set("exits",([      
      "northdown" : __DIR__"didao4",

     ]));
   
       set("item_desc", ([
            "wan" : (: look_wan :),
        ]));

 setup();
}
void init()
{
        add_action("do_circle", "circle");
}
string look_wan()
{
    this_player()->add_temp("look_wan",1);
        if (this_player()->query_temp("look_wan")>3){
                this_player()->delete_temp("look_wan");
                return "����ϸ���˿��������������Ƕ��һ��ʯͷ�ϵģ��ƺ�����ת��(circle)����\n";
        }else
        return "����һ���Ժ��������µĹŶ�,�ܱ��¡�\n";
}

int do_circle(string arg)
{
        object me = this_player();
        object room;
        if ((arg != "wan") || !arg)
                return notify_fail("��Ҫ��ʲô��\n");
        if((int)me->query("str") < 20)
                return notify_fail("������������\n");
        if(!( room = find_object(__DIR__"neishi")) )
                room = load_object(__DIR__"neishi");
        if (!query("exits/up")){
          set("exits/up", __DIR__"neishi");
          message_vision("$N�������룬ֻ��ӭ���ʯǽ�ƿ�,¶��һ�������ĵĶ��ڡ�\n",me);
          room->set("exits/down", __FILE__);
          message("vision", "���洫��һ��ᶯ���������һ���������˽�����\n", room);
        }else{
          delete("exits/up");
          message_vision("�ܿ����ְ����ԭλ��ӭ���ʯǽ���ϣ������ֱ���ס�ˡ�\n",me);
          room->delete("exits/down");
          message("vision", "���洫��һ��ᶯ������������ڱ���ס�ˡ�\n", room);
        }
        return 1;
}


