//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5
inherit NPC;

void create()
{
        set_name("��������", ({ "zhenyu mingwang", "wang" }));
         set("title", HIY"��������" +NOR);
        set("age", 1000);
        set("attitude", "aggressive");
        set("str", 40);
        set("int", 35);
        set("con", 30);
        set("cor", 40);
        
        set("max_qi", 15000000);
        set("max_jing", 15000000);
        set("neili", 15000000);
        set("max_neili", 15000000);
		set("jingli", 15000000);
        set("max_jingli", 15000000);
        set("jiali", 6000);
        set("combat_exp", 2100000000);
		set("no_suck", 1);

        set_skill("force", 15000);
        set_skill("dodge", 15000);
        set_skill("parry",15000);
        set_skill("unarmed", 15000);
        set_skill("shushan-force", 15000);
        set_skill("zuixian-steps",15000);
        set_skill("fumozhang",15000);
        map_skill("dodge", "zuixian-steps");
        map_skill("force", "shushan-force");
        map_skill("unarmed", "fumozhang");
        set("chat_chance_combat", 50);

   add_temp("apply/damage", 20);
   add_temp("apply/armor", 20);

        setup();
       carry_object("/clone/cloth/cloth")->wear();

}

void die()
{
        if( environment() ) {
        message("sound", "\n����������������û�취��...��\n", environment());
        }
        destruct(this_object());
}
