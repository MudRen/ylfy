// mingjiaodizi.c 
#include <ansi.h>
inherit NPC;

void create()
{
       set_name("���̵���", ({ "mingjiao dizi", "dizi" }) );
       set("long","һ�����̵ĵ��ӣ�����б�峤��������Ӣ��֮����");
        set("gender", "����");
        set("age", 20);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 23);
        set("int", 22);
        set("con", 22);
        set("dex", 23);

        set("max_qi", 300);
        set("max_jing", 140);
        set("neili", 200);
        set("max_neili", 200);
        set("jiali", 10);
        set("combat_exp", 6000);
        set("shen",500);
        set("score", 100);

        set_skill("force", 30);
        set_skill("sword", 30);
        set_skill("dodge", 30);
        set_skill("unarmed", 30);
        set_skill("parry", 30);
        set_skill("sword", 30);
        
        
        create_family("����", 36, "����");

        setup();

        set("chat_chance", 1);
        set("chat_msg", ({
        "���̵���˵���������̵Ľ������޼��ǵ���������һ����������Ү\n",
        "���̵��Ӵ�е�������ҵ��к����ǽ�����ĸ����Щ����...�ٺ١�\n",
        "���̵��Ӷ������Ц�����������Ī�����\n",
         }));

       carry_object("/clone/weapon/changjian")->wield();
       carry_object("/clone/cloth/cloth")->wear();
}

