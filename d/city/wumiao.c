// Room: /city/wumiao.c
#include <room.h>
inherit ROOM;
void create()
{
    set("short", "����");
    set("long", @LONG
�����������������������������Ϸ������������顰���Һ�ɽ����
���ҡ����������Ƕ�š����ұ������ĸ����֡����˵��ˣ��������������Ϲ�
�Ͼ���������ݡ��Ա��ƺ���һ�����š�
LONG
    );
    set("no_fight", "1");
    set("no_steal", "1");
	set("no_all_cmd",1);
    set("no_sleep_room", "1");
    set("valid_startroom","1");
    set("no_msg_vision",1);
    set("objects", ([
        __DIR__"obj/box" : 1,
        __DIR__"npc/bigeye" : 1,
		__DIR__"npc/give_cloth" : 1,
        __DIR__"obj/table" : 1,//����2003-7-13�޸ģ��ɹ㳡����������	
    ]));
    set("exits", ([
        "east" : __DIR__"beidajie2",
        "northwest": "/d/wizard/guest_room",
       "north":"/d/city/shijian",
    ]));
        create_door("northwest", "����", "southeast", DOOR_CLOSED);
         setup();
      "/clone/board/bugs_b"->foo();	
	 
}
void init()
{
	if ( !wizardp(this_user()) )
		add_action("discmds",({"sha","drop","attack","duanlian","ansuan","touxi","persuade","teach","exert",
			"exercise","study","learn","sleep","kill","steal","cast","conjure","expell","fight","hit","perform",
			"prcatice","scribe","surrender","qufeng", "skills", "guard", "sendto"}));
}
int discmds()
{
    tell_object(this_player(),"�󵨣���������ǰҲ�Һ�������\n");
    return 1;
}
