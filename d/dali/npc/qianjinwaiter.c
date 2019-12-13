// waiter.c

inherit NPC;
inherit F_DEALER;
#include <ansi.h>
void create()
{
        set_name("����", ({ "xuniang" }) );
        set("gender", "Ů��" );
        set("age", 54);
        set("title", HIG "������ϣ������̴�" NOR);
        set("long",
                "��λ������������ɫ���Ե��������㡣\n");
        set("combat_exp", 500000);
        set("attitude", "friendly");
        set("per",2);
        set("vendor_goods", ({
                __DIR__"obj/glxj",
                __DIR__"obj/cpdx",
                __DIR__"obj/pxhy",
                __DIR__"obj/kzmt",
                __DIR__"obj/hhdq",

        }) );
        set_skill("unarmed",50);
        set_skill("yueying-wubu",50);
        set_skill("dodge",50);
        set_skill("liuyang-zhang",50);
        map_skill("dodge","yueying-wubu");        
        map_skill("unarmed","liuyang-zhang");
        setup();
        carry_object(__DIR__"obj/wch_skirt")->wear();
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        if( this_player()->query_temp("dalikill") )
        {
                 kill_ob(this_player());
        }
        add_action("do_kill","kill");
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(4) ) {
                case 0:
message_vision("$N���$nһ�ۣ����˶��˰ɣ�������������\n",this_object(),ob);
                        break;
                case 1:
message_vision("$N΢�ڱ�ˮͰ��ϸһ�������¶����צ����֣���$n�����У��������˰ɡ�\n",this_object(),ob);
                        break;
                case 2:
message_vision("$N����$nһ�ۣ�����������Ц��������¶���ѵ��˴��Ļ�����\n",this_object(),ob);
                        break;
        }
}

int do_kill(string arg)
{
        this_player()->set_temp("dalikill", 1);
        return 0;
}
