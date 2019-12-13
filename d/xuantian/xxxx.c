//li.c
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;
void greeting(object);
void init();
void create()
{
    set_name("独孤求败", ({ "chen"}) );
    set("gender", "男性" );
    set("age", 65);
    set("long", "无名家老仆人。\n");
    set("attitude", "friendly");
    set("max_qi", 600);
    set("qi",600);
    set("max_jing", 500);
    set("jing",500);
    set("neili", 1000);
    set("max_neili", 1000);
    set("jiali",30);
    set("combat_exp", 20);
    set("score", 20);
    create_family(HBBLU"无剑山庄"NOR,-3001,"开山祖师");
    setup();
    carry_object("/clone/cloth/cloth")->wear();
}
void attempt_apprentice(object ob)
{
     command("say 好吧，我收下你。\n");
     command("recruit "+ob->query("id"));
     if((int)ob->query("combat_exp")<10000)
       command("say 你先到东边练功室找陪练童子比划几招吧。\n");
     return;
}

