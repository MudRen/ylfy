// Room: /d/cxwxm/fanting.c
// marry 8,14
inherit ROOM;

#include <ansi.h>

void create()
{
        set("short", HIC"����"NOR);
        set("long",
"����һ��ǳ���ķ��䣬������ڷ���ʮ���׺�ľ���Σ�һ��\n"
"�ִ��"+RED"����"NOR+"ֱͨ�ں����ķ�������������˿������ʦҪ( yao)��\n"
"�����ݳ�������\n\n"


);
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"dating",
]));

        setup();
}
void init()
{
        add_action("do_climb", "climb");
        add_action("do_yao", "yao");
}

int do_yao(string arg)
{
       object me;
       object food;
       me=this_player();
       if (arg)  return notify_fail("��������ֻ�г�����\n");
       if (food = present("fan", me)) return notify_fail("������˵... ...\n");
       message_vision("һ����ͷ����ĳ�ʦ������������Щ������Ȼ��ݸ���$N��\n",me);
        food=new(__DIR__"obj/fan");
        food->move(me);
       return 1; 
}
int do_climb(string arg)
{
    int n;
        object me = this_player();

    if( !arg || arg!="����" )
        {
        write("��Ҫ���Ķ���\n");
        return 1;
    }

    message_vision(
    "$N���˿��������ˣ����ߵ�������ǰ������ȫ���Ṧ��˳�������͵���������\n", this_player());

        if ((me->query("family/family_name") == "����������"))
        {
                me->move(__DIR__"longfeng");
                return 1;
        }

    n = (int)me->query("dodge");
    if (n >= 300)
        {
        message_vision(
                HIR "ֻ�����顱��һ����$N�����˵��ϣ�һ��������?...\n" NOR, this_player());
        set("exits/up", __DIR__"longfeng");
        remove_call_out("close");
        call_out("close", 5, this_object());
    }
    else
        {
                message_vision(
                HIR "ֻ�����顱��һ����$N�����˵��ϣ�һ��������?...\n" NOR, this_player());
                this_player()->set("qi",1);
                this_player()->unconcious();
    }

    return 1;
}
