//ROOM: xiaohuayuan.c
inherit ROOM;
void create()
{
	set("short", "С��԰");
        set("long",
	     "�ӻ谵�ĵص��г���, �㷢���Լ�����������һ�������µ�С��\n"
	     "԰��, ��÷����, ���ɴ��, ���õ��ľ߽���, ����ȥ��һ�侫��\n"
              "С��.\n"
            );
        set("exits", ([
                "west" : __DIR__"neishi",
                "east" :__DIR__"xiaoshe",   
           ]));
        setup();
        replace_program(ROOM);
}
