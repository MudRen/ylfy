// masteryue.c
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("岳不群", ({ "yue buqun", "master", "yue" }) );
        set("title", "华山派现任掌门");
        set("nickname", "君子剑");        
        set("gender", "男性");
        set("age", 40);
        set("long",
 "他就是华山派的现任掌门人，江湖上人称“君子剑”的岳不群。他看上去\n"
 "是个和善的中年人，对人总是彬彬有礼，很有一代宗师的风范。\n" );
        set("inquiry", ([
                "紫霞秘籍": "对不起，你来晚了，紫霞秘籍并不在我这里。\n",
        "辟邪剑谱": "你问辟邪剑谱,那是歪门邪道的武功，问来干什么。\n",
                "手令": "手令，你想进我的书房偷东西吗，抓贼啊。"
]) );        
        set("attitude", "peaceful");
    set("str", 40);
    set("neili",5000000);
    set("max_qi",902000);
	set("max_jing",902000);
    set("int", 65);
    set("con", 60);
    set("per", 28);
    set("dex", 130);
    set("max_neili", 400000);
    set("jiali", 18200);
    set("rank_info/respect", "岳掌门");        
    set("combat_exp",1562500);
	set("xyzx_sys/level", 1500);
    set("shen",15000);
    set_skill("force", 2250);
    set_skill("dodge", 2250);
    set_skill("parry", 2250);
    set_skill("sword", 2250);
    set_skill("blade", 2250);
    set_skill("zixia-shengong", 1250);
    set_skill("huashan-jianfa", 1250);
    set_skill("huashan-zhangfa", 1250);
    set_skill("huashan-shenfa", 1250);
    set_skill("hunyuan-zhang", 1250);
    set_skill("pixie-jian", 1250);
    set_skill("poyu-quan", 1250);
    set_skill("fanliangyi-dao", 1250);
    set_skill("literate", 2250);
    set_skill("unarmed", 2250);
    
    map_skill("dodge", "pixie-jian");
    map_skill("force", "zixia-shengong");
    map_skill("parry", "pixie-jian");
    map_skill("sword", "pixie-jian");
    map_skill("unarmed", "hunyuan-zhang");
    map_skill("blade", "fanliangyi-dao");
    create_family("华山派", 13, "掌门人");
    setup();
    carry_object("//clone/cloth/long_cloth")->wear();
    carry_object("/clone/weapon/changjian")->wield();
}
void attempt_apprentice(object ob)
{
        if( (string)ob->query("gender") == "女性" )
                command("say 我不收女弟子的，姑娘还是另访名师吧。");
        else {
                command("nod");
                command("say " + RANK_D->query_respect(ob) + "日后必成大器 ！\n");                
				command("recruit " + ob->query("id") );
             }
}
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "swordsman");
}
