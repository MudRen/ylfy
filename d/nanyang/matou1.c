// Room: /d/shaolin/matou1.c
// Date: Hop 97.06.13
inherit ROOM;
void create()
{
    set("short", "����ͷ");
    set("long", @LONG
�����Ǻ�ˮ�ϰ���һ������ͷ���׳ơ�С�������һ���ļ�
�����������˵������ַǷ������治Զ���ǻ�ɽ���¡������Ϸ�
������������ԼԼ�ؿ������ݳǵ�Ӱ�ӡ���������֡�
LONG
    );
    set("exits", ([
        "west" : __DIR__"hanshui1",
    ]));
    set("objects", ([
        "/d/city/npc/chuanfu1" : 1,
    ]));
    set("outdoors", "shaolin");
    setup();
    replace_program(ROOM);
}
