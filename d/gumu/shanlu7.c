// shanlu7.c By csy 98/12

inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", YEL"ɽ·"NOR);
    set("long", @LONG
�˴���һ�����ɽ·����������������������Ω�������ȵף����Է��ۣ�
��ɽ�żţ�΢��������ãã����ֻ��һ�˶��ѡ����н��ͣ��߽���һ��ɽ
�ȣ���Χ�������ԡ���������ԶԶ�غ�����һ���߶����ͱڡ�
LONG
        );

    set("exits", ([ 
                "northwest"  : __DIR__"shanlu8",
                "southeast"  : __DIR__"shandong",       
    ]));

    set("outdoors", "��Ĺ");

    setup();
}

void init()
{
       object me, room;
       me = this_player(); 
       if (random((int)me->query("kar")) >= 15 ) {  
       if(!( room = find_object(__DIR__"shushang")))
       room = load_object(__DIR__"shushang");
       if(!(present("du mang", room))) 
       return;
       message_vision(HIR"ͻȻ�ŵ�һ���ȳ�֮���������ϵ�����һ����ڴ�ϸ������ͷ��������$N�����ˡ�\n\n"NOR, me);
       me->move(__DIR__"shushang");                                                            
       me->start_busy(3);       
    }      

}

