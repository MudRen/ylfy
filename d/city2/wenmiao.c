
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
����������������п׷����������ʵ۶������������˼��������
�Լ��Ľ�ɽ��𢣬�����ʵ���ȻҲ�����⡣���ۺ��˵��ˣ����Ϲ��Ͼ�����
����ݡ�
LONG
	);
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("objects", ([
		"/d/city/obj/box" : 1,
		"/d/taishan/npc/shu-sheng" : 1,
        "/d/city2/npc/lwshizhe" : 1,    
		"d/npc/wenqianer" :1,
		__DIR__"npc/newbie" :1,
	]));
	set("exits", ([
		"west" : __DIR__"xisi",
	]));
	setup();
        call_other("/clone/board/yijian_b", "???");
	//replace_program(ROOM);
}

void init()
{
	if ( !wizardp(this_player()) )
		add_action("discmds",({"sha","drop","attack","duanlian","ansuan","touxi","persuade","teach","exert",
			"exercise","study","learn","sleep","kill","steal","cast","conjure","expell","fight","hit","perform",
			"prcatice","scribe","surrender","qufeng", "skills", "guard", "sendto"}));
}

int discmds()
{
    tell_object(this_player(),"�󵨣���������ǰҲ�Һ�������\n");
    return 1;
}