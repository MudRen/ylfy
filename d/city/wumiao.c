// Room: /city/wumiao.c
#include <room.h>
inherit ROOM;
void create()
{
    set("short", "武庙");
    set("long", @LONG
这里是岳王庙的正殿，内有岳飞像，像上方悬挂岳飞手书“还我河山”的
横匾。殿两侧壁上嵌着“尽忠报国”四个大字。武人到此，都放下武器，毕恭
毕敬地上香礼拜。旁边似乎有一道侧门。
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
        __DIR__"obj/table" : 1,//后卫2003-7-13修改，由广场换到武庙来	
    ]));
    set("exits", ([
        "east" : __DIR__"beidajie2",
        "northwest": "/d/wizard/guest_room",
       "north":"/d/city/shijian",
    ]));
        create_door("northwest", "竹门", "southeast", DOOR_CLOSED);
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
    tell_object(this_player(),"大胆！在神像面前也敢胡来？！\n");
    return 1;
}
