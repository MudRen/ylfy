// kuangfeng.c 狂风


inherit NPC;

void create()
{
        set_name(HIG"狂风"NOR, ({ "kuang feng", "feng", "kuangfeng" }));        
        set("title", YEL"四大名捕之首"NOR"「"GRN"风"NOR"」");
        set("gender", "男性");
        set("age", 38);
        set("str", 3000);
        set("per", 30);
        set("dex", 30);
        set("long", "他，就是闻名天下的四大名捕的老大，面上木无表情，冷若冰霜，"+
        	"\n犹如一具行尸走肉，令人一望而生畏。\n");
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
        set("jiali", 200000); 
		
		set_temp("apply/attack", 1160);
        set_temp("apply/defense", 1160);
        set_temp("apply/armor", 1160);
        set_temp("apply/damage", 1160);
		
		set_skill("force", 51350);	
		set_skill("unarmed", 51350);	
		set_skill("qufeng", 51350);     	
		set_skill("qimen-wuxing", 21350);     	
		set_skill("yizhi-chan", 21350);	
		set_skill("sword", 51350);	
		set_skill("dodge", 51500);	
		set_skill("parry", 51350);	
		set_skill("hunyuan-yiqi", 21350);	
		set_skill("wuying-jian", 21350);	
		set_skill("shaolin-shenfa", 21500);	

        map_skill("force", "hunyuan-yiqi");
        map_skill("unarmed", "yizhi-chan");
        map_skill("sword", "wuying-jian");
        map_skill("parry", "wuying-jian");
        map_skill("dodge", "shaolin-shenfa");
        prepare_skill("unarmed","yizhi-chan");
		
        set("chat_chance_combat", 100);	
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.jingmo" :),
                (: perform_action, "sword.wuying" :),
        
                (: exert_function, "recover" :),
                (: exert_function, "heal" :),
            }) ); 
       
        set("chat_msg",({
     GRN"狂风"HIY"哼了一声，说道：“有四大名捕在，谁也不要杀人...谁要是杀了人给我找麻烦，就让他妈的去坐牢！”\n"NOR,
     GRN"狂风嘿嘿嘿地奸笑了几下，低声对你说：“杀人其实是很好玩的，当杀人狂更加刺激，\n"+
         "如果有一天我下岗了，一定会去当杀人狂，嘿~！嘿~！嘿~！”\n"NOR,
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
                    command("say "+ob->name()+"，你杀了人，还想往哪逃？！");
					this_object()->set_leader(ob);
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob);
                                        return ;
                }
                if (  !ob->query_temp("armor/cloth") && ob->query("race")=="人类" 
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
        message_vision("\n$N一把抓住$n，光天化日，当街裸跑，有伤风化！\n\n",this_object(),ob);
        message_vision("$N拎着$n向衙门走去！\n",this_object(),ob);
        ob->move(room);
    ob->set_temp("summon_time",time());
    message("vision",YEL+"\n\n当啷一声，一个赤条条的家伙被扔了进来。\n\n"+NOR,room,({ob}));
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
            command("say 想在大爷面前撒野？找死呀！");
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
                        message_vision(YEL "$N见势不好，转身要走，被$n"+YEL+"一把拦在面前。想走？没那么容易！\n"NOR, this_player(), this_object());
						this_player()->start_busy(1);
                        return 1;
                        }
        return 0;
}

