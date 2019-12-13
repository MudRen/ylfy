//bye enter

#include <room.h>
#include <ansi.h>

inherit ROOM;
int do_jump(string arg);

void create()
{
    set("short", "Сͤ");
    set("long", @LONG
����վ�ں��ߵ�һ��Сͤ�ͨ��һ�������ػص����ȿ���
�ص�������Сͤ�������൱���£�������������ͺ��еĺɻ���
����ͤ�ӱ���������ż���ľ׮�������и�С�������ʼ俴��
ȴ�ǲ�̫���С�
LONG
    );

    set("exits", ([
        "south" : __DIR__"zoulang4",
    ]));

    set("item_desc", ([
        "ľ׮" : "���Ǽ����ֲ��ù��������ľ׮������ȥ���Ǻܽ�ʵ��"
    ]) );
    setup();
}

void init()
{
    object me;
    me = this_player();
    add_action("do_jump", "jump");
}



int do_jump(string arg)
{
    int n;
    n = this_player()->query_skill("dodge");
    if( !arg || arg!="ľ׮" ) {
        write("��Ҫ�����������Ƕ��죬�ɲ�������Ӿ�ļ���Ŷ��\n");
        return 1;
    }


    message_vision(
    "$N��������˿������͵�Ծ��������\n", this_player());
        
    if (n>=100) {
        message_vision(
        "ֻ��$N����һԾ�����ȵ�վ�ں��е�ľ׮�ϣ��������䣬�Ѿ������˺���С����\n", this_player());
        this_player()->move(__DIR__"xiaodao");
    }
    else {
        message_vision(
        "$N�߸�Ծ��,���ص�����ľ׮�ϣ������ľ׮�ȶ��ˣ�����ͨ��һ������ˮ�С�\n", this_player());
        this_player()->move(__DIR__"huli");
     }
    return 1;
}


