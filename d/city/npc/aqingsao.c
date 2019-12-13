// aqingsao.c ����ɩ
inherit NPC;
//inherit F_VENDOR;
inherit F_DEALER;
void create()
{
        set_name("����ɩ", ({ "aqing sao", "aqing", "sao" }));
        set("title", "����ϰ���");
        set("nickname", "����һ֧��");
        set("shen_type", 1);
        set("str", 30);
        set("gender", "Ů��");
        set("age", 25);
        set("long",
                "����ɩ�����ݳ��������Ĵ����ˣ���Ϊү������ϲ����������䣬\n"
                "�������Գ����һ��һ��������ִ�ơ�\n");
        set("combat_exp", 500);
        set("attitude", "friendly");
        set("inquiry", ([
                "����" : "���ǼҰ���ȥ����������ȥ��Ү��\n",
                "����" : "���ô������\n",
        ]));
        
        set("vendor_goods", ({
                "d/city/obj/peanut",
                "clone/food/tofu",
                "d/city/obj/chahu",
				"d/city/obj/pigu",
				"d/city/obj/cuijin",
				"d/city/obj/jiangong",
				"d/city/obj/zhengshen",
				"d/city/obj/xieshen",				
        }));
        setup();
        carry_object("/clone/cloth/hiw_cloth")->wear();
}
void init()
{
        object ob,owner;
        string nature;
        nature=NATURE_D->room_event_fun();
        owner=this_object();
        ::init();
        if (base_name(environment())!=query("startroom")) return;
        if (interactive(ob = this_player()) && !is_fighting()) {
        	if(nature!="event_dawn"
		&& nature!="event_night"
		&& nature!="event_midnight"){
                remove_call_out("greeting");
                call_out("greeting", 1, ob);}
                else owner->command("zzz "+owner->query("id"));
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
                say("����ɩЦ���е�˵������λ" + RANK_D->query_respect(ob) +
                        "����������ȱ��Ȳ衣\n");
                break;
        case 1 :
                say("����ɩ˵����Ӵ����λ" + RANK_D->query_respect(ob) + 
                        "�����˰��������и�ը�õ����㻨�����ۡ�\n");
                break;
        }
}

