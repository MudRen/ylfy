// Room: /d/emei/boat.c С��

inherit ROOM;
void create()
{
	set("short", "С��");
	set("long", @LONG
һҶС�ۣ����Ҳ�������������ˡ�һ�����������(bamboo)���ڴ�β��
���������������Ŵ�ǰ�С�
LONG
	); 
       set("item_desc", ([
           "bamboo" : "����һ����������(use)����͡�\n",
             ])) ;
	setup();
}
void init()
{
    add_action("do_use", "use");
    add_action("do_jump","jump");
}

int do_jump(string arg)
{
    object room;
    object me = this_player();
    if (arg != "out") return command("jump "+arg);
    if ( me->query_temp("used"))
      return notify_fail("���������𣿴�û�е����أ�\n");
    message_vision("$N��ಡ���һ����С������˳����������˺����ϣ�\n",me);
    if(!(room = find_object(__DIR__"boat")))
         room = load_object(__DIR__"boat");
    room->delete_temp("person_inside");     
    if ( me->query_temp("from_taoyuan") && me->query_temp("arrive_taoyuan"))
     {
         me->move(__DIR__"sroad1");
         me->delete_temp("arrive_yanbohu");
         return 1;
     }
    if ( me->query_temp("from_yanbohu") && me->query_temp("arrive_yanbohu"))
     {    
        me->move(__DIR__"yanbohu");
        me->delete_temp("arrive_taoyuan");
        return 1;
    }
   
    if ( me->query_temp("from_taoyuan") )
    {
        me->move(__DIR__"yanbohu");
        return 1;
    }
    if ( me->query_temp("from_yanbohu") )
    {
        me->move(__DIR__"sroad1");
        return 1;
    }
   
}

int do_use(string arg)
{
    object me = this_player();
    if ( me->query_temp("used"))
        return notify_fail("�����Ѿ��ڻ����ˡ�\n");
    if (!arg || arg != "bamboo") 
        return notify_fail("����ʹ��ʲô��\n");
        
    message_vision("$N������ͣ�����ˮ�棬�Ŵ�����л�ȥ��\n",me);
    me->set_temp("used",1);    
    message_vision("�����Ǳ̲�������ˮ�棬ˮ�������������ɻ������Ŵ��Ĳ���ǰ�У�ӭ����΢�紵����"
           "�綯��Ҷ��ɫ���ˣ�С�������Ƶ��ںɻ����д����š�\n",me);
    if ( me->query_temp("from_yanbohu")  )
   {
     if ( me->query_temp("arrive_yanbohu",1) )
     {
      me->start_call_out( (: call_other, __FILE__, "taoyuan", me :), 5);
      }
     else {
      me->start_call_out( (: call_other, __FILE__, "yanbohu", me :), 5);
   
     }
    return 1;
   }
   if ( me->query_temp("from_taoyuan"))
      {
       if ( me->query_temp("arrive_taoyuan",1) )
     {
      me->start_call_out( (: call_other, __FILE__, "yanbohu", me :), 5);
      }
     else {
      me->start_call_out( (: call_other, __FILE__, "taoyuan", me :), 5);
     }
    return 1;
   }
    return 1;  
}
void taoyuan(object me)
{
    object room;
    if( room = find_object(__DIR__"boat") )
    {
         message("vision","\n�ڻ�㱼䣬С���Ѿ����˰���ңң��ȥ��Զ����һ����ׯ��"
            "�������������Ĵ�����������\n",room);
     }
     me->set_temp("arrive_taoyuan",1);
     me->delete_temp("from_yanbohu");
     me->set_temp("from_taoyuan",1);
     me->delete_temp("used");
}
void yanbohu(object me)
{
    object room;
    if( room = find_object(__DIR__"boat") )
    {
       message("vision","\n�ڻ�㱼䣬С���Ѿ����˰���ңң��ȥ��Զ�����е�������������"
            "һ��С��ͨ���������\n",room);
     }
     me->set_temp("arrive_yanbohu",1);
     me->delete_temp("from_taoyuan");
     me->set_temp("from_yanbohu",1);
     me->delete_temp("used");
}
