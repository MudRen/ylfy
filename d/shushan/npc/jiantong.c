//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5
//by yushu�޸�
inherit NPC;
void create()
{
        set_name("��ͯ", ({ "jian tong", "tong" }));
        set("title", "��ɽ����");
        set("gender", "����");
        set("age", 8 + random(10));
        set("attitude", "peaceful");
        set("str", 18);
        set("int", 25);
        set("con", 20);
        set("cor", 20);
        set("class","xiake");
        
        set("max_qi", 500);
        set("max_jing", 500);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 200);
        set("combat_exp", 10000);
        set("max_jingli", 100);
        set("max_neili", 100);
        set("jingli", 100);
        set("neili",100);
        set_skill("force", 30);
         set_skill("shushan-force", 30);
        set_skill("dodge", 30);
        set_skill("parry", 30);
        set_skill("sword", 30);
        set_skill("unarmed", 30);
          set_skill("fumozhang", 30);
          set_skill("yujianshu", 30);
       set_skill("zuixian-steps", 30);    
        map_skill("dodge", "zuixian-steps");
        map_skill("force", "shushan-force");
        map_skill("parry", "yujianshu");
        map_skill("sword", "yujianshu");
        map_skill("unarmed", "fumozhang");
        setup();
         carry_object("/clone/cloth/cloth")->wear();
      carry_object("/clone/weapon/changjian")->wield();
}
