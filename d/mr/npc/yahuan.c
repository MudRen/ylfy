inherit NPC;
void create()
{
        set_name("Ѿ��", ({ "ya huan", "yahuan" }));
        set("gender", "Ů��");
        set("age", 18);
        set("str", 25);
        set("int", 26);
        set("con", 26);
        set("dex", 26);
        set("combat_exp", 5000);
        set("shen_type", 0);
        set("attitude", "peaceful");
        set("max_qi",500);
        set("max_jing",250);
        set("neili",250);
        set("max_neili",100);
        set("jiali",0);
        set("score", 4000);

        set_skill("cuff", 35);
        set_skill("parry",35);
        set_skill("ding-dodge",35);
        set_skill("dodge", 35);
        set_skill("force",35);
        set_skill("ding-force",35);

        map_skill("force","ding-force");
        map_skill("dodge","ding-dodge");

        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);

        setup();
        carry_object("d/mr/obj/skirt1")->wear();
        carry_object("d/mr/obj/shoe")->wear();
        carry_object("d/mr/obj/green_silk")->wear();
}
