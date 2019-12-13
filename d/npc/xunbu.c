// xunpu.c Ѳ��
inherit NPC;
void create()
{
        set_name("Ѳ��", ({ "xun bu", "bu", "xun" }));
        set("gender", "����");
        set("age", random(10) + 40);
        set("str", 25);
        set("dex", 16);
        set("long",       "���Ǹ�����ִ�й����Ѳ���������ɱ���ˣ���û��Ǳ�����ĺá�\n");
        set("combat_exp", 100000);
        set("shen_type", 1);
        set("attitude", "peaceful");
        set_skill("unarmed", 60);
        set_skill("force", 60);
        set_skill("sword", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 30);
        set("neili", 400); 
        set("max_neili", 400);
        set("jiali", 10);
        set("chat_chance", 30);
        set("chat_msg", ({
       "\nѲ���������ؿڣ�˵���������ڣ�˭��������ɱ�ˣ�˭ɱ���˾�Ҫ������\n",
       "\nѲ�������㼸�ۣ�˵�����ɱ�ɱ�˰�����������һ������Ź��㣡\n",
        "\nѲ��˵������ô����û��ɱ�ˣ����������ˣ�\n",
        (: random_move :)
        }) );
 
        setup();
        carry_object("/clone/weapon/gangjian")->wield();
        carry_object("/clone/cloth/xunbufu")->wear();
}
void init()
{
        object ob;
        ::init();
        if (!living(this_object())) return;
        if (interactive(ob = this_player())){
                        if ( (int)ob->query_condition("killer")) {
                    command("say "+ob->name()+"����ɱ���ˣ����������ӣ���");
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob);
                                        return ;
                }
                if (  !ob->query_temp("armor/cloth") && ob->query("race")=="����" 
                   && ((int)ob->query_temp("summon_time")+400)< time() ) {
                remove_call_out("summon_ob");
                call_out("summon_ob", 1, ob);
                                return;
        }
            add_action("do_kill","kill");
        }

}
void summon_ob(object ob)
{
    object room;
	
	if (!ob || environment(ob)!=environment())
		return;
	if(ob->query_temp("armor/cloth")) return;
	
	if (! room=find_object("/d/city/jianyu"))
		room=load_object("/d/city/jianyu");
	
	message_vision("\n$Nһ��ץס$n�����컯�գ��������ܣ����˷绯��\n\n",this_object(),ob);
	message_vision("$N����$n��������ȥ��\n",this_object(),ob);
	ob->move(room);
	ob->set_temp("summon_time",time());
	message("vision",YEL+"\n\n���һ����һ���������ļһﱻ���˽�����\n\n"+NOR,room,({ob}));
}

int do_kill(string arg)
{
        object ob;
      if (!environment()) return 0;
        if (ob=present(arg,environment()))
        if (userp(ob)){
            command("say ���ڴ�ү��ǰ��Ұ������ѽ��");
            kill_ob(this_player());
        }
    return 0;
}

