// Room: /d/quanzhou/haigang.c
// Date: May 7, 96   Jay
inherit ROOM;
void create()
{
    set("short", "����");
    set("long", @LONG
�����ǳ����ıؾ�֮�أ����߲���һ�Ҵ�(chuan)��
LONG
    );
    set("exits", ([
                "west" : __DIR__"zhongxin",
                "east" : "/d/quanzhou/haigang3",	
                 "north" : "/d/quanzhou/haigang2",
    ]));
    set("objects", ([
                __DIR__"npc/boy":2,
                __DIR__"npc/girl":1,
                "/d/shenlong/npc/chuanfu" :1,
    ]));
    set("item_desc", ([
        "chuan" : "����ȥ�һ����Ĵ󴬡�ֻҪ�ϴ�(enter)�Ϳ��Ե��һ�����\n",
    ]));
    set("outdoors", "quanzhou");
    setup();
}
void init()
{
    add_action("do_enter", "enter");
}
int do_enter ( string arg )
{
    object ob ,room;
    if( !arg || arg !="chuan" ) 
       {
         tell_object(this_player() , "��Ҫ enter �Ķ���\n" ) ;
         return 1 ;
       }
    if (!room=find_object("/d/taohua/dahai"))
    room=load_object("/d/taohua/dahai");
    if (!room->do_check())
        return notify_fail("���ոճ����ˣ�\n");
    ob = this_player () ;
    message_vision("����һ�������ϴ���æ����һ��������ඣ�\n", ob);
    message_vision("�������𷫣������򶫷����С�\n", ob);
    ob ->move(room) ;
    tell_object(ob, BLU "���ں��Ϻ����˺ܾúܾ�.......\n" NOR ) ;
    call_out("rtaohua", 10 , ob );
    return 1 ;
}
void rtaohua( object ob )
{
    if (!ob || ob->is_ghost()) return;
  tell_object(ob , "�����ڵִ���һ����ɫ�ĺ�̲�������´�����\n" ) ;
  ob->move ("/d/taohua/haitan.c") ;
}
