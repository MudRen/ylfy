// Room: /d/shaolin/hanshui1.c
// bye mei
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "��Ժ");
        set("long", @LONG
�����ǿ�ջ�ĺ�Ժ��������������ר�Ÿ���ӭ��ס
��Ŀ��ˡ��Ա���һ�����ӣ�������
LONG);

        set("no_fight", 1);
        set("exits" , ([
             "east": __DIR__"kezhan",
           ]));

        set("item_desc", ([
                "sign": @TEXT
������Ϣ�У���Ҫ�ó��ģ��루������
TEXT
        ]) );

        setup();
}

void init()
{
    add_action("do_jiao", "jiao");
}

void check_trigger()
{
    object room;
    if(!query("exits/enter") ) {
        if( !(room = find_object(__DIR__"chexiang")) )
            room = load_object(__DIR__"chexiang.c");
        if( room = find_object(__DIR__"chexiang") ) {
            if((int)room->do_check() && !room->query("yell") ) {
                set("exits/enter", __DIR__"chexiang");
                room->set("exits/out", __FILE__);
                room->set("yell",1);
                message("vision", "�����������˿��˳���������˵�����ϳ��ɡ�\n", this_object() );
                message("vision", "����һ��̤�Ű���ϳ��ᣬ�γ�һ������"
                    "�Ľ��ݡ�\n", room);
                remove_call_out("on_board");
                call_out("on_board", 15);
            }
            else
                message("vision", "���Ѿ���ȥ��,���Ե�һ�ᡣ\n",this_object() );
        }
        else
            message("vision", "ERROR: boat not found\n", this_object() );
    }
    else 
        message("vision", "����˵�������������أ������ɡ�\n",
            this_object() );
}
void on_board()
{
    object room;
    message("vision", "���һ˦���ӣ���������������ת�ۼ��ܵ���Ӱ���١�\n",
        this_object() );
    delete("exits/enter");
    if( room = find_object(__DIR__"chexiang") )
    {
        room->delete("exits/out");
        room->delete("yell");
        message("vision", "����ѳ��Ź����ˣ�\n", room );
        if (!(int)room->do_check())
        {
        remove_call_out("arrive");
        call_out("arrive", 20);
        }
    }
}

void on_out()
{
    object room;
    message("vision", "һ�������㴫�˹�����ת�ۼ����Ѿ���������ǰ��\n",
        this_object() );
    if( room = find_object(__DIR__"chexiang") )
    {
        room->delete("yell");
        if (!(int)room->do_check())
        {
        remove_call_out("arrive");
        call_out("arrive", 20);
        }
    }
}

void arrive()
{
    object room;
    if( room = find_object(__DIR__"chexiang") )
    {
        room->set("exits/out", "/d/city/kedian");
        room->set("yell",1);
    message("vision", HIR "����˵������ɶ�Ӻȣ����ˡ�\n" NOR,room );
    remove_call_out("on_out");
    call_out("on_out", 10);
   }
}

int do_jiao(string arg)
{
        check_trigger();
        return 1;
}