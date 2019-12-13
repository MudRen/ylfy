// ROOM heiwu.c

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "С����");
        set("long", @LONG
���ܺ������һƬ��������в���һ��������˼��������ʲô
��ط���ͻȻ��ǿ�ҵĸо��������С�����п϶�������ʲô����
�Ķ�������һ�ж�͸�ż�˿���죬���˶�������֮�ģ���ȥ��ϸѰ
��һ����
LONG
        ); 
        set("exits",  ([
               "out" : __DIR__"ymdrk12",
]));        set("no_clean_up", 0);
        setup();
}  
void init()
{
    add_action("do_search", "search");
    this_player()->receive_damage("qi", 500+random(500));
    this_player()->receive_wound("qi",  500+random(500));
message_vision(HIR"ͻȻһ���ޱ�ǿ���������$Nӭ�������$Nֻ������ǰ�����⵽��ǧ���ذ��Ĵ���
һ�㣬��ʱ������������ȫ����ͬɢ�˼ܣ�Ѹ�ٵĵ����˳�ȥ��\n"NOR, this_player());    }
int do_search(string arg)
{
        object ob;

        ob = this_player();
        if( ob->is_busy() )
                return notify_fail("��Ķ�����û����ɣ������ƶ���\n");
        message_vision("$N��ϸ����Ѱ�������ÿһ�����䡣\n", ob);
        ob->start_busy(2);
        call_out("search_obj", 4, ob);
        return 1;
} 
int search_obj(object me)
{
        int kar,per;
        int exp;
        object  book, box;

        if(!(this_object()->query("marks/none"))) {
                kar = (int)me->query("kar"); per = (int)me->query("per");                        exp = (int)me->query("combat_exp");
                if( kar > 60 ) kar = 60;
                if( (random(60 - kar) < 5) && (exp >= 100000) && ( kar >= 27 || per >= 36 ))  {
                       this_object()->set("marks/none", 1);
                        message_vision(HIW"$N�ҵ���һ�����ú�����С���䣬�Ž��˻��\n"NOR, me);
                        seteuid( geteuid(me));
                        book = new(__DIR__"npc/obj/danuoyi-xinfa1");
                        box = new(__DIR__"npc/obj/box");
                        book->move(box);
                        box->move(me);
                }
                else
                        message_vision("$Nʲô��û�ҵ���\n", me); 
                        me->add("jing", -15);        }
        else
                message_vision("$Nʲô��û�ҵ���\n", me);

        return 1;
} 
void reset()
{       ::reset();
        delete("marks/none");
}

