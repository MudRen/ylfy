// nvdizi.c 
// marry 8.13

inherit NPC;
#include <ansi.h>

void create()
{
        set_name("Ů����", ({ "nv dizi", "di" }));
        set("long", 
                "һ���˼��˰�����Ů\n");
        set("gender", "Ů��");
        set("jihao",1);
        set("age", 18);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
        
        set("max_qi", 5000);
        set("max_jing", 200);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 0);
        set("combat_exp", 100000);

        set_skill("force", 300);
        set_skill("dodge", 300);
        set_skill("whip", 350);
        set_skill("parry", 300);
        set_skill("unarmed", 300);
        set_skill("wangran-xinfa",300);
        set_skill("cxwx-quan", 300);
        set_skill("shuiyue", 300);
        set_skill("chixin-bianfa", 300);
        create_family("����������", 3,"����");
        map_skill("force", "wangran-xinfa");
        map_skill("whip", "chixin-bianfa");
        map_skill("parry", "chixin-bianfa");
        map_skill("dodge", "shuiyue");
        map_skill("unarmed", "cxwx-quan");
        setup();
        carry_object("/d/cxwxm/obj/cloth")->wear();
        carry_object("/d/cxwxm/obj/whip")->wield();
      
      
}
