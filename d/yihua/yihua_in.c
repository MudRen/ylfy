#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "����");
        set("long",@LONG
����һƬ�ȵ׵�С·������һ���޼ʣ�ȫ��ʢ�����ʻ���΢�������
�۷䵽���衣�������ˡ�������һƬõ�廨����������һƬ��������
LONG
        );
       set("exits", ([
     "south" : __DIR__"xiaojin",
     "north" : __DIR__"yihua0",
]));
//	set("objects", ([
//        "" : 1,
//	__DIR__"npc/" : 1,
//   ]) );
    
        set("outdoors","yihua");

        setup();
}
void init()
{       object ob;
        mapping myfam;
	ob = this_player() ;
        if(query("exits/south")) 
        if ((int)ob->query_skill("qimen-wuxing",1) >= 100 )
        {
        delete("exits/south");
        set("exits/south", __DIR__"yihua_out");
	return ;
        }
        myfam = (mapping)ob->query("family");
        if(myfam && myfam["family_name"] == "�ƻ���")
        {
        delete("exits/south");
        set("exits/south", __DIR__"yihua_out");
	return ;
        }         
	delete("exits/south");
        set("exits/south", __DIR__"yihua0");
}