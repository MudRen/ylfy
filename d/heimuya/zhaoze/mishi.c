// Room: /d/heimuya/zhaoze/mishi.c
inherit ROOM;
int do_get(string arg);
void relay_circs(object me);
void create()
{
        set("short", "����");
        set("long", @LONG
����ں����ģ���ʲô����������
LONG
);
        set("exits", ([ 
        "out" : __DIR__"shx",
]));
        setup();
}
void init()
{
    object me;
    me = this_player();
        set("long", @LONG
����ں����ģ���ʲô����������
LONG
);
     delete("item_desc"); 

    if (time()-query("time")>3600)
        set("yangpi",1);
    if (userp(me)){
        call_out("relay_circs",5,me);
        }
}
void relay_circs(object me)
{
//    if (environment(me)!=this_object()) return;             	

//     if ( !present("ming zhu",me) ) return;  	
     write("  �㻳���ҹ�����Ȼ����һ����⣬�㷢�����������ܿյ�����,
����ȴʮ�ָ����֪Ϊ��ˮ�������������ҵ�������һʯ��(box)��\n");
        set("long", @LONG
ƾ��ҹ����ĺ��⣬�㷢�����������ܿյ�����,����ȴʮ�ָ����
֪Ϊ��ˮ�������������ҵ�������һʯ��(box)��
LONG
);
    if ((int)query("yangpi")){
        set("item_desc", ([ "box" : "    ʯ���������һ����Ƥ��\n",  ])); 
        add_action("do_get", "get");
    }else
        set("item_desc", ([ "box" : "    һ���յ�ʯ�С�\n",  ])); 
}
int do_get(string arg)
{
        object me,ob;
        me = this_player();
        if( !arg || arg=="" ) return 0;
        if (!(int)query("yangpi")) return 0;
        if( arg=="��Ƥ from box" || arg=="��Ƥ from ʯ��") {
             ob=new(__DIR__"obj/yangpi");
            if (ob->move(me)){
             message_vision("$N��ʯ����ȡ��һ����Ƥ��\n",me);
             set("item_desc", ([ "box" : "    һ���յ�ʯ�С�\n",  ])); 
             return 1;    
           }   
      }
      return 0;              
}
void reset()
{
     object ob;
     ::reset();
     if (present("ling pai",this_object())) return;
     if (random(10)<4 ){
        ob=new(__DIR__"obj/lingpai");
        ob->move(this_object());
     }
}

