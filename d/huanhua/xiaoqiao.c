//bridge.c

inherit ROOM;

void create()
{
        set("short", "С��");
        set("long",
             "����һ��С���ţ�һ���峺��СϪ�����»���������\n"
            "��ʱ����Ƥ��С��Ծ��ˮ�棬�������»���һ������ɫ�Ļ��ߡ�\n"
        );
        set("outdoors", "huanhua");
        set("exits", ([
"northwest" : "/d/heimuya/changtan",	
                "east" : __DIR__"podi",
        ]));
        set("coor/x",30);
	set("coor/y",-110);
	set("coor/z",0);
	set("coor/x",30);
	set("coor/y",-110);
	set("coor/z",0);
	set("coor/x",30);
	set("coor/y",-110);
	set("coor/z",0);
	set("coor/x",30);
	set("coor/y",-110);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
