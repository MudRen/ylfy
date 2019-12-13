//bye enter

#include <room.h>
#include <ansi.h>

inherit ROOM;
int do_climb(string arg);

void create()
{
    set("short", "��լ����");
    set("long", @LONG
������ǳɶ����¼ҵĴ��ţ��ſ�������ʯʨ��������
�������Ž����ţ����ϵ�ͭ��ȴ���ô��ۡ�Χǽ�ܸߣ�������
д�������̽�Ĵ��֡��¸�������Ȼ���Ȳ������ŵ��Ա���һ
��������(tree),��վ������������졣
LONG
    );

    set("outdoors","chengdu");
    set("exits", ([
        "south" : "/d/city3/qingshixiang3",
    ]));

    set("item_desc", ([
        "tree" : "����һ���ϰ������������֦Ҷ��Ȼʮ��ïʢ��������������ȥ�ġ�\n"
    ]) );
    setup();
}

void init()
{
    object me;
    me = this_player();
    add_action("do_climb", "climb");
}

int do_climb(string arg)
{
    int n;
    n = this_player()->query_skill("dodge");
    if( !arg || arg!="tree" ) {
        write("��Ҫ����������\n");
        return 1;
    }


    message_vision(
    "$N�ڹ���ǰ��������˿������͵�Ծ��������\n", this_player());
        
    if (n>=80) {
        message_vision(
        "ֻ��$N�������֦��һ��,����Ծ����ǽ������ȻƮ��Ժ�С�\n", this_player());
        this_player()->move(__DIR__"yuanzi");
    }
    else if (n>=50) {
        message_vision(
        "ֻ��$N˫��������һ��,��ǿ����Χǽ,����Ժ��.\n", this_player());
        this_player()->move(__DIR__"yuanzi");
    }
    else {
        message_vision(
        "$N�߸�Ծ��,�ɻ���һ�����,�������Ṧ�����á�\n", this_player());
     }
    return 1;
}


