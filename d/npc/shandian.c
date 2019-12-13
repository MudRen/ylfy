// shandian.c ����
inherit NPC;

void create()
{
        set_name(HIW"����"NOR, ({ "shan dian", "shandian", "dian" }));        
        set("title", YEL"�Ĵ�����֮��"NOR"��"WHT"��"NOR"��");
        set("gender", "����");
        set("age", 25);
        set("str", 30);
        set("per", 30);
        set("dex", 30);
        set("long", "���������������µ��Ĵ������е�������Ϊ�˼�������Ը���ҡ�\n");
		set("combat_exp", 2100000000);  
        set("xyzx_sys/level", 3000000);			
        set("attitude", "peaceful");
		set("no_suck",1);
		set("end_boss", 1);
		set("max_jing", 35500000);  	
        set("max_qi", 35500000);  	
        set("neili", 113500000);          	
        set("shen_type", 0);
        set("max_neili", 24000000); 
        set("jiali", 275000); 
		
		set_temp("apply/attack", 1160);
        set_temp("apply/defense", 1160);
        set_temp("apply/armor", 1160);
        set_temp("apply/damage", 1160);
		
		set_skill("unarmed", 51340);	
		set_skill("force", 51340);	
		set_skill("sword", 51340);	
		set_skill("qimen-wuxing", 21350);     	
		set_skill("qufeng", 21350);     	
		set_skill("dodge", 51500);	
		set_skill("parry", 51340);	
		set_skill("taiji-shengong", 21340);	
		set_skill("taiji-jian", 21340);	
		set_skill("taiji-quan", 21340);	
		set_skill("shenxing-baibian", 21500);	

        map_skill("force", "taiji-shengong");
        map_skill("sword", "taiji-jian");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("dodge", "shenxing-baibian");
        prepare_skill("cuff","taiji-quan");
		
        set("chat_chance_combat", 100);	
        set("chat_msg_combat", ({
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.lian" :),
                (: exert_function, "recover" :),
                (: exert_function, "heal" :),
            }) ); 
       
        set("chat_chance",4);
        set("chat_msg",({
     WHT"����"HIY"����һ����˵���������Ĵ������ڣ�˭Ҳ��Ҫɱ��...˭Ҫ��ɱ���˸������鷳�����������ȥ���Σ���\n"NOR,
     WHT"���糤Хһ����ŭ������˵��������ƽ����ʹ�޵ľ�����Щ����ɱ��ȡ�ֵķ��ӣ�Ҫ�����������ˣ���~��ɱ���⣡������\n"NOR,
        (: random_move :)
        }));
        setup();
        carry_object("/clone/weapon/gangjian")->wield();
        carry_object("/clone/armor/tiejia")->wear();
}
void init()
{
        object ob;
        ::init();
        if (!living(this_object())) return;
		add_action("do_go","go");
        if (interactive(ob = this_player())){
                        if ( (int)ob->query_condition("killer")) {
                    command("say "+ob->name()+"����ɱ���ˣ����������ӣ���");
					this_object()->set_leader(ob);
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
        if (! room=find_object("/d/city/jianyu"))
            room=load_object("/d/city/jianyu");
        message_vision("\n$Nһ��ץס$n�����컯�գ��������ܣ����˷绯��\n\n",this_object(),ob);
        message_vision("$N����$n��������ȥ��\n",this_object(),ob);
        ob->move(room);
    ob->set_temp("summon_time",time());
    message("vision",YEL+"\n\n���һ����һ���������ļһﱻ���˽�����\n\n"+NOR,room,({ob}));
        if (! room=find_object("/d/city/yamen"))
            room=load_object("/d/city/yamen");
        //this_object()->move(room);
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

int do_go(string arg)
{
        mapping exit;
        if( !mapp(exit = environment()->query("exits")) || undefinedp(exit[arg]) )
                return 0;
        if (is_killing(this_player()))
                if (random(10)<=5) {
                        message_vision(YEL "$N���Ʋ��ã�ת��Ҫ�ߣ���$n"+YEL+"һ��������ǰ�����ߣ�û��ô���ף�\n"NOR, this_player(), this_object());
						this_player()->start_busy(1);
                        return 1;
                        }
        return 0;
}

