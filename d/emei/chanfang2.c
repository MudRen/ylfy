//  /d/emei/chanfang1.c ����

inherit ROOM;

void create()
{
        set("short","����");
	set("long", @LONG
����һ�����ɮ�ڲβ�����ϰ�ĵط������ڰ���ܼ򵥣�����
һ�Ų輸��һ��ľ���Ϸ���һ�����š�
LONG
	);
        set("set_jingzuo",1);
	set("exits", ([ 
                "east": __DIR__"chunyangd",
		]));

	set("objects", ([ 
              "/d/emei/npc/limingxia": 1,
	]));

	setup();

}
