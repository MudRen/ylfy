#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
         set("short","����");
         set("long", @LONG
������Ľ�ݼ�����������ĵط�������Ľ�ݵ�����ò�Ҫ������������
�������аڷ���һ���㰸������ڷ���һ����λ����(paizi)��������ǽ
�Ϲ���һ�����񳯷�ͼ����ǽ�Ϲ���һ�ڱ����������������һ���᷿��
���������á�
LONG
    );
         set("item_desc",([
             "paizi" : "Ľ������������λ\n",  
             "sword" : "����һ�������ı�����͸�ű���ɫ��\n",
             "baojian" : "����һ�������ı�����͸�ű���ɫ��\n",
]));
         set("exits",([
             "east" : __DIR__"xiangfang2",
             "west" : __DIR__"xiangfang3",                    
             "south" : __DIR__"neitang",
             "north" : __DIR__"dating",
]));
         set("count",1);
         setup();
//         replace_program(ROOM);
}
             
void init()
{
        add_action("do_ketou", "ketou");
        add_action("do_ketou", "�ݼ�");
}             

int do_ketou()
{
        object me = this_player();
        object ob = this_object();
        if ( !present("yu xi",me) ) return 0;
        if ( me->query_temp("Ľ��/ketou") == 2 ) {
                if ( ob->query("count") > 0 ) {
                        new(__DIR__"npc/obj/biyujian")->move(ob);
                        message("vision","ֻ��������һ�������������һ��" +
                                "���������ı�����\n",me);
                        destruct(present("yu xi",me));
                        me->delete_temp("Ľ��/ketou");
                        ob->add("count", -1);
                        return 1;
                }
                else {
                        message("vision","�㲻�������������ƺ��ѱ��򿪹���\n",
                                me);
                        me->delete_temp("Ľ��/ketou");
                        return 1;
                }
        }
        else {
                me->add_temp("Ľ��/ketou", 1);
                message_vision("$N����������������ǰ���˸���ͷ��\n", me);
                return 1;
        }
}       
