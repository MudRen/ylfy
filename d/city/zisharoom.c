inherit ROOM;
string look_out();
void create()
{
    set("short", "����֮��");
    set("long", @LONG
�����������֮�ۡ�����ɽ�紵���������������ƺ�������������������ƮƮ���ɵĸо���	
��֪����(out)����ͷ�ϣ����������ĸо���
LONG
    );
    set("exits", ([
        "east" : "/d/city/qq",	
    ]));
    set("objects", ([		
      __DIR__"npc/counter" : 1,			
    ]));		
    set("item_desc",([
        "out"       :   (: look_out :),
    ]));
    setup();
}
void init()
{
    add_action("do_out", "out");
}
int do_out(string arg)
{
    object me;
    me = this_player();
//       if (me->is_busy()) return 1;	
    message_vision("$N��һ����һ������������ȥ��\n", me);
//      if (wizardp(me)) {	
    me->command("chat ������Υ������" + me->query("name") + "Ըһ��л���£�");
//      me->delete("env");	
//     me->delete("skills");	
//       me->delete_temp("last_damage_from");	
    me->set_temp("die_for","������������ˤ");
//      } else {	
//       message_vision("ֻ��������¡��һ�����죬�����ŵ�����������\n", environment(me));	
     me->move(__DIR__"guangchang");
message_vision("ֻ��������¡��һ�����죬�����ŵ�����������\n", environment(me));       	
me->die();
//   }
    return 1;
}
string look_out()
{
    return  "�������������ߴ������������ң���������硣\n"
"�����̳��������۵ס���˵�˵���������ɱ�ĵط���\n";	
}


