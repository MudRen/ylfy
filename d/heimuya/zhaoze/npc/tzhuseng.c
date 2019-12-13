//tzhuseng.c
inherit NPC;
void create()
{
    set_name("天竺僧", ({"tzhu seng"}));
    set("gender", "男性");
    set("age", 62);
    set("per", 23);
    set("long", 
        "他肌肤黝黑，高鼻深目，显是天竺国人。\n");
    set("attitude", "peaceful");
    
    set("str", 51);
    set("int", 40);
    set("con", 36);
    set("dex", 60);
    set("chat_chance", 5);

    set("qi", 200);
    set("max_qi", 200);
    set("jing", 500);
    set("max_jing", 300);
     
    setup();
    carry_object("/d/shaolin/obj/cheng-cloth.c")->wear();  
}

void die()
{
        object killer;
        if( objectp(killer = query_temp("last_damage_from")) )
                 killer->add_temp("kill_shi",1);
           ::die();
}

