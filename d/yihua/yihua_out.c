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
     "south" : __DIR__"damen",
     "north" : __DIR__"xiaojin",
]));
    
        set("outdoors","yihua");

        setup();
}
void init()
{       object ob;
        mapping myfam;
        if( interactive( ob = this_player()))
        if(query("exits/north")) 
        if ((int)ob->query_skill("qimen-wuxing",1) >= 100 )
        {
        delete("exits/north");
        set("exits/north", __DIR__"xiaojin");
	return ;
        }
        myfam = (mapping)ob->query("family");
        if(myfam && myfam["family_name"] == "�ƻ���")
        {
        delete("exits/north");
        set("exits/north", __DIR__"xiaojin");
	return ;
        }       
  	delete("exits/north");
        set("exits/north", __DIR__"yihua0");
}