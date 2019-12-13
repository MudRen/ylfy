// baguating.c ����ͤ

#include <room.h>

inherit ROOM;
void close_mark();

void create()
{
        set("short", "����ͤ");
        set("long", @LONG
�����ǰ���ͤ��ͤ���ķ��Σ�ͤ���Բ�Σ�������Բ�ط���ͤΪ˫ͤ
�����̽ǣ�ͤ�����л�ɫ�����ߣ�ͤ���ɰ˸��Կ�������ʯ��֧�š�����
һ�����ϵ�һ������ȭӡ(mark)���ȱ�ݡ�
LONG
        );
       
        set("exits", ([
                "southeast" : __DIR__"yunjiyuan",
        ]));

        set("item_desc", ([
                "mark" :"���ƺ����Խ���������ӡ���루�������裩��\n" ,
        ]));

        setup();
}

void init()
{
         add_action("do_touch", "touch");
}


void close_mark()
{
        object room;

        if(!( room = find_object(__DIR__"zhujianshi")) )
                room = load_object(__DIR__"zhujianshi");
        if(objectp(room))
        {
                delete("exits/down");
                message("vision","ֻ��-��-��-��-��-�ؼ���������Ѿ���ʧ��һ�ж��ָ���ԭ����\n",this_object());
                message("vision","���Ժ�������һ����ͷ����Ӵ���ֽ���ȥ�ˣ�\n" ,
                         this_object());
                
        }
}

int do_touch(string arg)
{       
        object me = this_player();
        object room;
//        object ob;

        if (query("exits/down"))
                return notify_fail("�����Ѿ��ǿ����ˡ�\n");
        if (!arg || arg != "mark" )
                return notify_fail("��Ҫ��ʲô��\n");
        if ((int)me->query("neili") < 500 ) 
              return notify_fail("�������������\n");
        if(!( room = find_object(__DIR__"zhujianshi")) )
                room = load_object(__DIR__"zhujianshi");
        if (objectp(room))
        {

                set("exits/down", __DIR__"zhujianshi");
                message_vision("ֻ����--��--��--����--�ؼ���������ͤ������������\n"+
                        "�ƶ����������ǰ¶����һ��������\n", this_player());
                remove_call_out("close_mark");
                call_out("close_mark", 10);
        }

        return 1;
}


