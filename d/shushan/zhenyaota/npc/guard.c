//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5
// lilong alter 2002.01.19
inherit NPC;

void create()
{
        set_name("��ɽ��ͯ", ({ "jian tong", "tong" }));
        set("title", "��ɽ����");
        set("gender", "����");
        set("age", 8 + random(10));
        set("attitude", "peaceful");
        set("str", 18);
        set("int", 25);
        set("con", 20);
        set("cor", 20);
        set("class","swordsman");
        
        set("max_qi", 3000000);
        set("max_jing", 3000000);
        set("neili", 3000000);
        set("max_neili", 3000000);
		set("no_suck", 1);
        set("jiali", 3000);
        set("combat_exp", 2100000000);
            set("max_jingli", 3000);
          set("jingli", 3000);

        set_skill("force", 1000);
        set_skill("shushan-force",1000);
        set_skill("dodge",1000);
        set_skill("parry", 1000);
        set_skill("sword",1000);
        set_skill("unarmed",1000);
        set_skill("fumozhang",1000);
        set_skill("yujianshu",1000);
        set_skill("zuixian-steps",1000);    

        map_skill("dodge", "zuixian-steps");
        map_skill("force", "shushan-force");
        map_skill("parry", "yujianshu");
        map_skill("sword", "yujianshu");
        map_skill("unarmed", "fumozhang");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
        }) );
   add_temp("apply/damage", 15);
   add_temp("apply/armor", 15);
        setup();
          carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
}

