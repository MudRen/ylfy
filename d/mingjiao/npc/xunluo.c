// Npc: xunluo.c

#include <ansi.h>

inherit NPC;

void create()
{
       set_name(CYN"明教巡逻"NOR, ({
               "mingjiao xunluo",
               "xunluo",
       }));
       set("long",
               "他是一位肌肉发达，膀阔腰圆的明教教众，太阳穴高高鼓起。\n"
               "他手持鬼头刀，身穿一袭明教教服，似乎武艺超群。\n"
       );


       set("gender", "男性");
       set("attitude", "peaceful");
       set("class", "jiaozhong");

       set("age", 35);
       set("shen_type", 1);
       set("str", 30);
       set("int", 20);
       set("con", 25);
       set("cps", 25);
       set("max_qi", 500);
       set("max_jing", 300);
       set("neili", 1000);
       set("max_neili", 1000);
       set("jiali", 50);
       set("combat_exp", 200000);
       set("score", 1);

       set_skill("force", 100);
       set_skill("dodge", 80);
       set_skill("unarmed", 80);
       set_skill("parry", 80);
       set_skill("blade", 100);

       setup();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/gangdao")->wield();
       set("chat_chance", 30);
       set("chat_msg", ({
HIM"明教巡逻道：我已经跟过三代教主了，张教主是对我们最好的！这年头，\n这样的好人不多了！\n"NOR,
HIM"明教巡逻道：不是我吹牛，武林中很少有人在俺这把刀下过个三五回合！！\n"NOR,
HIM"明教巡逻道：咱明教张教主是有名的义薄云天，武功盖世的性情中人！\n也是武林中响当当的美男子！\n"NOR,
HIM"明教巡逻骂道：这几天夜探明教总坛的人很多，害得老子不能睡觉，半夜里还要巡逻！\n"NOR,
                (: random_move :)
        }) );
}

void init()
{
        object me, ob;
        mapping fam;

        ::init();

        ob = this_player();
        me = this_object();
        
        if (interactive(ob) 
        && !environment(ob)->query("no_fight")
        && !present("mingjiao lingpai", ob) 
        && ( (fam = ob->query("family")) && fam["family_name"] != "明教" ) )
        {
                if( !ob->query_temp("warned") ) {
                        command("say 喂，站住？！");
                        command("say 半夜三更来明教干嘛，下次看到决不轻饶！");
                        ob->set_temp("warned", 1);
                }
                else if( ob->query_temp("stay") < 10 ) ob->add_temp("stay", 1);
                else {
                        command("say 大胆狂徒，竟敢闯到明教里来撒野！！！\n");
                        me->set_leader(ob);
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob); 
                }
        }
        if( environment(me)->query("no_out") )
            message_vision("$N吐了一口痰说道：算你这个兔崽子跑得快。\n", this_object());
      me->set_leader(0);
        return 0;
}
