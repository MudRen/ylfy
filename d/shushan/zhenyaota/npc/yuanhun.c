//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("ԩ��", ({ "yuan hun", "yuanhun" }));
        set("title", "��ɽǰ��");
        set("race","����");
        set("age", 99);
        set("attitude", "aggressive");
        set("str", 40);
        set("int", 25);
        set("con", 40);
        set("cor", 40);
        
        set("max_qi", 15000000);
        set("max_jing", 15000000);
        set("neili", 15000000);
        set("max_neili", 15000000);
        set("jiali", 6000);
        set("combat_exp", 2100000000);
         set("max_neili", 15000000);
         set("max_jingli", 15000000);
		 set("no_suck", 1);

        set_skill("force", 5000);
        set_skill("dodge", 5000);
        set_skill("parry",5000);
        set_skill("sword", 5000);
        set_skill("shushan-force", 5000);
        set_skill("zuixian-steps", 5000);
        set_skill("yujianshu",5000);
        map_skill("dodge", "zuixian-steps");
        map_skill("force", "shushan-force");
        map_skill("parry", "yujianshu");
        map_skill("sword", "yujianshu");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
        }) );
   add_temp("apply/damage", 20);
   add_temp("apply/armor", 20);

        setup();
        carry_object("/clone/cloth/cloth")->wear();
          carry_object("/clone/weapon/gangjian")->wield();

}

void die()
{
        object me = this_player();
        object ob = new("/d/shushan/zhenyaota/obj/qxsword");
        ob->move(environment(me));

        if( environment() ) {
        message("sound", CYN"\nԩ��ɢ��...", environment());
        message("sound", "\nһ������Ů��������������...", environment());
        message("sound", "\nŮ����������ʮ���ˣ��������ڿ��԰�Ϣ�ˣ�������ǽ����͸���������", environment());
        message("sound", "\nŮ��˵����ʧ��������...\n"NOR, environment());
        }
        destruct(this_object());
}
