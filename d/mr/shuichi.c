#include <ansi.h>
#include <room.h>
inherit ROOM;
int do_pai(string arg);
void create()
{
         set("short","ˮ��");
         set ("long",@long
����һ��ˮ�ء�һ��΢�紵����ˮ�к�Ҷ�����ˮ����Ư��, ˮ��(mian)
�̲�ӿ������ԡ�ˮ��������һ����ɽ�����е�ʯ���Ǻܶ�ģ�ʹ��
�̲�ס��̽��������
long);
         set("outdoors","mr");
         set("item_desc",([
             "mian" : "ˮ�淺����������˸�ŵ���������ֻ�������ںɻ��ϡ�\n"
]));
         set("exits", ([
             "west" : __DIR__"xiaojing7",
]));
         setup();
}

void init()
{
        add_action("do_jump", "jump");
//        add_action("do_pai","pai")
//        add_action("do_daji","daji")
        add_action("do_clean","clean");
}

int do_jump(string arg)
               {
                    object me;
               me = this_player();
                  if (arg !="chi")
              return notify_fail("��Ҫ����ȥ��\n");
          
             if (me->query_dex()<17) 
                    write("����ͼ����ˮ�أ��������������ݣ�ֻ�����ա�\n");
            else {
                    write("������������ˮ��,�䵽�˼�ɽ�ϡ�\n");
                    message("vision",
                             me->name() + "һ����Խ����ˮ�ء�\n",
                             environment(me), ({me}) );
              me->move(__DIR__"jiashan");
                    message("vision",
                             me->name() + "��ˮ�ر�Ծ��������\n",
                             environment(me), ({me}) );
                return 1;
           }
}
int do_pai(string arg)
{         object me;
        me = this_player();
 if ( !living(this_player()) || arg != "mian" )
                 return 0;                          
                 if (me->is_busy()) {
                write("��������æ���ء�\n");
                return 1;
        }

        if( me->is_fighting() ) {
                write("���޷���ս�����ڳ�������\n");
                return 1;
        }
        if ((int)me->query_skill("strike", 1) >100 ) {
                write("����ˮ���Ѿ��޷������Ļ����Ʒ��ˣ�\n");
                return 0;
        }
        if ( (int)me->query("jing")<30) {
                           me->receive_damage("jing", 10);
                 write("��̫���ˣ��Ѿ�û������������ˮ���ˣ�\n");              
        return 1;
}
me->receive_damage("jing", 15+random(10));
        write("�㲻ʱ�ػ�����ˮ�棬�������������������������Ļ����Ʒ�������ߡ�\n");
        message_vision("$N���ڲ�ʱ�ػ�����ˮ�棬��������������\n", me);  
                    me->improve_skill("strike", me->query("int"));
         return 1;
}                                     

int do_clean(string arg)
{
    object me = this_player();
    object ob;                             
    if (! (ob = present("paper", me)) || userp(ob))
    return notify_fail("��Ҫ��ʲô��\n");
    if (arg != "paper" && arg != "ֽ��") 
    return notify_fail("��Ҫ��ʲô��\n");
    write("�㲻����İ�ֽ����ˮ���С�\n",me);
    write("ֽ�����ɾ��ˣ��Գ���һ����С�֡�\n", me);
    destruct(ob);
ob = new(__DIR__"npc/obj/paper1.c");
    ob->move(me);
    return 1;
}
