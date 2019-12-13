// sample master.c code
// xiake island master.c
inherit NPC;
inherit F_MASTER;
void consider();
void create()
{
    set_name("龙亦凡", ({"island master", "long", "master"}));
    set("nickname", "不败神龙");
    set("gender", "男性");
    set("age", 80);
    set("long", 
        "这难道就是传说中的侠客岛岛主龙亦凡吗？\n他看上去跟一般的中年人无异，可是他已有百岁高龄。\n");
    set("attitude", "peaceful");
    
    set("str", 100);
    set("int", 100);
    set("con", 100);
    set("dex", 100);
    set("neili", 600000);
    set("max_neili", 100000);
    set("jiali", 500);
    
    set("combat_exp", 10000000);
    
    set_skill("force", 1000);
//  set_skill("xiake-force", 1000);
    set_skill("unarmed", 1000);
//  set_skill("xiake-strike", 1000);
    set_skill("dodge", 1000);
//  set_skill("xiake-steps", 1000);
//  set_skill("move", 1000);
    set_skill("literate", 1000);
    
//  map_skill("force", "xiake-force");
//  map_skill("unarmed", "xiake-strike");
//  map_skill("dodge", "xiake-steps");
//  map_skill("move", "xiake-steps");
    
    setup();
}
    
