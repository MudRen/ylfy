// Room: /d/emei/liangfengqiao.c ������
// create by host dec,20 1997

inherit ROOM;
string* npcs = ({
        "fish",
        "fish1",
});

string* npcs1 = ({
        "fish2",
        "fish3",
});

void create()
{
        set("short", "������");
	set("long", @LONG
�����Ѿ��Ƕ���ɽ���£�������ǰ��һ��СϪ��ᶫ������Ϫˮ�Ϸ���
��һ��ľ�ţ�����ľ���ϸ���ȥ��ֻ��С��ˮ���峺���ף�ż���ɼ����
��ˮ��������ȥ��Զ����������΢�磬��ʹ����ľ�����ˬ��
LONG
	);
       set("outdoors", "emei");
	set("exits", ([
                "southup" :  __DIR__"jietuopo",
                "north" : __DIR__"milin2",
	]));

	set("objects",([
	]));

	setup();
}
void init()
{
   add_action("do_catch","catch");
}

void wait_catch()
{
   
    object me;
    me=this_player();
    message_vision("$N�����˸ֲ棬�����Ŀ���ˮ�档\n",me);
    
    me->set_temp("busy",1);
    me->start_call_out( (: call_other, __FILE__, "delay_message", me :), 5);
}

void delay_message(object me,object obn)
{

  int i = random(sizeof(npcs));
  int j = random(sizeof(npcs1));
  me->delete_temp("busy");

  if ( random(me->query_str()) > (me->query_str())/2)
   { 
     if ( random(me->query_str()) < 18)
    {
       message_vision("һ��������˹�����$N�������˹�ȥ��������ܶ�����\n",me);
          return 0;
        } 
    else if ( random(me->query_str()) <  25)
       {
      obn= new("/d/emei/obj/"+npcs[i]);
      obn->move(me); 
      message_vision("ͻȻһ��������˹�����$N�͵����˹�ȥ����������\n",me);
         return 0;
      }
    else {
      obn= new("/d/emei/obj/"+npcs1[j]);
      obn->move(me); 
      message_vision("ͻȻһ��������˹�����$N�ɿ�����˹�ȥ����������\n",me); 
      return 0;
      }
   }
  message_vision("һ��������˹�����$N�������˹�ȥ��������ܶ���.\n",me);
    return 0;  
}


int do_catch(string arg)
{

    object me,obj; 
    me=this_player();

    if (me->query_temp("busy"))
       return notify_fail("��������æ��׽�㣡\n");

    if ( !arg || (arg != "fish"))
       return notify_fail("��Ҫ׽ʲô��\n");
    
   if (!(obj = present("gangcha", this_player())))
       return notify_fail("������ʲô׽�㣿\n");

   if( me->query("jing") < 15)
       return notify_fail("���Ѿ��޷����о���ȥ׽���ˡ�\n");

   this_player()->receive_damage("jing", 10);

   wait_catch();
   return 1;
}

