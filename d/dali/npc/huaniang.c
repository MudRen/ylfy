// huaniang.c ����

#include <ansi.h>
inherit NPC;
inherit F_DEALER;

void create()
{
        set_name(HIM"����"NOR, ({ "hua niang", "hua", "niang" }) );
        set("title", "Ʈ�㻨���ϰ�");
        set("gender", "Ů��");
        set("age",20);
        set("long",
                "��λ��������仨����ϰ壬������������������ˣ��ѹִ����С���Ӷ���Ȣ�����š� \n");
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_temp("apply/damage", 15);
        set("combat_exp", 40000);
        set("attitude", "friendly");
        set("vendor_goods", ({
                __DIR__"obj/chahua1", 
                __DIR__"obj/chahua2", 
                __DIR__"obj/chahua3", 
                __DIR__"obj/chahua4", 
                __DIR__"obj/chahua5", 
                __DIR__"obj/chahua6", 
                __DIR__"obj/chahua7", 
                __DIR__"obj/chahua8", 
                __DIR__"obj/chahua9",
                __DIR__"obj/chahua10", 
                __DIR__"obj/chahua11", 
                __DIR__"obj/chahua12", 
                __DIR__"obj/chahua13", 
        }));
        setup();
        carry_object("/clone/cloth/cloth")->wear();

}
void init()
{       
        object ob; 
        ob = this_player();

        ::init();
        if( interactive(ob) && !is_fighting() ) 
                    {
                        remove_call_out("greeting");
                        call_out("greeting", 1, ob);
                    } 
        if( this_player()->query_temp("dalikill") )
        {
                 kill_ob(ob);
        }

        add_action("do_buy", "buy");
        add_action("do_list", "list");
        add_action("do_kill","kill");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
 say( HIM"����"NOR"Ц�����˵������λ" + RANK_D->query_respect(ob)
 + "����֦�軨�͸���������˰ɡ�\n");
                        break;
                case 1:
say( HIM"����"NOR"�Ժ���˵����Բ�����������仨��Ĳ軨��������õ��ˡ�\n");
                        break;
        }
}

int do_kill(string arg)
{
        this_player()->set_temp("dalikill", 1);
        return 0;
}