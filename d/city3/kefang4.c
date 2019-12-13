inherit ROOM;

#define KEFANG  "/d/city3/kedian2"

int doing(object me);
int halt_do(object me);
void update_user(object user);
void do_touch(object me,object obj);
void do_make(object me,object obj);
void do_kiss(object me,object obj);
void do_hug(object me,object obj);
void do_tuo(object me,object obj);
void create()
{
        set("short", HIW "�ײ軨"NOR);
        set("long", @LONG
���Ӳ��õľ��¸���������һ�ź�ľ����������ֻ��ƿ��ƿ����ż�
֦�ײ軨����ƿ�����ż����ŷ�������Щ��ī��ʯ��δ��˴������µĻ�
�����������ԡ��ϱ����ȴ���(window)����ɫ���ˡ�һ����齷���ǽ�ǣ�
��ֻ�����ɴ�ʡ������䲻�󣬵��Ǹ����������ʵĸо���
LONG
        );
        set("exits", ([ 
  "out" : __DIR__"kedian2",
]));
    set("item_desc", ([
        "window" : 
"    �������Ǵ�����Ϣ����Ⱥ�������£���������Ⱥ��΢���еĲʴ�, ����
�ķ������಻�ϣ������С·��ϸС�����ߣ����������ڻ�ɫ�ķ���֮�䡣
�������·���һ�������деĴ�������\n", 
])); 

        set("sleep_room", "1");
                setup();
}
void init()
{
    add_action("do_sleep", "sleep");
    add_action("do_open","open");
    add_action("do_close","close");
}
int do_sleep(object arg){
    int doing_cost;
    object obj,me,where;

    me=this_player();
    where = environment(me);
    if(!arg || !objectp(obj = present(arg, environment(me)))){
         return 0;
    }

    if (me->query("gender")=="����"){
        tell_object(me,"��!���޸����ԣ�����������û��������ˣ�\n");
        return 1;
    }
    if( !obj->is_character() ){
        tell_object(me,"�����һ��ѽ����\n");
        return 1;
    }

    if((string)obj->query("gender") == (string)me->query("gender")){
        tell_object(me,"�㲻��" + RED"AIDS"NOR + "��\n");
        return 1;
    }
    if (obj->query("gender")=="����"){
        tell_object(me,"��!"+obj->name()+"�޸����ԣ�����������û��������ˣ�\n");
        return 1;
    }

    if (me->is_busy() || me->query_temp("pending/doing")){
        tell_object(me,"��������æ���ء�\n");
        return 1;
    }

    if( (int)me->query("qi") < 100 ){
        tell_object(me,"�����ڵ���̫���ˡ�\n");
        return 1;
    }
    if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 70 ){
        tell_object(me,"�����ھ�������\n");
        return 1;
    }
    if( userp(obj))
      if ((object)obj->query_temp("asking_who")!=me ) {
        message_vision("\n$N��$n���������Ŀ���,������$nʾ�� \n", me,obj);
        me->set_temp("asking_who", obj);
        obj->set_temp("asked_who",me);
        tell_object(obj, MAG "�����Ը��ͶԷ�....������Ҳ��" + me->name() + "("+(string)me->query("id")+")"+ "��һ�� sleep ָ�\n" NOR);
        write(HIY "���ڶԷ�������ҿ��Ƶ���������ȶԷ�ͬ����ܼ�����\n" NOR);
        return 1;
     }else{
      if (me->query("gender")=="����")
        message_vision("\n$N��$n���˵�ͷ��\n", me,obj);
      else
        message_vision("\n$N��ɬ�ؿ���$nһ�ۣ��Ǻ�������΢΢�ص��˵�ͷ��\n", me,obj);
     }
     me->delete_temp("asking_who");
     obj->delete_temp("asked_who");

    if (userp(obj)){
    if (me->query("gender")=="����"){
      message_vision("\n$N����ر���$n��$n��������$N�������������һ�¡�\n$N���ȴ�����ĸ���$nһ�ǡ�\n", me,obj);
    }else{
        message_vision("\n$N������§��$n��$nҲ�ſ�˫�ۣ���$N������§�ڻ��\n$N���ȴ�����ĸ���$nһ�ǡ�\n", me,obj);
    }
    }else{
        message_vision("\n$Nһ��$n��������ħ�Ƶģ�������˵�ͽ�$n��ס... ... ... ...  \n", me,obj);
    }
    me->set_temp("doing_with",obj);
    doing_cost=50;
    me->set_temp("make_cost",doing_cost);
    me->set_temp("doing_cost",doing_cost);
    me->start_busy((: doing :), (:halt_do:));

    obj->set_temp("doing_with",me);
    doing_cost=random(obj->query("jing"));
    obj->set_temp("make_cost",doing_cost);
    obj->set_temp("doing_cost",doing_cost);
    obj->start_busy((: doing :), (:halt_do:));

    return 1;
}
int doing(object me)
{
    object obj;
    int doing_cost;
    int exp_gain =random(30);
    int doing;
    if (!me) return 1;
    doing_cost = (int)me->query_temp("doing_cost");
    obj=(object)me->query_temp("doing_with");
    if (doing_cost < 1)
        return 0;
    me->add("combat_exp", exp_gain);
    doing_cost--;
    me->set_temp("doing_cost", doing_cost);

    me->add_temp("time_count",1);
    if (living(me))
        me->add("jing", -random(10));
    else{ me->add("jing", 1); me->set_temp("unconcious",1);}
    if (!obj || !present(obj, this_object())){
        me->start_busy(0);
        return 0;
    }
    doing=doing_cost*100/me->query_temp("make_cost");
    if (obj->query("gender")!="����")
        if (doing<95 && !me->query_temp("pending/tuo")){ do_tuo(me,obj); me->set_temp("pending/tuo",1);}
        else if (doing<80 && !me->query_temp("pending/hug")){ do_hug(me,obj); me->set_temp("pending/hug",1);}
        else if (doing<60 && !me->query_temp("pending/kiss")){ do_kiss(me,obj); me->set_temp("pending/kiss",1);}
        else if (doing<30 && !me->query_temp("pending/touch")){ do_touch(me,obj); me->set_temp("pending/touch",1);}
        else if (doing<15 && !me->query_temp("pending/make")){ do_make(me,obj); me->set_temp("pending/make",1);}
    if (doing_cost > 0)
        return 1;
    if (me->query_temp("unconcious"))
    {
        message_vision("���ھ������Ĺ��ȣ�$N��Ҳ֧�ֲ�ס���ε���$n��ǰ��\n", me,obj);
        me->unconcious();
    }   
    me->add("make_loves",1);
    obj->add("make_loves",1);
    obj->start_busy(0);
    me->delete_temp("doing_with");
    obj->delete_temp("doing_with");
    me->delete_temp("time_count");
    me->delete_temp("unconcious");
    me->delete_temp("make_cost");
    me->delete_temp("pending");
    update_user(me);
    update_user(obj);
    return 1;
}
int halt_do(object me)
{
    return 1;
}
void do_tuo(object me,object obj)
{
    object ob;
    message_vision(BOLD "$N�����Լ����´�����������������ѡ�\n" NOR, me);
     foreach (ob in all_inventory(me)){
        if (!ob->id("marry ring")){
        if ( ob->query("no_drop") || (!ob->vaule() && !ob->query("value")) )
            destruct(ob);
        else
            ob->move(this_object());
      }
      }
        message_vision(BOLD "$N����⿪$n���´���¶���˽�׵ļ�����\n" NOR, me,obj);
     foreach (ob in all_inventory(obj)){
        if (!ob->id("marry ring")){
        if ( ob->query("no_drop") || (!ob->vaule() && !ob->query("value")) )
            destruct(ob);
        else
            ob->move(this_object());
      }
      }
}
void do_hug(object me,object obj)
{
        message_vision("$N������ס��$n��$n����һƬ��ܰ��\n", me ,obj);
        
}
void do_kiss(object me,object obj)
{
    message_vision("$N�Ǳ���$n��ÿһ�缡��!\n", me,obj);
}
void do_touch(object me,object obj)
{
        message_vision("$N������$n���������!\n", me,obj);
}
void do_make(object me,object obj)
{
    message_vision( 
     HIM "  �¹⴩�������������ڴ�ǰ....... \n" NOR,me,obj);
}
void update_user(object user)
{
    object cloth,*ob;
    int i;

    if (!userp(user)){
      ob=all_inventory(this_object());
      for (i=0;i<sizeof(ob);i++){
          if (ob[i]->is_character() ) continue;
          if (ob[i]->move(user)){
              message_vision("$N����һ"+ob[i]->query("unit")+ob[i]->query("name")+"��\n" NOR, user);
              ob[i]->wear();
          }
      }
         return;
    }
    if (wizhood(user) == "(player)") 
	{
        if (user->query("shen")>10000)
            cloth = new("/clone/cloth/red_cloth");
        else if (user->query("shen")<-10000)
            cloth = new("/clone/cloth/black_cloth");
        else if (user->query("gender")!="Ů��")
            cloth = new("/clone/cloth/cloth");
        else    cloth = new("/clone/cloth/pink_cloth");
        cloth->move(user);
        cloth->wear();
    }
	   else{  
	    if (user->query("gender")!="Ů��")
            cloth = new("/clone/cloth/baipao");
        else cloth = new("/clone/cloth/color_cloth");
        cloth->move(user);
        cloth->wear();
    }
    UPDATE_D->check_user(user);
}

