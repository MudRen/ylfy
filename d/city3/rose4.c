// This is a room made by roommaker.

inherit ROOM;

void create()
{
    set("short", MAG"԰��С��"NOR);
    set("long", ""MAG"���ƿ��������˽�����һ�����µĻ���ζ�˱Ƕ�����ԭ\n"
                 "�����ӵĺ�����һ�ڳ�����������ĺɻ���ʢ�Ŷ�����С��\n"
                 "�а���һ�������ӱ�ɵ����ӣ������Ϸ���һ���ǳ����µ�\n"
                 "��ƿ�������ʮһ��"HIW"��õ��"MAG"��"NOR"\n");
    set("exits", ([
                "east" : __DIR__"rose3",
            ]));
       set("no_fight",1);
    setup();
    replace_program(ROOM);
}

