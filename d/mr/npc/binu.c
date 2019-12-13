inherit NPC;
void create()
{
        set_name("�Ů", ({ "bi nu", "bu" }));
        set("gender", "Ů��");
        set("age", 24);
        set("str", 18);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("combat_exp", 10000);
        set("shen_type", 0);
        set("attitude", "peaceful");
        set("max_qi",600);
        set("max_jing",600);
        set("neili",450);
        set("max_neili",450);
        set("jiali",0);
        set("score", 5500);

        set_skill("cuff", 35);
        set_skill("parry",35);
        set_skill("ding-force",35);
        set_skill("dodge", 35);
        set_skill("force",35);
        set_skill("ding-dodge",35);

        map_skill("force","ding-force");
        map_skill("dodge","ding-dodge");

        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);

        setup();
        carry_object("d/mr/obj/skirt")->wear();
        carry_object("d/mr/obj/shoe")->wear();
        carry_object("d/mr/obj/red_silk")->wear();
}