inherit NPC;
void create()
{
   set_name("��ǰ����",({"shi wei"}));
   set("age","����");
   set("age",20+random(30));
   set("combat_exp",1400000);
    set("max_neili",8500);
    set("neili",8500);
    set("qi",8500);
    set("eff_qi",8500);
    set("max_qi",8500);

    set("jing",8500);
    set("eff_jing",8500);
    set("max_jing",8500);
        set_skill("force", 180+random(180));

        set_skill("unarmed", 180+random(180));
        set_skill("blade", 180+random(180));
        set_skill("parry", 180+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("kuangfeng-blade", 180+random(180));
        map_skill("blade", "kuangfeng-blade");
        map_skill("parry", "kuangfeng-blade");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),
                (: random_move :),
        }) );
   set("force",500);
   set("home",1);
   set("max_force",500);
   set("force_factor",20);
   set("chat_chance",5);
   set("chat_msg",({
   (:random_move:),
   }));
   setup();
  carry_object("/clone/weapon/gangdao")->wield();
  carry_object("clone/armor/tiejia")->wear();
  carry_object("clone/armor/toukui")->wear();
}
#include "shiwei.h"