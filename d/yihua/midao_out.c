#include <ansi.h>
inherit ROOM;
 
int do_pick(string arg) ;

void create()
{
        set("short", "�ܶ�");
        set("long",@LONG
��������һ���ܶ��С�������ߺܰ���ֻ������ԼԼ����������Щ�仨��ݡ�
����֮�е�һ��ʯͷ�Ϻ������һ����ϻ(xia)�� ��ͻȻ�ŵ�һ���������ζ����
�治֪������ʲô�ط��ˡ�
LONG);   
        set("item_desc", ([
        "xia" : @TEXT
����ϸ����һ��ʯϻ�����������ƺ����������飬�ƺ����������ó���
(pick book)��
TEXT
    ]) );
        set("exits", ([
  "out"  : __DIR__"midao",
  "west"   : __DIR__"xiaojing2",
]));
        set("objects", ([
        __DIR__"npc/huawuque" : 1,
    ]) );    

        setup();
}
void init()
{
            add_action("do_pick","pick");
}
void reset()
{
        ::reset();
        set("get_available" , 2);
}

int do_pick(string arg)
{
       object me,obj;

       me = this_player();
       if( !arg || arg!="book" )
              return notify_fail("��Ҫȡʲô?\n");
obj=present("hua wuque",environment(me));
if(obj && living(obj))
        
       {
        message_vision(YEL"����ȱ˵����û�й�����ͬ����ô�����أ�"
                       "���������ˣ�\n" NOR,me);
        return 1 ;
       }
       if ( query("get_available") )  {
       obj = new (__DIR__"obj/yihuapu");
       obj->move(me);
       obj = new (__DIR__"obj/yifengjianpu");
       obj->move(me);
       add("get_available", -2);
       message_vision("$N�ӱ�ϻ��ȡ�������顣\n",me );
       }
       else
       return notify_fail("�ؼ��Ѿ������˽����ȵ��ˡ�\n");
       return 1;
}

