// This is a room made by roommaker.

inherit ROOM;

void create()
{
    set("short", MAG"԰��СԺ"NOR);
    set("long", ""MAG"���������ŷ����Լ��Ѿ�����õ����У�һ���ܱ���\n"
"��Сľ�ݳ����������ǰ��ľ�ݵ��Ա���һȦ��ʣ�����õ\n"
"�廨�����쳣�����������㲢û����ôע�⵽���Ĵ��ڡ���\n"
"������һ��С����"NOR"\n");
       set("resource/water", 1);
        set("exits", ([
                "east" : __DIR__"rose2",
                "west" : __DIR__"rose4",
            ]));
     set("no_fight",1);
    setup();
    replace_program(ROOM);
}

