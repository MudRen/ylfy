//����ɽ�ɡ�mhxy-yushu 2001/2
// lilong alter 2002.01.19
inherit F_DEALER;
inherit NPC;
void create()
{ 
        set("shen_type", 1);
        set_name("������", ({"zhang qiaoshou", "laoban","boss"}));
        set("age", 42);
        set("gender", "����");
        set("long","�����̵��ϰ壬Ц���еĿ����㡣\n");
	 set("title", "�������ϰ�");
        set("attitude", "friendly");
        set_temp("apply/damage", 10);
        set("combat_exp", 100000);
          set("max_neili", 200);
	 set("neili", 200);
        set_skill("unarmed", 30);
        set_skill("dodge", 40);
        set_skill("parry", 30);
 set("vendor_goods", ({
  "/d/shushan/obj/qingyichan",
  "/d/shushan/obj/shenzhen",
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
                say("������Ц���е�˵������λ" + RANK_D->query_respect(ob) +
                        "�����������Ķ��������ʵ��\n");
                break;
        case 1 :
                say("������˵����Ӵ����λ" + RANK_D->query_respect(ob) + 
                        "�����˰�������Ķ����Ų���Ƿ��\n");
                break;
        }
}

