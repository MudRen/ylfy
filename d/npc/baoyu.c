// baoyu.c ����
inherit NPC;

void create()
{
        set_name( HIB"����"NOR, ({ "bao yu", "baoyu", "yu" }));        
        set("title", YEL"�Ĵ�����֮��"NOR"��"BLU"��"NOR"��");
        set("gender", "����");
		set("long", "���������������µ��Ĵ��������϶�����Ȼ�书������������͵ģ����Ǵ������أ���ϸ�緢������һ�㶼������������ѷɫ��\n");
        set("age", 32);
        set("str", 30);
        set("per", 30);
        set("dex", 30);
		set("xyzx_sys/level", 3000000);
		set("end_boss", 1);
		set("max_jing", 35500000);  	
        set("max_qi", 35500000);  	
        set("neili", 113500000);          	
        set("shen_type", 0);
        set("max_neili", 24000000); 
        set("jiali", 275000); 
        
        set("combat_exp", 2100000000);   	
        set("attitude", "peaceful");
        set_temp("apply/attack", 1350);
        set_temp("apply/defense", 1350);
        set_temp("apply/armor", 1350);
        set_temp("apply/damage", 1350);
		
		set_skill("unarmed", 51300);	
		set_skill("qufeng", 51300);     	
		set_skill("qimen-wuxing", 21300);     	
		set_skill("force", 51300);	
		set_skill("sword", 51300);	
		set_skill("strike", 51300);	
		set_skill("dodge", 51500);	
		set_skill("parry", 51300);	
		set_skill("zixia-shengong", 21300);	
		set_skill("dugu-jiujian", 21300);	
		set_skill("poyu-quan", 21300);	
		set_skill("hunyuan-zhang", 21300);	
		set_skill("qiankundanuoyi", 21500); 

        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "poyu-quan");
        map_skill("strike", "hunyuan-zhang");
        map_skill("sword", "dugu-jiujian");
        map_skill("parry", "qiankundanuoyi");
        map_skill("dodge", "qiankundanuoyi");
        prepare_skill("strike", "hunyuan-zhang");
        prepare_skill("unarmed", "poyu-quan");
		
       set("chat_chance_combat", 100);	
        set("chat_msg_combat", ({
                (: perform_action, "sword.pojian" :),
                (: perform_action, "sword.podao" :),
                (: perform_action, "sword.poqi" :),
                (: perform_action, "sword.poanqi" :),
                (: perform_action, "sword.pobian" :),
                (: perform_action, "sword.pozhang" :),
                (: perform_action, "unarmed.leidong" :),
                (: perform_action, "strike.wuji" :),
                (: exert_function, "recover" :),
                (: exert_function, "heal" :),
            }) ); 
       
        set("chat_chance",4);
        set("chat_msg",({
     BLU"����"HIY"����һ����˵���������Ĵ������ڣ�˭Ҳ��Ҫɱ��...˭Ҫ��ɱ���˸������鷳�����������ȥ���Σ���\n"NOR,
     BLU"����¶���Ի�ı��飬��˼�����ҡҡͷ˵�����ף����ǰ�����ô��ôˮ��������׾ͱ�PK�ˣ�
         �ֲ���Ҫ���������Ĵ�����������\n"NOR,
        (: random_move :)
        }));
        setup();
        carry_object("/clone/weapon/gangjian")->wield();
        carry_object("/clone/armor/tiejia")->wear()
;
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
        this_object()->move(room);
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

