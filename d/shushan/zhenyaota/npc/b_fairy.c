//����ɽ���ɡ�dhxy-evil 2000.7.5
// modified by vikee
// lilong ���� 2002.01.12
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�׷���ͷ", ({ "baifa laotou","fairy","laotou" }));
        set("title", "����ܴ�����");
        set("age", 300);
        set("attitude", "peaceful");
        set("int", 100);
        set("per", 20);
        
        set("max_qi", 1000);
        set("max_jing", 1000);


        setup();
}

void init()
{
        add_action("do_answer", "answer");
}

int do_answer(string arg)
{
        object who = this_player();
        object me = this_object();
        object ob;
        if (!arg || (arg != "������" && arg != "������"))
                return notify_fail("��Ҫ�ش�ʲô��\n");

        message_vision(CYN"�׷�����˵�����ã�����������һ�ȥ���鿩�����һ�ÿʱÿ��������߰���$N�ģ���\n", this_player());
        command("haha"+ me->query("id"));
        command("great"+ me->query("id"));
        who->add_temp("shushan/answer_book_fairy",1);
        write(CYN"˵�գ��׷�������ʧ����Ӱ���٣�\n"NOR);
        message_vision("$N�������϶���һ���顣\n",this_player());
        ob = new("/d/shushan/zhenyaota/obj/fbook");
        ob->move(who);
        destruct(me);
        return 1;
}
