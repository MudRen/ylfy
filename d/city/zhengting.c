// Room: /city/zhengting.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
	�����Ǹ����ھֵ���������ֻ̫ʦ��һ���ſ�����������������ͷ���ֳ�
�̴������ڱ�Ŀ��˼��ǽ�Ϲ��ż����ֻ���һ�ѱ�����
LONG
	);
set("no_fight", 1);	
	set("exits", ([
		"north" : __DIR__"biaoju",
	]));
	set("objects", ([
		__DIR__"npc/linzhennan" : 1,
	]));
	setup();
}
void reset()
{
    foreach (object ob in all_inventory(this_object()) ){
       if (userp(ob)) return ;
    }
    ::reset();
}
