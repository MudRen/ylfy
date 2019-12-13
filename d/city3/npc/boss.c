//boss.c


inherit NPC;
//inherit F_VENDOR;
inherit F_DEALER;

void create()
{
        set_name("����ϰ�", ({ "lao ban", "lao", "ban" }));
        set("nickname", "Ц����");
        set("shen_type", 1);

        set("str", 30);
        set("gender", "����");
        set("age", 36);
        set("long",
                "���������Ц�ݣ�������ͷȴ���ѵúܡ�\n"+
                "��Ϊ��ݵ��ϰ壬�����һ��û�¸ɵ����ļһ����һ��\n"+
                "��Ϣ������ͨ��\n");
        set("combat_exp", 5000);
        set("attitude", "friendly");
        set("inquiry", ([
                "�¼�" : "�¼��ǳɶ��Ĵ󻧣�����ȴ�����Ǩ���ģ�\n"+
                         "��˵�Ǽ������ڽ����д����������Ϊ�˱ܳ𵽳ɶ��ġ�\n",
        ]));
        
        set("vendor_goods", ({
                "/clone/food/peanut",
                "/clone/food/tofu",
                __DIR__"obj/longhucui",
        }));

        setup();
        carry_object("/clone/cloth/cloth")->wear();
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
                say("����ϰ�Ц���е�˵������λ" + RANK_D->query_respect(ob) +
                        "����������ȱ��Ȳ衣\n");
                break;
        case 1 :
                say("����ϰ�˵����Ӵ����λ" + RANK_D->query_respect(ob) + 
                        "�����˰��������и�ը�õ����㻨�����ۡ�\n");
                break;
        }
}

