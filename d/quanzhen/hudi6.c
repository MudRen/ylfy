//tan7.c

inherit ROOM;

void create()
{
	set("short", "�����Ϻ� ");
	set("long",
"������С���ף����ܺں����ģ�ͷ���Ͽ�����һ�����⣬��ߵ�ˮ��	
		���Ϻ��µ�ӿ���š���������һ�����ۡ������ƺ���һ�����⣬Ҳ��֪��
                        Щʲô����ΧһƬ���ţ��ƺ������Ų��ɱ����\n"

	);
	set("exits", ([
		"up" : __DIR__"",	
		"east" : __DIR__"",
		"west" : __DIR__"",
		"south" : __DIR__"",
		"north" : __DIR__"",
	]));
//        set("objects" , ([
//               __DIR__"npc/fish" : 3,
//	       __DIR__"item/zhenzhu" :1,	
//             ]) );
	setup();
	replace_program(ROOM);
}
