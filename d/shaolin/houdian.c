// Room: /d/shaolin/houdian.c
// Date: YZC 96/01/19
inherit ROOM;


void create()
{
    set("short", "���");
    set("long", @LONG
����ģ�������߶���ˮĥʯ�ڣ��ο���ʮ���޺���Ф��
�����ˣ�������һ��ˮ����ˮ�澻���������������ᣬ��Ի����
��������������ˮ������������и��Ŷ���ͨ�����೤�������ȡ�
LONG
    );
    set("exits", ([
        "west" : __DIR__"zoulang2",
        "east" : __DIR__"zoulang3",
        "southdown" : __DIR__"guangchang4",
        "north" : __DIR__"wuchang",
    ]));
    set("valid_startroom",1);
    set("resource/water",1);
    set("objects",([
"kungfu/class/shaolin/hui-ru" : 1,	
"d/shaolin/npc/seng-bing3" : 2,	
    ]));
    setup();
}
void init()
{
    add_action("do_tiaoshui", "tiaoshui");
}
int do_tiaoshui(string arg)
{
    object me;
    
    me = this_player();
    if( present("yingxiong ling", me) )
    {
        this_player()->set_temp("shui",1);
        return notify_fail("��Ѵ�ˮͰ�ŵ����װ������һͰˮ���ܷ���������������\n");
    }
    else return notify_fail("����ʲô��ˮ��\n");
}
