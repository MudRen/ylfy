//����ɽ�ɡ�mhxy-yushu 2001/2
inherit F_DEALER;
inherit NPC;
void create()
{
  set_name("���ϰ�", ({"ma laoban", "laoban","boss"}));
  set("gender", "����");
  set("title", "�Ƶ��ϰ�");
set("long", "���ϰ�����еļҵ����������ڿ�����ҾƵꡣ\n");
  set("combat_exp", 10000);
  set("age", 50);
  set("per", 34);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 50);
           set_temp("apply/damage", 4);
        set("vendor_goods", ({
            "/clone/food/tofu",
            "/d/shushan/obj/chahu",
            "/clone/food/hdjiudai",
            "/clone/food/kaoya",
        }));
  setup();
  carry_object("/clone/cloth/cloth")->wear();
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
                say("���ϰ�Ц���е�˵������λ" + RANK_D->query_respect(ob) +
                        "��������ķ��˰������⡣\n");
                break;
        case 1 :
                say("���ϰ�˵����Ӵ����λ" + RANK_D->query_respect(ob) + 
                        "�����˰���ϣ�����ϳԺã��Ⱥã���ӭ�´�������\n");
                break;
        }
}