int do_open(string arg)
{
    object room;
    if (!arg || arg!="door")
        return notify_fail("��Ҫ��ʲô��\n");
    room=find_object(KEFANG);
    if (!room)
        room=load_object(KEFANG);
    set("exits", ([   "out" : __DIR__"kedian2",]));
    if (room->query("exits/4"))
        return notify_fail("���Ѿ����ˡ�\n");
    room->set("exits/4",base_name( this_object() ));
    message_vision("$N����ذѷ��Ŵ��ˡ�\n",this_player());
    message("vision","��Үһ�������˰�"+this_object()->name()+"�ķ��Ŵ��ˡ�\n",room);
    return 1;
}
int do_close(string arg)
{
    object room;
    mapping exits;
    if (!arg || arg!="door")
        return notify_fail("��Ҫ����ʲô��\n");
    room=find_object(KEFANG);
    if (!room)
        room=load_object(KEFANG);
    delete("exits");
    if (!room->query("exits/4"))
        return notify_fail("���Ѿ��ر��ˡ�\n");
    exits=room->query("exits");
    map_delete(exits,"4");
    message_vision("$N����ذѷ��Ź����ˡ�\n",this_player());
    message("vision","��Үһ�������˰�"+this_object()->name()+"�ķ��Ź����ˡ�\n",room);
    return 1;
}
void reset()
{
    object room;
    string arg;
    ::reset();
    if (NATURE_D->outdoor_room() )
        return;
    room=find_object(KEFANG);
    if (!room)
        room=load_object(KEFANG);
    set("exits", ([   "out" : __DIR__"kedian2",]));
    room->set("exits/4",base_name( this_object() ));

    room=find_object("/d/city3/kedian");
    if (!room)
        room=load_object("/d/city3/kedian");
    message_vision("С�����������˽����������ģ���˯ʲô����\n" ,room);
    arg="";
    foreach (object ob in all_inventory()){
    if( ob && ob->is_character() && !ob->is_corpse() )
         arg+=ob->name();
         ob->move(room);
     }
     if (arg!=""){
         message("vision","С��ק��"+arg+"�������⡣\n",this_object());
         message("vision","С��ק��"+arg+"���˳�����\n",room);
     }
}

