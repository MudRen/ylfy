inherit NPC;
#include <ansi.h>
void create()
{
        set_name(HIC"�ܹܼ�"NOR, ({ "zong guanjia", "guanjia", "jia"}));
        set("gender", "����");
        set("age", 50);  
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
        set("combat_exp", 70000);
        set("shen_type", 0);
        set("attitude", "peaceful");
        set("max_qi",1000);
        set("max_jing",1000);
        set("neili",1000);
        set("max_neili",1000);
        set("jiali",30);
        set("score", 8000);

        set_skill("cuff", 90);
        set_skill("parry",90);
        set_skill("ding-dodge",95);
        set_skill("dodge", 90);
        set_skill("force",90);
        set_skill("ding-force",90);

        map_skill("force","ding-force");
        map_skill("dodge","ding-dodge");

        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);

        setup();
        carry_object("d/mr/obj/cloth2")->wear();
}
