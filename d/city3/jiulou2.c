//bye mei 
inherit ROOM;
int do_yell(string arg);
int do_diancai(object me);
int do_sit(object me);
void create()
{
        set("name", "���Ӿ�¥");
        set("short", "���Ӿ�¥��¥");
        set("long", @LONG
�����ڳɶ�������ľ�¥�ϣ�����¥�µķ���ææµµ��
���������죬��ν���ԾƵ��裬�������Ρ�������ԥʲô��
�������ϺõĻ���ưɣ�ǽ�Ϲ��ż۸�����(paizi)��
LONG
        );

        set("item_desc", ([
                "paizi" : "���껶ӭ���˵�ˡ���Ҫ��ˣ����(yell)С����\n",
        ]));

        set("exits", ([
                "down" : __DIR__"jiulou1",
        ]));
        set("objects", ([
                  __DIR__"obj/chair" : 4,
                  __DIR__"obj/table" : 1,
        ]));

        setup();
}
void init()
{
    this_player()->delete_temp("dian");
    add_action("do_yell", "yell");
}
int do_yell(string arg)
{
    if( !arg || arg=="" ) return notify_fail("�����С����");
    if ( this_player()->query_temp("rode/type")!="sit" )
        return notify_fail("�㻹����������˵��\n");
    if( arg=="xiao er" ) arg = "С��";
    if( (int)this_player()->query("neili") < 300 )
        message_vision("$Nʹ�����̵���������һ������" + arg + "��\n",
            this_player());
    else if( (int)this_player()->query("neili") > 600 )
        message_vision("$N���˿�����һ����" + arg + "������������ƽ�͵�ԶԶ��"
            "�˳�ȥ��\n", this_player());
    else
        message_vision("$N������������Хһ������" + arg + "����\n",
            this_player());
    if( arg=="С��"){
        call_out("do_diancai", 3,this_player());
        return 1;
        } else
        message_vision("¥�����ܴ���һ���������" + arg +
            "��������\n", this_player());
    return 1;
}
int do_diancai(object me)
{
    object xiaoer;
   if (!me || environment(me)!=this_object() ) return 1;
 
    xiaoer=find_living("xiao gouzi");
    if ( !xiaoer || !environment(xiaoer)){
          tell_object(me,"С�������ˣ�����ʲô�ˣ�\n");
          return 0;
    } else {
        if (!present("xiao gouzi", this_object() )){
                message("vision",xiaoer->name()+"ߺ��һ���������ˣ���\n������ææ���ܿ��ˡ�\n",environment(xiaoer));
                xiaoer->move(this_object());
                message("vision",xiaoer->name()+"����ææ�����˹�����\n",this_object());
         }else
        tell_object(me,xiaoer->name()+"���������Ա���\n");
    }
    call_out("do_zuo", 5,me,xiaoer);
    return 1;
}
int do_zuo(object me,object xiaoer,object ob)
{
   if (!me || environment(me)!=this_object()|| !xiaoer || environment(xiaoer)!=this_object() ) return 1;
    if( me->query_temp("rode/type") != "sit" ) { 
         message_vision("$N�����Ӱѵ���ʹ�����˲룬�����͹�����������˰ɣ�\n", xiaoer); 
         } else {
         if(!present("cai dan", me)){
            message_vision("$N˵������λ�͹���Ե�ʲô�������Ų˵����������Ը�С�ġ�\n",xiaoer); 
            ob = new(__DIR__"obj/caidan");
            ob->move(me);    
            message_vision("$N�ӻ����ó�һ�����ף�������$n��\n",xiaoer,me);
              } else 
            message_vision("$NЦ���еض�$n˵������λ�͹���Ե�ʲô��\n",xiaoer,me);
            return 1;              
            }
         return 1;                
}
int valid_leave(object me,string dir)
{
    if ( dir=="down" && me->query_temp("rode/type")=="sit" && !wizardp(me)){
       return notify_fail("�������վ(stand)����������·��\n");
    }
    return 1;
}

