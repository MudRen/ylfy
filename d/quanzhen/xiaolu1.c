//xiaolu1.c  

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "�ּ�С��");
        set("long", @LONG
������һ��С���ϣ��������������ӣ�����ɭɭ���������أ�������Ҷ
��������������������Ķ�����
LONG
        );

        set("exits", ([
                "north" : __DIR__"xiaolu2",
                "south" : __DIR__"houyuan",
                "west" : __DIR__"xiaolu3",
        ]));

	set("outdoors", "quanzhen");
	set("objects", ([
"/d/quanzhen/npc/liuchuxuan" : 1]));

        setup();
        
}
int valid_leave(object me, string dir)
{
	mapping fam;

	if (dir == "north")
	{
		if( mapp(fam = me->query("family")) 
			&&  fam["family_name"] == "ȫ���" 
			&&  fam["generation"] < 4  ) 	
			return ::valid_leave(me, dir);	
		
		if( me->query("guilty") == 0 
			&& !wizardp(me) )
		{
			return notify_fail("������˵��������ɽ���أ����������ϵ��Ӳ������ڣ�����������ȥ����\n");   	
		}
	}

	return ::valid_leave(me, dir);
}


