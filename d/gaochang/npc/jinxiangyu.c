inherit NPC;
inherit F_DEALER;
void create()
{
        set_name(MAG "������" NOR, ({ "jinxiang yu","jinxiang", "yu" }));
        set("title", "���ſ�ջ�ϰ���");
        set("shen_type", 0);
        set("gender", "Ů��");
    set("per",34);
        set("long",
                "�������ǻ�����ԭһ�������Ĵ����ˡ�һЩ��ٹ��ˣ��������ӳ���������ЪϢ��\n"
                "����������һ����һ��һ��������ָ�ơ�\n");
        set("combat_exp", 500);
        set("attitude", "friendly");
        set("inquiry", ([
                "����" : "���ô������\n",
        ]));
        
        set("vendor_goods", ({
             "/d/gaochang/npc/obj/hulu.c",
             "/d/xingxiu/obj/fire",
                __DIR__"obj/dogrou",
        }));
        setup();
        carry_object("//clone/cloth/pink_cloth")->wear();
}
void init()
{
        object ob;
        
        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
void greeting(object ob)
{
        if (!ob || environment(ob) != environment())
                return;
        switch(random(2)) {
        case 0 :
                say("������Ц���е�˵������λ" + RANK_D->query_respect(ob) +
                        "�������������ơ�\n");
                break;
        case 1 :
                say("������˵����Ӵ����λ" + RANK_D->query_respect(ob) + 
                        "�����˰��������иճ�Ҥ�ĺþơ�\n");
                break;
        }
}
