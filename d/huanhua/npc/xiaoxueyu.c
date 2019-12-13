// xiaoxueyu.c  ��ѩ��

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

//inherit F_DEALER;

void create()
{
        set_name("��ѩ��", ({ "xiao xueyu", "xueyu" }));
        set("nickname", HIG "��" NOR);
        set("long", 
                "��ѩ��������¥��СŮ��,ƽʱ�������Ǽ��������۰�,�Ǹ����������Ĺ��\n"
                "��ѩ�㸺�����,��������ȫ��佻����ɵ�Ů����.\n");
        
        set("gender", "Ů��");
        set("age", 21);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("dex", 28);

        set("max_qi", 50000);
        set("max_jing", 15000);    
        set("neili", 100000);
        set("max_neili", 2000);
        set("jiali", 500);
        set("combat_exp", 14000000);
        set("score", 30000);

        set_skill("force", 700);
        set_skill("unarmed",700);
        set_skill("dodge", 800);
        set_skill("parry",700);
        set_skill("sword", 700);
        set_skill("literate", 1200);
        set_skill("strike",700);
        set_skill("huanhua-jian",700);
        set_skill("tiexian-quan",700);
        set_skill("guiyuan-dafa",600);    
        set_skill("feihua-wuping",700);    
//      set_skill("feature",80);
        map_skill("force","guiyuan-dafa");
         map_skill("unarmed","tiexian-quan");
         map_skill("sword","huanhua-jian");
         map_skill("dodge","feihua-wuping");

        create_family("佻�����", 3, "Ů����");
        set("chat_chance_combat", 40);
        setup();

           carry_object("/clone/weapon/changjian")->wield();
          carry_object("/clone/cloth/cloth")->wear();

}

void attempt_apprentice(object ob)
{
   if ((string)ob->query("gender")=="Ů��")
   {
                message_vision("��ѩ������ͷ������, ˵�������ð�, �Ҿ��������ˡ���\n",ob);
                 command("recruit " + ob->query("id"));
                if((string)ob->query("class") != "swordsmanr")
                 ob->set("class", "swordsman");
       return;
}
   else
      {
                message_vision("��ѩ��Ц������˵�������ҿ������Ҵ����˰�?��\n",ob);
       return;}
}
