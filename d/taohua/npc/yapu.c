inherit NPC;
void create()
{
        set_name("����", ({"yapu"}));
        set("gender", "����");
        set("age", 56);
        set("long", 
        "����λ�������ƣ�������˪֮ɫ�������ˡ�\n");
//        set("attitude", "peaceful");
        set("str", 28);
        set("int", 17);
        set("con", 25);
        set("dex", 21);
        set("max_qi", 3000);
        set("max_qi", 3000);
        set("neili", 6000);
        set("max_neili", 600);
        set("jiali", 80);
        set("combat_exp", 2000000);
        set_skill("force", 300); 
        set_skill("huntian-qigong", 300); 
        set_skill("unarmed",300); 
        set_skill("xianglong-zhang", 300); 
        set_skill("dodge", 350); 
        set_skill("xiaoyaoyou", 350); 
        set_skill("parry", 350);
        set_skill("begging", 300); 
        set_skill("stealing", 300); 
        
        map_skill("force", "huntian-qigong");
        map_skill("unarmed", "xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "xianglong-zhang");

        setup();
        carry_object("/clone/cloth/cloth")->wear();
       if (random(10)>3)
       carry_object("/d/taohua/obj/xiang");

}
