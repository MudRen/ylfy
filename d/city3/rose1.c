// This is a room made by roommaker.

inherit ROOM;

void create()
{
    set("short", HIY"õ��԰"NOR);
    set("long", ""HIY"һ�󵭵���õ��������������������һ�����ۡ�����\n"
      "�ֵ�ȫ��õ�廨�������滹��һ�����˲ȳ�����С·����ֻ\n"
    "�����Ļ������ڻ�����������衣"NOR"\n");
        set("exits", ([
                "west" : __DIR__"rose2",
            ]));
     set("no_fight",1);
    setup();
    replace_program(ROOM);
}
