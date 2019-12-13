// Room: /d/quanzhou/haigang.c
// Date: May 7, 96   Jay
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ǳ����ıؾ�֮�أ�Ȫ�ݺųƶ�����һ��ۣ���
����˿��֮·����㣬�۴�(chuan) ʮ�ַ��㡣
LONG );
	set("exits", ([
            "west" : "/d/quanzhou/haigang",	
	]));
	set("item_desc", ([
                "chuan" : "һ���󺣴�����Զ��û�����Ĵ��ɲ��С�\n",
	]));
	set("objects", ([
        "/d/village/npc/boy": 2,   	
        "/d/village/npc/girl": 1,  	
		"/d/mingjiao/npc/changjinpeng": 1,
		"/d/lingshedao/npc/yinli": 1,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "quanzhou");
	setup();
//	replace_program(ROOM);
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
    message_vision("�������𷫣������򶫷����С�\n", ob);
    ob ->move("/d/taohua/dahai") ;	
    tell_object(ob, BLU "���ں��Ϻ����˺ܾúܾ�.......\n" NOR ) ;
    call_out("tpenghu", 10 , ob );
    return 1 ;
}
void tpenghu(object ob )
{
    tell_object(ob , "�����ڵִ��˴���һ�����졣�����´�����\n" ) ;
ob->move ("/d/lingshedao/haitan1") ;	
}
