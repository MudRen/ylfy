inherit NPC;
 
void create()
{
        set_name("�Ů", ({ "binu", }) );
        set("gender", "Ů��" );
        set("age",18);
        set("class", "taohua");
        set("combat_exp", 100);
        set_skill("unarmed", 5);
        set_skill("dodge", 10);
        set_skill("force",50);
        set("force", 50);
        set("max_force", 50);
        setup();
        carry_object("/d/taohua/obj/baichou")->wear();
}
