// This is a room made by roommaker.

inherit ROOM;

void create()
{
    set("short", HIY"԰��С·"NOR);
    set("long", ""HIW"��˳��С·���������ţ�����õ��԰��Ļ����ŵ��쳣\n"
"���ޣ�������һ���Ŀ������ĸо�������̰����������˼�\n"
"���������µĿ�����"NOR"\n");
        set("exits", ([
                "east" : __DIR__"rose1",
                "west" : __DIR__"rose3",
            ]));
     set("no_fight",1);
    setup();
    replace_program(ROOM);
}
