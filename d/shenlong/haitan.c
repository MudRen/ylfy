#include <ansi.h>
inherit ROOM;
void home( object ob ) ;
void create()
{
    set("short", "��̲");
    set("long", @LONG
����������ߵ��ˡ��ϱ���һ���޼ʵĴ󺣣���������һƬ��ľ�֡�
���ϵĿ����ƺ���������,��ʪ�ĺ����д���һ���ȳ�,�ּ�����һ����
�صĻ���,������ʮ�ֹ���.���߲���һ�Ҵ�(chuan)��
LONG
    );
    set("item_desc", ([
        "chuan" : "�������ߵ�������ϵ�Ĵ󴬡����ϵĿ��˻����ֻҪ\n"
                  "�ϴ�(enter)�Ϳ��Ի���ԭ��\n",
    ]));
    set("exits",([
     "north" :__DIR__"lin1",
]));
    set("outdoors", "shenlong");
    setup();
}
void init()
{
    add_action("do_enter", "enter");
}
int do_enter ( string arg )
{
    object ob ;
    if( !arg || arg !="chuan" ) 
       {
         tell_object(this_player() , "��Ҫ enter �Ķ���\n" ) ;
         return 1 ;
       }
    ob = this_player () ;
    message_vision("����һ�������ϴ���æ����һ��������ඣ�\n", ob);
    message_vision("�������𷫣��������������С�\n", ob);
    ob ->move("/d/shenlong/dahai") ;
    tell_object(ob, BLU "���ں��Ϻ����˺ܾúܾ�.......\n" NOR ) ;
    call_out("home", 10 , ob );
    return 1 ;
}
void home( object ob )
{
     if (!ob) return;
  tell_object(ob , "�����ڵִ�����ԭ��һ���������С������´�����\n" ) ;
  ob->move ("/d/city2/haigang") ;
}
