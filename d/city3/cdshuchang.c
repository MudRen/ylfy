// Room: /chengdu/cdshuchang.c
// oooc: 1998/06/20 

inherit ROOM;

void create()
{
        set("short", "�鳡");
	set("long", @LONG
������ȫ���������鳡��ÿ����������������ﲻ����������
����Ҫ֪������˵ɶ���ȿ�������ǽ�ϵĺ�����������Ҫ��Щ��ɽ
������������ȡ�Ҳ�в�����������Կ�������ȤҲ����һ����
LONG
	);

	set("exits", ([
                "east" : __DIR__"nanjie2",
                "west" : __DIR__"shuoshuyuan",
	]));

	setup();
	replace_program(ROOM);
}

